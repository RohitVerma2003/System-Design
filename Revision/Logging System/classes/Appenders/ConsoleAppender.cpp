#include "../../headers/Appenders/ConsoleAppender.hpp"
#include <iostream>

std::mutex ConsoleAppender::mt;

void ConsoleAppender::append(LogMessage message){
    std::lock_guard<std::mutex> lock(mt);
    std::cout<<this->formatter->format(message)<<std::endl;
}