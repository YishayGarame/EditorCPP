#include <iostream>
#include <regex> 
#include "Document.h"
using namespace std;

class Editor
{
    private:
        Document document;

    public:
        Editor(): document(){};
        Editor(string fileName);
        void loop();

};
