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
            //cout << " word to search " << textInput <<endl;
            document.commandSearchText(textInput);
            //cout << input << endl ;

        }
        else if( (input.at(0) == 's') && input.at(1) == '/' && input.at(input.length()-1) == '/' && input.find("/",2,input.length()-2))
         {
            string tmpStr = input.substr(2,input.length()-3);
            int delimeterPos = tmpStr.find("/");
            string old = tmpStr.substr(0,delimeterPos);
            cout<< "old: "<<old<<endl;
            string newWord = tmpStr.substr(delimeterPos+1,tmpStr.length()-1);
            cout<<"new: "<< newWord<<endl;
            document.commandReplaceOldByNew(old,newWord);

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
                 cout << "alon shat"<<endl;
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
            input.clear();
            cin.clear();
        }
        else if( input.at(0) == 'w')
         {
             string fileName = input.substr(2,input.back());
            document.commandWriteToFile(fileName);
            cout << input << endl ;
        }

        else if(isdigit(input[0]) || isdigit(input[1]))
         {
             int type; // plus=1 or minus=0
             int rowNumber;
             if(isdigit(input[0]))
             {
                type=0;
                rowNumber =stoi(input);
                document.commandGoToRow(rowNumber,type);
             }
             else // it has "+" or "-" before"
             {
                string tmpNum;
                tmpNum = input.substr(1, input.back());
                rowNumber = stoi(tmpNum);
                 if(input.at(0) == '+')
                 {
                     type = 1;
                     document.commandGoToRow(rowNumber,type);

                 }
                 else
                 {
                    type =-1 ;
                    document.commandGoToRow(rowNumber,type);
                 }
             }    
        }
        else
        {
            cout << "default commands" << endl;
             cin.clear();

        }
        getline(cin,input);

       
    }
}




