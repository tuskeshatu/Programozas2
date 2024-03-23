#include "logging.h"

using namespace logging;

int main()
{
	Logger &logger = Logger::getInstance();

	// If logging::Logger is singleton, this is a reference to the same instance
	Logger &loggerSingletonEEzACsoda = Logger::getInstance();
	loggerSingletonEEzACsoda.log(ERROR, "Ha singleton ez ott kell legyen a fileban");

	// If '=' operator and copy constructor wouldn't be disabled, this would
	// create another instance of Logger. Since these operations are deleted,
	// the compiler throws errors.
	
	// Logger loggerSingletonEEzACsodaPart2 = Logger::getInstance();
	// Logger loggerSingletonEEzACsodaPart3 = logger;

	logger.setDefaultLogLevel(DEBUG);

	logger.log(INFO, "Network connection established.");
	logger.log(DEBUG, "Module A can communicate with remote host R.");
	logger.log(WARN, "Network card junction temperature is getting higher and higher.");
	logger.log(ERROR, "Network connection interrupted.");

	return 0;
}