#include "Editor.h"

    Editor::Editor(string fileName){
        document.FileReader(fileName);
    };

void Editor::loop()
{
    string input;
    while(input!="q")
    {
        cin>>input;
    }
}

