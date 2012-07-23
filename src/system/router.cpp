#ifndef ROUTER_CPP
#define ROUTER_CPP

#include <algorithm>
#include "router.h"

void Router::route(int argc, char *argv[]) {
    string controller = "index";
    string method = "index";
    stringStruct params;
    stringStruct split;

    if(argc > 1) {
        split = StrHelper::explode('/', argv[1]);
       
        if(split.size > 0) {
            controller = split.myString[0];

            if(split.size > 1) {
                method = split.myString[1];

                if(split.size > 2) {
                    params.myString = new string[split.size - 2];
                    params.size = split.size - 2;
                    for(int iter = 2; iter < split.size; iter++) {
                        params.myString[iter-2] = split.myString[iter];
                    }
                }
            }
        }
    }

    transform(controller.begin(), controller.end(), controller.begin(), ::tolower);
    transform(method.begin(), method.end(), method.begin(), ::tolower);

    if(controller.compare("test") == 0) {
        if(method.compare("test") == 0) {
        } else {
            TestController con;
            con.index(params);
        }
    } else {
        if(method.compare("test") == 0) {
        } else {
            IndexController con;
            con.index(params);
        }
    }
}

#endif
