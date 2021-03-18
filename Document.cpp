#include "Document.h"

void Document::FileReader(string fileName)
{
  samanPlace =0 ;
  string line;
  ifstream myfile (fileName);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      vector.push_back(line);
      //cout << line <<endl;
      samanPlace++;
    }
    	for(int i = 0; i < vector.size(); i++)
	{
		//cout << vector[i] << i << endl;	
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
  samanPlace = vector.size()-1;
}

//d
void Document::commandDeleteRow()
{

  if(vector.size() > 0 && samanPlace >= 1)
  {
    vector.erase (vector.begin()+samanPlace-1);
    samanPlace--;
  }
   else cout << "File is Empty" << endl ;

}

// /text/
void Document::commandSearchText(string textToFind)
{
int curSamanPlace= samanPlace;
 for(int i = curSamanPlace; i < vector.size(); i++)
	{
       if (vector[i].find(textToFind) != string::npos )
        {
          cout << vector[i] << endl;
          samanPlace = i ;
          cout << "saman place " << samanPlace << endl ;
          break;
        }
	}
  for(int i =0 ; i< curSamanPlace ; i++)
  {
       if (vector[i].find(textToFind) != string::npos)
          {
          samanPlace = i ;
          cout << "saman place " << samanPlace << endl ;
          break;
          }
    
  }
}

// s/old/new/
void Document::commandReplaceOldByNew(string old, string newWord)
{
  if(vector[samanPlace].find(old) != string::npos)
  {
    string tmp = vector[samanPlace];
    int whereToReplace = vector[samanPlace].find(old);
    string partA = tmp.substr(0,whereToReplace);
    string partB = tmp.substr(whereToReplace+old.length(),tmp.length()-1);
    //cout << "part a" << partA << endl;
    //cout << "part b" << partB << endl;

    string total = partA + newWord + partB;
    //vector[samanPlace].at()
    cout << "toal after rep" << total << endl;
  }
}

// j
void Document::commandAddRowToAnother(string input)
{
    //cout << samanPlace << "saman place" << endl;
   // cout << vector.at(samanPlace-1) << "vector last" << endl;
    string tempString = vector[samanPlace-1];
    //cout << tempString << "before" << endl ;
    tempString += " " + input;
   // cout << tempString << "after" << endl ;
    vector.insert(vector.begin()+samanPlace-1,input);
    samanPlace++;  
}

// a
void Document::commandAddRowsAfter(string input)
{
    //cout << samanPlace << "saman place" << endl;
   // cout << vector.at(samanPlace-1) << "vector last" << endl;
    cout << input << "saman" << samanPlace << endl;
    vector.insert(vector.begin()+samanPlace,input);
    samanPlace++;  
}


// c
void Document::commandChangeThisRow(string input)
{

    vector.insert(vector.begin()+samanPlace-1,input);
    cout << "saman " << samanPlace << endl;
    samanPlace++; 
} 

// i
void Document::commandAddRowsBefore(string input)
{
    //cout << samanPlace << "saman place" << endl;
   // cout << vector.at(samanPlace-1) << "vector last" << endl;

    vector.insert(vector.begin()+samanPlace-1,input);
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
    for(int i = 0 ; i < vector.size(); i++ )
      {
        myfile << vector[i] <<endl;
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
