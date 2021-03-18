#include "Document.h"

void Document::FileReader(string fileName)
{
  samanPlace =1 ;
  string line;
  ifstream myfile (fileName);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      lines.push_back(line);
      //cout << line <<endl;
      samanPlace++;
    }
    myfile.close();
  }

  else
   cout << "Unable to open file"; 

}
//$
void Document::commandLastRow()
{
  cout << "$" << endl ;
  samanPlace = lines.size()-1;
}

//d
void Document::commandDeleteRow()
{

  if(lines.size() > 0 && samanPlace >= 1)
  {
    lines.erase (lines.begin()+samanPlace);
    samanPlace--;
  }
   else cout << "File is Empty" << endl ;

}

// /text/
void Document::commandSearchText(string textToFind)
{
int curSamanPlace= samanPlace;
 for(int i = curSamanPlace; i < lines.size(); i++)
	{
       if (lines[i].find(textToFind) != string::npos )
        {
          samanPlace = i ;
          break;
        }
	}
  for(int i =0 ; i< curSamanPlace ; i++)
  {
       if (lines[i].find(textToFind) != string::npos)
          {
          samanPlace = i ;
          break;
          }
    
  }
}

// s/old/new/
void Document::commandReplaceOldByNew(string old, string newWord)
{
  if(lines[samanPlace].find(old) != string::npos)
  {
    string tmp = lines[samanPlace];
    int whereToReplace = lines[samanPlace].find(old);
    string partA = tmp.substr(0,whereToReplace);
    string partB = tmp.substr(whereToReplace+old.length(),tmp.length()-1);
    string total = partA + newWord + partB;
    lines[samanPlace] = total;
  }
}

// j
void Document::commandAddRowToAnother()
{
    string tempString = lines[samanPlace];
    string nextLine = lines[samanPlace+1];
    lines.erase(lines.begin()+samanPlace+1);
    tempString += " " + nextLine;
    lines.insert(lines.begin()+samanPlace,tempString);
    samanPlace++;  
}

// a
void Document::commandAddRowsAfter(string input)
{
    //cout << samanPlace << "saman place" << endl;
   // cout << lines.at(samanPlace-1) << "lines last" << endl;
    //cout << input << "saman" << samanPlace << endl;
    lines.insert(lines.begin()+samanPlace,input);
    samanPlace++;  
}


// c
void Document::commandChangeThisRow(string input)
{

    lines.insert(lines.begin()+samanPlace-1,input);
    cout << "saman " << samanPlace << endl;
    cout << "before " << lines[samanPlace]<<endl;
    samanPlace++; 
    cout << "after " << lines[samanPlace]<<endl;
    lines[samanPlace].erase();
    cout << "after deleetted " << lines[samanPlace]<<endl;


} 

// i
void Document::commandAddRowsBefore(string input)
{
    //cout << samanPlace << "saman place" << endl;
   // cout << lines.at(samanPlace-1) << "lines last" << endl;

    lines.insert(lines.begin()+samanPlace-1,input);
    samanPlace++; 
}

// w file
void Document::commandWriteToFile(string fileName)
{
  string line;
  ofstream myfile;
  myfile.open(fileName);
  if (myfile.is_open())
  {
    for(int i = 0 ; i < lines.size(); i++ )
      {
        myfile << lines[i] <<endl;
      }
    myfile.close();
  }

  else
   cout << "Unable to open file"; 

}

// number
void Document::commandGoToRow(int rowNumber, int type)
{
  if(type == 0)
  {
    samanPlace = rowNumber;
  }
  else if (type == 1)
  {
    samanPlace += rowNumber;
  }
  else
  {
    samanPlace -= rowNumber;
    if(samanPlace < 1){
      samanPlace = 0 ;
    }

  }
}

/*
continue with c
s/old/new
/text/
*/
