#include "./headers/LogManager.hpp"
#include "./headers/Appenders/ConsoleAppender.hpp"
#include "./headers/Appenders/FileAppender.hpp"
#include "./headers/Formatters/TextFormatter.hpp"

#include <thread>
using namespace std;

int main(){
    LogManager& logger = LogManager::get_instance();

    logger.add_appender(DEBUG , new ConsoleAppender(new TextFormatter()));
    logger.add_appender(ERROR , new ConsoleAppender(new TextFormatter()));
    logger.add_appender(ERROR , new FileAppender(new TextFormatter()));
    logger.add_appender(INFO , new ConsoleAppender(new TextFormatter()));
    logger.add_appender(INFO , new FileAppender(new TextFormatter()));

    logger.info("This is information log1");
    logger.info("This is information log2");
    logger.debug("This is a debug log");
    logger.error("This is an error");

    return 0;
}