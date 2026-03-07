#ifndef TEXT_FORMATTER_HPP
#define TEXT_FORMATTER_HPP

#include "..//IFormatter.hpp"

class TextFormatter: public IFormatter{
public:
    std::string format(LogMessage message) override;
};


#endif