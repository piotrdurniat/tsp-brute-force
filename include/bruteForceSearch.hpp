#ifndef BRUTE_FORCE_SEARCH_H
#define BRUTE_FORCE_SEARCH_H
#include "GraphMatrix.hpp"

/**
 * @brief Finds the shortest Hamiltonian path in the graph
 *
 * @param graph Graph on which the algorithm operates
 * @param startingVertex Starting vertex of the path
 */
int bruteForceSearch(GraphMatrix *graph, int startingVertex);

void printImprovement(int weight, int optimum);

void printPath(int startingVertex, std::vector<int> *path);

/**
 * @brief Returns the weight of the path starting and ending at 'startVertex'
 * and passing through all of the vertices in 'path' vector
 */
int getPathWeight(GraphMatrix *graph, std::vector<int> &path, int pathSize, int startingVertex);

#endif
