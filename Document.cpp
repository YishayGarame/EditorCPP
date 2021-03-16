#include "Document.h"

void Document::FileReader(string fileName){
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