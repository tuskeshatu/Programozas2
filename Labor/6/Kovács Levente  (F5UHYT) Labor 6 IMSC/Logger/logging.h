#pragma once

#include <string>

namespace logging
{

    // Enum for log levels
    typedef enum logType_t
    {
        ERROR,
        WARN,
        INFO,
        DEBUG
    } logType_t;

    // Logger class
    class Logger
    {
    public:
        // Static getInstance for singleton class
        static Logger &getInstance()
        {
            //Static instance to prevent multiple instances
            static Logger instance;
            instance.logLevel = ERROR;
            return instance;
        }

        // Delete copy constructor and '=' operator to prevent creation of copies
        Logger(const Logger &) = delete;
        void operator=(const Logger &) = delete;

        // Function to set desired log level
        void setDefaultLogLevel(logType_t);

        // Function for logging
        void log(logType_t, const std::string);

    private:
        // Maximum log level
        logType_t logLevel;

        std::string logFileName;

        // Constructor and destructor
        Logger();
        ~Logger();
    };

} // namespace logging
