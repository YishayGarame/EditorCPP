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
  		cout << "saman" <<samanPlace<< endl;	

   	for(int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << i << endl;	
	}
  if(vector.size() > 0)
  {
    vector.erase (vector.begin()+samanPlace-1);
    samanPlace--;
    cout << "after" << endl;	
   	for(int i = 0; i < vector.size(); i++)
	  {
		cout << vector[i] << i << endl;	
	  }
    cout << samanPlace << endl ;
  }

   else cout << "File is Empty" << endl ;

}

// /text/
void Document::commandSearchText(string textToFind)
{
 // for(int i = samanPlace; i < vector.size(); i++)
	//{
    // if(vector.getline(i).find(textToFind))
     //{
		  //cout << vector[i] << i << endl;	
    // }
//	}
}

// s/old/new/
void Document::commandReplaceOldByNew()
{

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
    //cout << samanPlace << "saman place" << endl;
   // cout << vector.at(samanPlace-1) << "vector last" << endl;

    vector.insert(vector.begin()+samanPlace-1,input);
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
samanPlace =0 ;
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
void Document::commandGoToRow()
{

}

// .
void Document::commandStopAddingRows()
{

}


/*
w
s/old/new
/text/
number
*/
