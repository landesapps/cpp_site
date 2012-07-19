#include "router.h"

void Router::route(int argc, char *argv[]) {
    string controller = "index";
    string method = "index";
    string *params;
    stringStruct split;
    int paramCount = 0;

    if(argc > 1) {
        split = StrHelper::explode('/', argv[1]);
        cout << split.myString[0] << endl;
       
        if(split.size > 0) {
            controller = split.myString[0];

            if(split.size > 1) {
                method = split.myString[1];

                if(split.size > 2) {
                    params = new string[split.size - 2];
                    paramCount = split.size - 2;
                    for(int iter = 2; iter < split.size; iter++) {
                        params[iter-2] = split.myString[iter];
                    }
                }
            }
        }
    }

    cout << "Controller: " << controller << "<br/>";
    cout << "Method: " << method << "<br/>";
    
    for(int iter = 0; iter < paramCount; iter++) {
        cout << "Param" << iter << ": " << params[iter] << "<br/>";
    }
}
