#include "tests.hpp"

#include <iostream>
#include "bruteForceSearch.hpp"
#include "Timer.hpp"
#include "graphGenerator.hpp"
#include "FileUtils.hpp"
#include "printColor.hpp"

void Tests::testAlgorithm(GraphMatrix *graph, int startingVertex, int iterCount, unsigned long *resTime)
{
    Timer timer;

    unsigned long averageTime = 0;
    for (int i = 0; i < iterCount; ++i)
    {
        timer.start();
        bruteForceSearch(graph, startingVertex);
        const unsigned long elapsedTime = timer.getElapsedNs();
        // printf("%lu\n", elapsedTime);
        averageTime += elapsedTime;
    }
    averageTime /= iterCount;
    (*resTime) = averageTime;
}

void Tests::benchmarkAlgorithm(int minVerticesNum, int maxVerticesNum, int iterCount)
{
    Timer timer;
    GraphMatrix *graph;
    const int startingVertex = 0;

    srand(1);
    printf("Num of vertices, time\n");
    for (int verticesNum = minVerticesNum; verticesNum <= maxVerticesNum; verticesNum++)
    {
        long unsigned averageTime = 0;
        for (int i = 0; i < iterCount; ++i)
        {
            graph = graphGenerator::getRandom(verticesNum, 10);

            timer.start();
            bruteForceSearch(graph, startingVertex);
            averageTime += timer.getElapsedNs();

            delete graph;
            graph = NULL;
        }
        averageTime /= iterCount;
        printf("%i, %lu\n", verticesNum, averageTime);
    }
}

void Tests::testAlgorithm(std::vector<std::string> instances)
{
    for (std::string instanceName : instances)
    {
        GraphMatrix *graph;
        graph = FileUtils::loadGraph(instanceName);

        const int startingVertex = 0;

        const int pathWeight = bruteForceSearch(graph, startingVertex);
        const bool correctRes = pathWeight == graph->optimum;

        printf("%14s", instanceName.c_str());

        if (correctRes)
        {
            printColor(" PASS\n", GREEN, BOLD, BOLD);
        }
        else
        {
            printColor(" FAIL\n", RED, BOLD, BOLD);
        }

        delete graph;
        graph = NULL;
    }
}
