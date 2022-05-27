#ifndef __MAZE_HPP
#define __MAZE_HPP
#include <iostream>
#include <ctime>
#include <stack> // fix

class Maze
{
    unsigned rows, cols;
    unsigned level;
    char **data;

    void generateMaze() const;

    size_t fib(unsigned lvl, unsigned val1, unsigned val2) const;

public:
    bool isReachable(unsigned y, unsigned x) const;
    Maze(unsigned lvl = 1);
    Maze(const Maze &other) = delete;
    Maze &operator=(const Maze &other) = delete;
    ~Maze();
    void print() const;
};

#endif