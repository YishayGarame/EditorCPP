#include "Editor.h"

    Editor::Editor(string fileName){
        document.FileReader(fileName);
    };

void Editor::loop()
{
    //regex a("\\(*)*\\"); // Geeks followed by any characte
    string textInput;
    string input;
    getline(cin,input);
    while(input != "q")
    {
        // getline(cin,input);
       
        if( input ==  "$")
        {
            document.commandLastRow();
        }
        else if( input ==  "d")
         {
            document.commandDeleteRow();
            cin.clear();
            //input.clear();  
        }
        else  if( (input.at(0) == '/') && input.at(input.length()-1) == '/')
         {
            textInput = input.substr(1,input.length()-2);
            document.commandSearchText(textInput);
            //cout << input << endl ;

        }
        else if( input ==  "s/old/new")
         {
            document.commandReplaceOldByNew();
            cout << input << endl ;

        }
        else if( input ==  "j")
         {
            getline(cin,input);
            if(input != ".")
            {
            document.commandAddRowToAnother(input);
            }
            cin.clear();
        }
        else if( input ==  "a")
         {
            while(input != ".")
             {
                getline(cin,input);
                if(input != ".")
                {
                document.commandAddRowsAfter(input);
                }
             }
             cin.clear();

        }
        else if( input ==  "i")
         {
            while(input != ".")
             {  
                getline(cin,input);
                if(input != ".")
                {
                document.commandAddRowsBefore(input);
                }
             }
             cin.clear();
        }
        if( input ==  "c")
         {
            while(input != ".")
             {
                getline(cin,input);
                if(input != ".")
                {
                document.commandChangeThisRow(input);
                }
             }
             cin.clear();
        }

        else if( input ==  ".")
         {
            document.commandStopAddingRows();
            input.clear();
            cin.clear();
        }
        else if( input.at(0) == 'w')
         {
             string fileName = input.substr(2,input.back());
            document.commandWriteToFile(fileName);
            cout << input << endl ;
        }

        else if( input ==  "number")
         {
            document.commandGoToRow();
            cout << input << endl ;
        }
        // else if( cin.get() ==  '\n')
        //  {
        //     cout << input << ". input "<< endl ;

        //     cout << "enter" << endl ;
        // }
        else
        {
            cout << "default commands" << endl;
             cin.clear();

        }
        getline(cin,input);

       
    }
}




