#include "Maze.hpp"

size_t Maze::fib(unsigned n, unsigned val1, unsigned val2) const
{
    if (!n)
        throw 1;
    if (n == 1)
        return val1;
    if (n == 2)
        return val2;
    return fib(n - 1, val1, val2) + fib(n - 2, val1, val2);
}

void Maze::generateMaze() const
{
    for (unsigned i = 0; i < rows; ++i)
        for (unsigned j = 0; j < cols; ++j)
            data[i][j] = (rand() % 4 < 3 ? '.' : '#');
    data[0][0] = data[rows - 1][cols - 1] = '.';
}

Maze::Maze(unsigned lvl) : level(1), rows(fib(lvl, 10, 15)), cols(fib(lvl, 10, 10)),
                           // FIX
                           data(new char *[rows])
{
    srand(time(0));
    for (unsigned i = 0; i < rows; ++i)
    {
        data[i] = new char[cols + 1];
        data[i][cols] = '\0';
    }

    do
    {
        generateMaze();
    } while (!isReachable(rows - 1, cols - 1));
}

void Maze::print() const
{
    for (unsigned i = 0; i < rows; ++i)
        std::clog << data[i] << '\n';
}

bool Maze::isReachable(unsigned posY, unsigned posX) const
{
    struct position
    {
        unsigned y, x;
        position(unsigned row, unsigned col) : y(row), x(col) {}
        bool operator==(const position &other) const { return x == other.x && y == other.y; }
    };
    bool **visited = new bool *[rows];
    for (unsigned i = 0; i < rows; ++i)
    {
        visited[i] = new bool[cols];
        for (unsigned j = 0; j < cols; ++j)
            visited[i][j] = data[i][j] == '#';
    }

    // improve use my Stack
    std::stack<position> memory;
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

Maze::~Maze()
{
    for (unsigned i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;
}
