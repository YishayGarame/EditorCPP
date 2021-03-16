#include <iostream>
#include "Document.h"
using namespace std;

class Editor
{
    private:
        Document document;

    public:
        Editor(){};
        Editor(string fileName);
        void loop();
};
