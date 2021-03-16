#include "Document.h"

void Document::FileReader(string fileName)
{
  string line;
  ifstream myfile (fileName);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      vector.push_back(line);
      cout << line <<endl;
    }
    	for(int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << i << endl;	
	}
    myfile.close();
  }

  else cout << "Unable to open file"; 

}
//$
void Document::commandLastRow()
{
  cout << "$" << endl ;
}

//d
void Document::commandDeleteRow()
{

}

// /text/
void Document::commandSearchText()
{

}

// s/old/new/
void Document::commandReplaceOldByNew()
{

}

// j
void Document::commandAddRowToAnother()
{

}

// a
void Document::commandAddRowsAfter()
{

}

// .
void Document::commandStopAddingRows()
{

}

// c
void Document::commandChangeThisRow()
{

} 

// i
void Document::commandAddRowsBefore()
{

}

// w file
void Document::commandWriteToFile()
{

}

// number
void Document::commandGoToRow()
{

}
