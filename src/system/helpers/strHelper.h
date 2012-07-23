#ifndef STRHELPER_H
#define STRHELPER_H

#include <string>

struct stringStruct {
    string* myString;
    int size;
};

class StrHelper {
    public:
        static stringStruct explode(char separator, string input);
        static void add(string *&arr, int arr_size, string word);
};

#endif
