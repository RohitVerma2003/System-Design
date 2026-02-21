#ifndef TAG_HPP
#define TAG_HPP

#include <string>
using namespace std;

class Tag{
private: 
    string tag;
public:
    Tag(string text);
    string get_tag();
};

#endif