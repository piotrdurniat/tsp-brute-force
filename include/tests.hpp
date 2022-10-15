#include "GraphMatrix.hpp"
#include <string>

#ifndef TESTS_H
#define TESTS_H

namespace Tests
{
    /**
     * @brief Measures algorithm execution time for randomly generated instances
     *
     * @param minVerticesNum Minimum number of vertices (inclusive)
     * @param maxVerticesNum Maximum number of vertices (inclusive)
     * @param iterCount Number of algorithm iterations for each instance size
     */
    void benchmarkAlgorithm(int minVerticesNum, int maxVerticesNum, int iterCount);

    // Checks if results are correct for all of the provided instances
    void testAlgorithm(std::vector<std::string> instances);

    void testAlgorithm(GraphMatrix *graph, int startingVertex, int iterCount, unsigned long *resTime);
};

#endif
