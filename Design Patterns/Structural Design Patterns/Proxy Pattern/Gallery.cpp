#include "Proxy.h"
#include "HighResolutionImage.h"

class Gallery{
public:
    static void main(){
        Proxy* image = new Proxy("luffy.png");
        image->display();
        image->display();

        delete image;
    }
};

int main(){
    Gallery::main();
    return -1;
}