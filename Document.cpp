#include "Document.h"

void Document::FileReader(string fileName)
{
  samanPlace = 0 ;
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
  samanPlace = lines.size();
  cout << "$ line" << samanPlace;
}

//d
void Document::commandDeleteRow()
{

  if(lines.size() > 0 && samanPlace >= 1)
  {
    lines.erase (lines.begin()+samanPlace);
    samanPlace--;
     cout<< printLine()<< endl;

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
          samanPlace = i+1 ;
          break;
        }
	}
  for(int i =0 ; i< curSamanPlace ; i++)
  {
       if (lines[i].find(textToFind) != string::npos)
          {
          samanPlace = i+1 ;
          break;
          }
    
  }
 cout<< printLine()<< endl;
}

// s/old/new/
void Document::commandReplaceOldByNew(string old, string newWord)
{
  if(lines[samanPlace-1].find(old) != string::npos)
  {
    string tmp = lines[samanPlace-1];
    int whereToReplace = lines[samanPlace-1].find(old);
    string partA = tmp.substr(0,whereToReplace);
    string partB = tmp.substr(whereToReplace+old.length(),tmp.length()-1);
    string total = partA + newWord + partB;
    lines[samanPlace-1] = total;

  }
}

// j
void Document::commandAddRowToAnother()
{
    string tempString = lines[samanPlace-1];
    string nextLine = lines[samanPlace];
    lines.erase(lines.begin()+samanPlace);
    tempString += " " + nextLine;
    lines.at(samanPlace-1) = tempString ;
    //lines.insert(lines.begin()+samanPlace,tempString);
    samanPlace++;  
     cout<< printLine()<< endl;

}

// a
void Document::commandAddRowsAfter(string input)
{
    cout << samanPlace << " saman place a" << endl;
   // cout << lines.at(samanPlace-1) << "lines last" << endl;
    //cout << input << "saman" << samanPlace << endl;
    lines.insert(lines.begin()+samanPlace,input);
    samanPlace++;  
     cout<< printLine()<< endl;

}


// c
void Document::commandChangeThisRow(string input)
{
    cout << "saman c : " << samanPlace<< endl;
    cout << " line is " << lines[samanPlace-1];
    lines[samanPlace-1].erase();
    lines.insert(lines.begin()+samanPlace-1,input);
    //cout << "saman " << samanPlace << endl;
    //cout << "before " << lines[samanPlace]<<endl;
    samanPlace++; 
    //cout << "after " << lines[samanPlace]<<endl;
    //cout << "after deleetted " << lines[samanPlace]<<endl;
     cout<< printLine()<< endl;



} 
void Document::commandPrintLines()
{
      cout<<"saman place is: "<< samanPlace <<endl;
    cout <<"lines size " << lines.size()<<endl;
  for(int i =0; i<lines.size(); i++)
  {
    cout << "line number: " << i << " is: "<<lines[i]<<endl;

  }
}



// i
void Document::commandAddRowsBefore(string input)
{
    int tmpsaman =  max(samanPlace-1,0);
    //samanPlace = max(samanPlace-1,0);
    //cout << lines.at(samanPlace) << " lines last" << endl;
    //cout << samanPlace << " saman place" << endl;
    lines.insert(lines.begin()+tmpsaman,input);
    tmpsaman++;
    samanPlace++; 
    cout<< "saman "<<samanPlace<< endl;
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
  //last added
  if(rowNumber == 0)
  {
    rowNumber = 1;
  }
  if(type == 0)
  {
    samanPlace = rowNumber;
  }
  else if (type == 1)
  {
    samanPlace += rowNumber;
    cout <<" after adding number " <<lines[samanPlace] << endl;
  }
  else
  {
    samanPlace -= rowNumber;
    if(samanPlace < 1){
      samanPlace = 1 ;
    }

  }
 cout<< printLine()<< endl;
}

string Document::printLine()
{
      if(samanPlace == 0 || samanPlace > lines.size())
    {
        return nullptr;
    }
    return lines.at(samanPlace - 1); 
}

/*
continue with c
s/old/new
/text/
*/
