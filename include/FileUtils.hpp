#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include "GraphMatrix.hpp"

class FileUtils
{
public:
    /**
     * @brief Loads graph from a file
     *
     * @param fileName Name of the file
     * @return Pointer to the newly created graph
     */
    static GraphMatrix *loadGraph(std::string fileName);
};

#endif
