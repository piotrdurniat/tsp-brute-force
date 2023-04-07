#include "tests.hpp"

#include <iostream>
#include "bruteForceSearch.hpp"
#include "Timer.hpp"
#include "graphGenerator.hpp"
#include "FileUtils.hpp"
#include "printColor.hpp"
#include "TestResult.hpp"

void Tests::fileInstanceTest(GraphMatrix *graph, int iterCount, std::string instanceName, std::string outputPath)
{
    FileUtils::writeInstanceTestHeader(outputPath);
    const int startingVertex = 0;
    Timer timer;

    for (int i = 0; i < iterCount; ++i)
    {
        timer.start();
        Path path = bruteForceSearch(graph, startingVertex);
        const unsigned long elapsedTime = timer.getElapsedNs();

        bool isCorrect = path.weight == graph->optimum;

        TestResult testResult(instanceName, elapsedTime, path, isCorrect);

        FileUtils::appendTestResult(outputPath, testResult);
    }
}

void Tests::randomInstanceTest(int minSize, int maxSize, int iterCount, std::string outputPath)
{

    FileUtils::writeRandomInstanceTestHeader(outputPath);
    Timer timer;
    GraphMatrix *graph;
    const int startingVertex = 0;

    srand(1);
    for (int vertexCount = minSize; vertexCount <= maxSize; vertexCount++)
    {
        long unsigned averageTime = 0;
        for (int i = 0; i < iterCount; ++i)
        {
            graph = graphGenerator::getRandom(vertexCount, 10);

            timer.start();
            bruteForceSearch(graph, startingVertex);
            averageTime += timer.getElapsedNs();

            delete graph;
            graph = NULL;
        }
        averageTime /= iterCount;
        FileUtils::appendRandomInstanceTestResult(outputPath, vertexCount, averageTime);
    }
    printf("Done. Saved to file.\n");
}

void Tests::testAlgorithm(std::vector<std::string> instances)
{
    for (std::string instanceName : instances)
    {
        GraphMatrix *graph;
        graph = FileUtils::loadGraph(instanceName);

        const int startingVertex = 0;

        Path path = bruteForceSearch(graph, startingVertex);
        const bool correctRes = path.weight == graph->optimum;

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
