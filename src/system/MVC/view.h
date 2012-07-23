#ifndef VIEW_H
#define VIEW_H

#include "../helpers/assocArr.cpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class View {
    private:
        string baseDir;
        string getContent(string file, assoc *data);
    public:
        void render(string file, assoc *data);
        void render(string file);
        View();
};

#endif
