#include "logging.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#define TIME_BUFF_SIZ 100

// Constructor to create logfile
logging::Logger::Logger()
{

    // Set default log level to ERROR
    logLevel = ERROR;

    // Initialize time string buffer and time var
    char cCurenttime[TIME_BUFF_SIZ];
    time_t currentTime;

    // Get current time and initialize tm* pointer for strftime
    time(&currentTime);
    tm *currentTm = localtime(&currentTime);

    // Write formatted time to C string
    strftime(cCurenttime, TIME_BUFF_SIZ, "%Y-%m-%d_%H-%M-%S", currentTm);

    // Create file name from current time and log.txt
    logFileName = cCurenttime;

    logFileName += "_log.txt";

    // Try to open file
    std::ofstream logFile(logFileName);

    // Initializing file with start message
    if (logFile.is_open())
    {
        strftime(cCurenttime, TIME_BUFF_SIZ, "%H:%M:%S", currentTm);
        logFile << cCurenttime << ":\t"
                << "Log started" << std::endl;
        logFile.close();
    }
    else
        throw "Couldn't create logfile";
}

// Implementation of the destructor
logging::Logger::~Logger()
{
    // Try to open log.txt
    std::ofstream logFile(logFileName, std::ios::app);

    // Write log message to file
    if (logFile.is_open())
    {
        // Initialize time string buffer and time var
        char cCurenttime[TIME_BUFF_SIZ];
        std::time_t currentTime;

        // Get current time and initialize tm* pointer for strftime
        time(&currentTime);
        std::tm *currentTm = localtime(&currentTime);

        // Write formatted time to C string
        strftime(cCurenttime, TIME_BUFF_SIZ, "%H:%M:%S", currentTm);

        logFile << cCurenttime << ":\t"
                << "Log ended" << std::endl;
        logFile.close();
    }
}

// Set log level to param
void logging::Logger::setDefaultLogLevel(logType_t targetLevel)
{
    logLevel = targetLevel;
}

void logging::Logger::log(logType_t currentLogLevel, const std::string logMessage)
{
    // Check if log is needed based on set logLevel
    if (currentLogLevel > logLevel)
        return;

    // Try to open log.txt
    std::ofstream logFile(logFileName, std::ios::app);

    // Write log msg to file
    if (logFile.is_open())
    {
        // Initialize time string buffer and time var
        char cCurenttime[TIME_BUFF_SIZ];
        std::time_t currentTime;

        // Get current time and initialize tm* pointer for strftime
        time(&currentTime);
        std::tm *currentTm = localtime(&currentTime);

        // Write formatted time to C string
        strftime(cCurenttime, TIME_BUFF_SIZ, "%H:%M:%S", currentTm);

        logFile << cCurenttime << ":\t" << logMessage << std::endl;
        logFile.close();
    }
    else
        throw "Couldn't open logfile";
}
