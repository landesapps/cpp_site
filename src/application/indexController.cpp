#ifndef INDEXCONTROLLER_CPP
#define INDEXCONTROLLER_CPP

#include "indexController.h"

void IndexController::index(stringStruct params) {
    assoc* test = NULL;

    AssocArr::add("test", "test1", "file", &test);
    AssocArr::add("test2", "test", "string", &test);
    if(test != NULL) {
        while(test != NULL) {
            cout << test->name << " " << test->content << endl;
            test = test->next;
        }
    } else {
        cout << "NULL" << endl;
    }
}

#endif
