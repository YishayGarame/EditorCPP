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
       
        if( input ==  "$")
        {
            document.commandLastRow();
            cin.ignore();
            cout << input << endl ;
        }
        if( input ==  "d")
         {
            document.commandDeleteRow();
            cout << input << endl ;

        }
        if( input ==  "/text/")
         {
            document.commandSearchText();
            cout << input << endl ;

        }
        if( input ==  "s/old/new")
         {
            document.commandReplaceOldByNew();
            cout << input << endl ;

        }
        if( input ==  "j")
         {
            document.commandAddRowToAnother();
            cout << input << endl ;

        }
        if( input ==  "a")
         {
            document.commandAddRowsAfter();
            cout << input << endl ;

        }
        if( input ==  ".")
         {
            document.commandStopAddingRows();
            cout << input << endl ;
        }
        if( input ==  "c")
         {
            document.commandChangeThisRow();
            cout << input << endl ;
        }
        if( input ==  "i")
         {
            document.commandAddRowsBefore();
            cout << input << endl ;

        }
        if( input ==  "w")
         {
            document.commandWriteToFile();
            cout << input << endl ;
        }

        if( input ==  "number")
         {
            document.commandGoToRow();
            cout << input << endl ;
        }
        else
        {
            cout << "default commands" << endl;
        }
        
       
    }
}

/*
 string input;
    while(input!="q")
    {
         cin>>input;

        switch (input) 
        {
        case '$':
        {
            Document::document.commandLastRow();
            cout << input << endl ;
        }
        case 'd':
         {
            Document::document.commandDeleteRow();
            cout << input << endl ;

        }
        case '/text/':
         {
            Document::document.commandSearchText();
            cout << input << endl ;

        }
        case 's/old/new/':
         {
            Document::document.commandReplaceOldByNew();
            cout << input << endl ;

        }
        case 'j':
         {
            Document::document.commandAddRowToAnother();
            cout << input << endl ;

        }
        case 'a':
         {
            Document::document.commandAddRowsAfter();
            cout << input << endl ;

        }
        case '.':
         {
            Document::document.commandStopAddingRows();
            cout << input << endl ;
        }
        case 'c':
         {
            Document::document.commandChangeThisRow();
            cout << input << endl ;
        }
        case 'i':
         {
            Document::document.commandAddRowsBefore();
            cout << input << endl ;

        }
        case 'w':
         {
            Document::document.commandWriteToFile();
            cout << input << endl ;
        }

        case 'number':
         {
            Document::document.commandGoToRow();
            cout << input << endl ;
        }
          default:
        {
            cout << "default commands" << endl;
            break;
        }
        */


