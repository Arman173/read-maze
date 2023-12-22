#include "rmaze.h"

Maze::Maze(/* args */)
{
    this->m_mat = NULL;
}

Maze::~Maze()
{
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
    int columns = 0;
    while (file.get(c))
        if (c == '\n')
            break;
    columns = (int)file.tellg() - 1;
    std::cout << std::endl
              << "gcount: " << file.gcount() << std::endl;
    std::cout << std::endl
              << "columns: " << columns << std::endl;
    std::cout << std::endl
              << "tellg: " << file.tellg() << std::endl;
    file.seekg(0, file.end);
    int lenght = file.tellg();
    file.seekg(0, file.beg);
    int rows = 0;
    while (file.tellg() < lenght)
    {
        file.seekg(columns + 1, file.cur);
        rows++;
        std::cout << file.tellg() << std::endl;
    }
    std::cout << std::endl
              << "rows: " << rows << std::endl;
    // cerramos el archivo
    file.close();
}