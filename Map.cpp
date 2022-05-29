#include "Map.hpp"

size_t Map::fib(unsigned n, unsigned val1, unsigned val2) const
{
    if (!n)
        throw 1;
    if (n == 1)
        return val1;
    if (n == 2)
        return val2;
    return fib(n - 1, val1, val2) + fib(n - 2, val1, val2);
}

void Map::generateMap() const
{
    for (unsigned i = 0; i < rows; ++i)
        for (unsigned j = 0; j < cols; ++j)
            data[i][j] = (rand() % 4 < 3 ? (char)MAP_SYMBOLS::FREE : (char)MAP_SYMBOLS::WALL);
    data[0][0] = data[rows - 1][cols - 1] = (char)MAP_SYMBOLS::FREE;
}

Map::Map(const MultipleImagePrinter &print, unsigned lvl)
    : running(false),
      p(print), level(1), rows(fib(lvl, 10, 15)), cols(fib(lvl, 10, 10)),
      data(new char *[rows]), dragonCount(fib(lvl, 2, 3)), treasureCount(fib(lvl, 2, 2)),
      events(dragonCount + treasureCount)
{
    srand(time(0));
    pl = new Player(0, 0); // todo passed as parameter
    for (unsigned i = 0; i < rows; ++i)
        data[i] = new char[cols];

    do
    {
        generateMap();
    } while (!isReachable(rows - 1, cols - 1));
    unsigned posY, posX;
    for (unsigned i = 0; i < dragonCount; ++i)
    {
        do
        {
            posY = rand() % cols;
            posX = rand() % rows;
        } while (data[posY][posX] != (char)MAP_SYMBOLS::FREE || !posY && !posX || !isReachable(posY, posX));
        events.push_back(new Dragon(posY, posX, rand() % lvl + 1)); // improve
        data[posY][posX] = events[events.size() - 1]->getChar();
    }
    unsigned eqNumber; // fix
    for (unsigned i = 0; i < treasureCount; ++i)
    {
        do
        {
            posY = rand() % cols;
            posX = rand() % rows;
        } while (data[posY][posX] != (char)MAP_SYMBOLS::FREE || !posY && !posX || !isReachable(posY, posX));

        events.push_back(Inventar::getEquipment(rand() % 3, posY, posX));
        data[posY][posX] = events[events.size() - 1]->getChar();
    }
}

EventGenerator *Map::print() const
{
    // fix USE PRINTER
    system("cls");
    bool plHere = false;
    for (unsigned i = 0; i < rows; ++i)
    {
        for (unsigned j = 0; j < cols; ++j)
        {
            plHere = (i == pl->getY() && j == pl->getX());
            std::clog << (plHere
                              ? pl->getChar()
                              : (data[i][j] == (char)MAP_SYMBOLS::WALL
                                     ? data[i][j]
                                     : '_'))

                      << (data[i][j] == (char)MAP_SYMBOLS::FREE && plHere
                              ? pl->getChar()
                              : data[i][j]);
        }
        std::clog << '\n';
    }
    unsigned i = 0;
    while (i < events.size() && !events[i]->locatedAt(pl->getY(), pl->getX()))
        ++i;
    if (i < events.size() && events[i]->isOnBoard())
        return events[i];
    return nullptr;
}

bool Map::isReachable(unsigned posY, unsigned posX) const
{
    struct position
    {
        unsigned y, x;
        position(unsigned row = 0, unsigned col = 0) : y(row), x(col) {}
        bool operator==(const position &other) const { return x == other.x && y == other.y; }
    };
    bool **visited = new bool *[rows];
    for (unsigned i = 0; i < rows; ++i)
    {
        visited[i] = new bool[cols];
        for (unsigned j = 0; j < cols; ++j)
            visited[i][j] = data[i][j] == (char)MAP_SYMBOLS::WALL;
    }

    Stack<position> memory;
    position current(0, 0), desired(posY, posX);
    memory.push(current);
    while (!memory.empty() && !visited[posY][posX])
    {

        current = memory.top();
        visited[current.y][current.x] = true;
        memory.pop();
        if (current.y + 1 < rows && !visited[current.y + 1][current.x])
        {
            visited[current.y + 1][current.x] = true;
            memory.push(position(current.y + 1, current.x));
        }
        if (current.y < rows && current.x - 1 < cols && !visited[current.y][current.x - 1])
        {
            visited[current.y][current.x - 1] = true;
            memory.push(position(current.y, current.x - 1));
        }
        if (current.y - 1 < rows && current.x < cols && !visited[current.y - 1][current.x])
        {
            visited[current.y - 1][current.x] = true;
            memory.push(position(current.y - 1, current.x));
        }
        if (current.y < rows && current.x + 1 < cols && !visited[current.y][current.x + 1])
        {
            visited[current.y][current.x + 1] = true;
            memory.push(position(current.y, current.x + 1));
        }
    }

    bool res = visited[posY][posX];

    for (unsigned i = 0; i < rows; ++i)
        delete[] visited[i];
    delete[] visited;

    return res;
}

Map::~Map()
{
    EventGenerator *tmp;
    while (!events.empty())
    {
        tmp = events.pop_back();
        delete tmp;
    }
    for (unsigned i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;
    delete pl; // fix
}

void Map::run()
{
    running = true;
    EventGenerator *event = print();
    do
    {
        if (pl->move(running, [&](unsigned y, unsigned x) -> bool
                     { return y < rows && x < cols && data[y][x] != (char)MAP_SYMBOLS::WALL; }))
            if (event = print())
            {
                event->print(p);
                if (!event->action(pl))
                    print();
            }
    } while (running);
}

Map::Map(const MultipleImagePrinter &pr,
         const String &path)
    : p(pr), data(nullptr), pl(nullptr),
      running(false), level(0), rows(0), cols(0), dragonCount(0),
      treasureCount(0)
{
    // todo read map from text file
    std::ifstream ifs(path.c_str(), std::ios::in);
    if (!ifs.is_open())
    {
        std::cerr << "No such map found!\n";
        return;
    }
    pl = new Player(0, 0);
    ifs >> level >> rows >> cols;

    unsigned buf, y, x;
    dragonCount = (fib(level, Constants::MONSTER_COUNT_1, Constants::MONSTER_COUNT_2));
    treasureCount = (fib(level, Constants::TREASURE_COUNT_1, Constants::TREASURE_COUNT_2));
    for (unsigned i = 0; i < dragonCount; ++i)
    {
        ifs >> buf >> y >> x;
        events.push_back(new Dragon(y, x, buf));
    }
    for (unsigned i = 0; i < treasureCount; ++i)
    {
        ifs >> buf >> y >> x;
        events.push_back(Inventar::getEquipment(buf, y, x));
    }
    ifs.get();

    data = new char *[rows];
    for (unsigned i = 0; i < rows; ++i)
    {
        data[i] = new char[cols];
        for (unsigned j = 0; j < cols; ++j)
        {
            ifs.get(data[i][j]);
        }

        // optimize better with getline?
    }

    ifs.close();
}
