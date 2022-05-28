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
    data[0][0] = data[rows - 1][cols - 1] = '.';
}

Map::Map(unsigned lvl) : level(1), rows(fib(lvl, 10, 15)), cols(fib(lvl, 10, 10)),
                         data(new char *[rows]), dragonCount(fib(lvl, 2, 3)), dragons(new Dragon *[dragonCount])
{
    srand(time(0));
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
        } while (data[posY][posX] != '.' || !posY && !posX || !isReachable(posY, posX));
        dragons[i] = new Dragon(posY, posX); // improve
        data[posY][posX] = (char)MAP_SYMBOLS::MONSTER;
    }
}

void Map::print() const
{
    for (unsigned i = 0; i < rows; ++i)
    {
        for (unsigned j = 0; j < cols; ++j)
            std::clog << (i == pl->getY() && j == pl->getX() ? char(177) : ' ') << data[i][j];
        std::clog << '\n';
    }
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
    for (unsigned i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;
}

void Map::run()
{
    do
    {
        if (pl->move())
            print();
    } while (1);
}
