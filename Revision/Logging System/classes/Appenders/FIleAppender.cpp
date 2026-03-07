#include "../../headers/Appenders/FileAppender.hpp"
#include <iostream>
#include <fstream>

std::mutex FileAppender::mt;

void FileAppender::append(LogMessage message){
    std::lock_guard<std::mutex> lock(mt);
    
    std::ofstream file("logs.txt", std::ios::app);

    if(file.is_open()){
        file<<formatter->format(message)<<std::endl;
        file.close();
    }
}