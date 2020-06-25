#ifndef CONSOLEPROCESSING_H
#define CONSOLEPROCESSING_H

#include <iostream>
#include <map>
#include <functional>
#include <string>

#include "imageprocessing.h"

class ConsoleProcessing
{
    ImageProcessing imgProc;
    std::map<std::string, std::function<bool()>> operations;

public:
    ConsoleProcessing();

    void run();

private:
    bool processing(std::string command);
};

#endif // CONSOLEPROCESSING_H
