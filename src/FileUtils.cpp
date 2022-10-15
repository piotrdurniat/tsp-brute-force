#include "FileUtils.hpp"
#include <iostream>
#include <fstream>

GraphMatrix *FileUtils::loadGraph(std::string filePath)
{
    std::ifstream fin(filePath);

    if (!fin)
    {
        return NULL;
    }

    std::string name;
    fin >> name;

    int verticesNum;
    fin >> verticesNum;

    GraphMatrix *graph = new GraphMatrix(verticesNum);
    for (int i = 0; i < verticesNum; i++)
    {
        for (int j = 0; j < verticesNum; j++)
        {
            int weight;
            fin >> weight;
            graph->addEdge(i, j, weight);
        }
    }

    int optimum;
    fin >> optimum;
    graph->setOptimum(optimum);

    fin.close();
    return graph;
}
