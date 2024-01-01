#include "rmaze.h"

vector_m::vector_m()
{
    this->x = 0;
    this->y = 0;
}

vector_m::vector_m(unsigned int x, unsigned int y)
{
    this->x = x;
    this->y = y;
}

std::ostream &operator<<(std::ostream &os, const vector_m vector)
{
    os << "x: " << vector.x << ", y: " << vector.y;
    return os;
}

Maze::Maze(/* args */)
{
    this->m_mat = NULL;
    this->ROWS = 0;
    this->COLUMNS = 0;
}

Maze::~Maze()
{
    std::cout << std::endl
              << "deleting: " << this->ROWS * this->COLUMNS;
    std::cout << " elements..." << std::endl;
    delete[] this->m_mat;
}

Maze::Maze(const char *filename)
{
    this->m_mat = NULL;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Error al leer el archivo..." << std::endl;
        exit(EXIT_FAILURE);
    }
    // contamos cuantas columnas hay
    char c;
    // int columns = 0;
    while (file.get(c))
        if (c == '\n')
            break;
    this->COLUMNS = (int)file.tellg() - 1;
    // volvemos al inicio del archivo
    file.seekg(0, file.end);
    int lenght = file.tellg();
    file.seekg(0, file.beg);
    // contamos las filas
    this->ROWS = 0;
    while (file.tellg() < lenght)
    {
        file.seekg(this->COLUMNS + 1, file.cur);
        this->ROWS++;
        // std::cout << file.tellg() << std::endl;
    }
    // reservamos memoria...
    this->m_mat = new char[this->ROWS * this->COLUMNS];
    std::cout << std::endl
              << "maze size: " << sizeof(char) * ROWS * COLUMNS << std::endl;
    // volvemos al inicio del archivo
    file.seekg(0, file.beg);
    // guardamos el laberinto en nuestro arreglo
    unsigned int i = 0;
    while (file.get(c) && i < this->ROWS * this->COLUMNS)
    {
        // std::cout << c;
        if (c == '\n')
        {
            std::cout << std::endl;
            continue;
        }
        std::cout << c;
        this->m_mat[i] = (c == '*') ? 1 : 0;
        if (c == 'I')
        {
            _start = vector_m(i / this->COLUMNS, i % this->COLUMNS);
            // std::cout << std::endl
            //           << _start << std::endl;
        }
        if (c == 'F')
        {
            _end = vector_m(i / this->COLUMNS, i % this->COLUMNS);
            // std::cout << std::endl
            //           << _end << std::endl;
        }
        i++;
    }
    std::cout << std::endl;
    // for (int i = 0; i < this->ROWS * this->COLUMNS; i++)
    //     std::cout << this->m_mat[i];
    // std::cout << std::endl;
    // cerramos el archivo
    file.close();
}

char &Maze::operator()(unsigned int r, unsigned int c)
{
    if ((r < 0 || c < 0) || (r >= this->ROWS || c >= this->COLUMNS))
    {
        exit(EXIT_FAILURE);
    }
    return this->m_mat[r * this->COLUMNS + c];
}

unsigned int Maze::rows()
{
    return this->ROWS;
}
unsigned int Maze::columns()
{
    return this->COLUMNS;
}

vector_m Maze::beg()
{
    return this->_start;
}
vector_m Maze::end()
{
    return this->_end;
}