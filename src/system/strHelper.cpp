#ifndef STRHELPER_CPP
#define STRHELPER_CPP

#include "strHelper.h"

stringStruct StrHelper::explode(char separator, string input) {
    int prev_pos = 0;
    int next_pos = 0;
    int arr_size = 0;
    string *ret;

    while((next_pos = input.find(separator)) != string::npos) {
        StrHelper::add(ret, arr_size++, input.substr(prev_pos, next_pos));
        input = input.substr(next_pos+1);
    }

    StrHelper::add(ret, arr_size++, input.substr(prev_pos));

    stringStruct exploded;
    exploded.myString = ret;
    exploded.size = arr_size;
    return exploded;
}

void StrHelper::add(string *&arr, int arr_size, string word) {
    string *temp = new string[arr_size];

    for(int iter = 0; iter < arr_size; iter++) {
        temp[iter] = arr[iter];
    }

    arr = new string[arr_size+1];

    for(int iter = 0; iter < arr_size; iter++) {
        arr[iter] = temp[iter];
    }

    arr[arr_size] = word;
}

#endif
