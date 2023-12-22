#ifndef _RMAZE_HPP
#define _RMAZE_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

class Maze
{
private:
    /* data */
    int *m_mat; // maze matrix
public:
    Maze(/* args */);
    Maze(const char *);
    ~Maze(); // destructor
};

#endif