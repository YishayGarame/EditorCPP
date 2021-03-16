#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Document
{
    private:

    public:
        Document(){};
        void FileReader(string fileName);
        void writeFile();
        vector <string> vector;
        int samanPlace;
        void commandToDo(string command);
        //string fileName;
};