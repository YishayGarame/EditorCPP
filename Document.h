#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Document
{
    private:

    public:
        int samanPlace = 0 ;
        Document():samanPlace(0){};
        void FileReader(string fileName);
        void writeFile();
        vector<string> lines; 

        //Cocuments commands
                
        void commandLastRow(); //$

        void commandDeleteRow(); //d

        void commandAddRowsAfter(string input); // a

        void commandAddRowsBefore(string input); // i

        void commandAddRowToAnother(); // j
      
        void commandChangeThisRow(string input); // c
        
        void commandReplaceOldByNew(string old, string newWord); // s/old/new/
       
        void commandSearchText(string textToFind); // /text/

        void commandWriteToFile(string fileName); // w file

        void commandGoToRow(int rowNumber,int type); // number

        void commandPrintLines();

        string printLine();

};