#include "main.hpp"

#include <iostream>
#include "graphGenerator.hpp"
#include "FileUtils.hpp"
#include "bruteForceSearch.hpp"
#include "Timer.hpp"
#include "tests.hpp"
#include "GraphMatrix.hpp"
#include "printColor.hpp"

int main(void)
{
    srand(1);

    ini.SetUnicode();

    SI_Error rc = ini.LoadFile("settings.ini");
    if (rc < 0)
    {
        printf("Could not load 'settings.ini' file\n");
        return 1;
    };

    const std::string mode = ini.GetValue("common", "mode", "UNKNOWN");

    if (mode == "single_instance_test")
    {
        singleInstanceTest();
    }
    else if (mode == "multiple_instances_test")
    {
        multipleInstanceTest();
    }
    else if (mode == "time_test")
    {
        timeTest();
    }
    else
    {
        printf("Wrong mode value.\n");
        return 1;
    }

    return 0;
}

void singleInstanceTest()
{
    const char *mode = "single_instance_test";
    const int startingVertex = 0;
    Timer timer;

    const int iterations = atoi(ini.GetValue(mode, "iterations", "1"));
    const std::string inputDir = ini.GetValue("common", "input_dir", "./instances");
    const std::string outputDir = ini.GetValue("common", "output_dir", "./results");
    const std::string inputFileName = ini.GetValue(mode, "instance", "UNKNOWN");
    const std::string outputFileName = ini.GetValue(mode, "output", "UNKNOWN");

    const std::string inputFilePath = inputDir + "/" + inputFileName;
    const std::string outputFilePath = outputDir + "/" + outputFileName;

    printf("Single instance test:\n\n");
    printf("Input file: %s\n", inputFilePath.c_str());
    printf("Output file: %s\n", outputFilePath.c_str());
    printf("Number of iterations: %i\n\n", iterations);

    GraphMatrix *graph = FileUtils::loadGraph(inputFilePath);
    if (graph == NULL)
    {
        printf("File not found.\n");
        return;
    }
    printf("Graph read from file:\n");
    graph->display();

    timer.start();

    bruteForceSearch(graph, startingVertex);

    const unsigned long elapsedTime = timer.getElapsedNs();
    printf("Elapsed time [ns]: %lu\n", elapsedTime);
}

void multipleInstanceTest()
{
    printf("Multiple instances test\n");
}

void timeTest()
{
    printf("Time test\n");
}
