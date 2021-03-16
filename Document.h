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

        void commandSearchText(); // /text/

        void commandReplaceOldByNew(); // s/old/new/

        void commandAddRowToAnother(); // j

        void commandAddRowsAfter(); // a

        void commandStopAddingRows(); // .

        void commandChangeThisRow(); // c

        void commandAddRowsBefore(); // i

        void commandWriteToFile(); // w file

        void commandGoToRow(); // number

};