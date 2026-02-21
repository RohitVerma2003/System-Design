#ifndef KEYWORD_HPP
#define KEYWORD_HPP

#include <string>
using namespace std;

class Keyword{
private:
    string keyword;
public:
    Keyword(string text);
    string get_keyword();
};

#endif