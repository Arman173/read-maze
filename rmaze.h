#ifndef _RMAZE_HPP
#define _RMAZE_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

struct vector_m
{
    unsigned int x;
    unsigned int y;

public:
    vector_m();
    vector_m(unsigned int, unsigned int);
    friend std::ostream &operator<<(std::ostream &, const vector_m);
};

class Maze
{
private:
    /* data */
    unsigned int ROWS;
    unsigned int COLUMNS;
    char *m_mat; // maze matrix
    vector_m _start;
    vector_m _end;

public:
    Maze(/* args */);
    Maze(const char *);
    ~Maze(); // destructor
    /*operators*/
    char &operator()(unsigned int, unsigned int);
    /*getters*/
    unsigned int rows();
    unsigned int columns();
    vector_m beg();
    vector_m end();
};

#endif