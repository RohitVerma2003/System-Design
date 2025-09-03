#include "FileSystemItem.hpp"
#include "Folder.hpp"
#include "File.hpp"
#include <iostream>
using namespace std;

class FileExplorer{
public: 
    static void main(){
        FileSystemItem* file1 = new File("file.exe" , 1);
        FileSystemItem* file2 = new File("Cpp.c" , 3);
        FileSystemItem* file3 = new File("xyz.txt" , 5);

        Folder* folder1 = new Folder("Documents");
        folder1->add_item(file1);
        folder1->add_item(file2);

        Folder* folder2 = new Folder("Home");
        folder2->add_item(folder1);
        folder2->add_item(file3);

        folder2->print_structure("");
        cout<<"Total Size: "<<folder2->get_size()<<" KB"<<endl;

        delete file1;
        delete file2;
        delete file3;
        delete folder1;
        delete folder2;
    }
};

int main(){
    FileExplorer::main();
    return -1;
}