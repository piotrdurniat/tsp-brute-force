#include "bruteForceSearch.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

#define VERBOSE false

Path bruteForceSearch(GraphMatrix *graph, int startingVertex)
{
    const int graphSize = graph->getVertexCount();
    const int optimum = graph->getOptimum();
    std::vector<int> shortestPath;

    // Utworzenie tablicy path składającej się z pozostałych wierzchołków grafu
    // w kolejności naturalnej.
    std::vector<int> path;
    for (int i = 0; i < graphSize; ++i)
    {
        if (i != startingVertex)
        {
            path.push_back(i);
        }
    }

    const int pathSize = path.size();
    // Przypisanie weight := waga cyklu wychodzącego z wierzchołka początkowego
    // i przechodzącego przez wierzchołki tablicy path
    const int weight = getPathWeight(graph, path, pathSize, startingVertex);
    // Przypisanie minWeight = wieght
    int minWeight = weight;
    if (VERBOSE)
    {
        printImprovement(weight, optimum);
    }

    // Wygenerowanie kolejnej permutacji tablicy path.
    // Jeżeli nie ma kolejnej permutacji, wyjście z pętli - koniec
    while (std::next_permutation(path.begin(), path.end()))
    {
        // Przypisanie weight := waga cyklu wychodzącego z wierzchołka początkowego
        // i przechodzącego przez wierzchołki tablicy path
        const int weight = getPathWeight(graph, path, pathSize, startingVertex);
        if (weight < minWeight)
        {
            // Przypisanie minWeight := weight
            minWeight = weight;
            shortestPath = path;
            if (VERBOSE)
            {
                printImprovement(weight, optimum);
            }
        }
    }

    if (VERBOSE)
    {
        printImprovement(weight, optimum);
        printPath(startingVertex, &shortestPath);
    }

    // Do tablicy dodany jest wierzchołek początkowy, aby zwrócić całą ścieżkę
    shortestPath.push_back(startingVertex);
    return Path(shortestPath, minWeight);
}

void printImprovement(int weight, int optimum)
{
    const float prd = (100.0 * (weight - optimum)) / optimum;
    printf("%4i %.2f%%\n", weight, prd);
}

void printPath(int startingVertex, std::vector<int> *path)
{
    printf("%i -> ", startingVertex);
    for (int vertex : *path)
    {
        printf("%i -> ", vertex);
    }
    printf("%i \n", startingVertex);
}

int getPathWeight(GraphMatrix *graph, std::vector<int> &path, int pathSize, int startingVertex)
{
    int weight = graph->getWeight(startingVertex, path[0]);
    for (int i = 0; i < pathSize - 1; ++i)
    {
        weight += graph->getWeight(path[i], path[i + 1]);
    }
    weight += graph->getWeight(path[pathSize - 1], startingVertex);
    return weight;
}
