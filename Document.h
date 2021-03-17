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
        //string fileName;

        //Cocuments commands
                
        void commandLastRow(); //$

        void commandDeleteRow(); //d

        void commandAddRowsAfter(string input); // a

        void commandAddRowsBefore(string input); // i

        void commandAddRowToAnother(string input); // j
      
        void commandChangeThisRow(string input); // c
        
        void commandReplaceOldByNew(); // s/old/new/
       
        void commandSearchText(string textToFind); // /text/

        void commandWriteToFile(string fileName); // w file

        void commandGoToRow(); // number

        void commandStopAddingRows(); // .
};