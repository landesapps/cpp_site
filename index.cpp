#include <iostream>
#include <stdlib.h>
#include "src/application/testModel.cpp"
#include "src/system/router.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    int query_state;
    return_query result;

    cout << "Content-type: text/html" << endl << endl;
    cout << "<html><head></head><body>";

    Router route;
    route.route(argc, argv);


    /*TestModel test;

    result = test.index();

    for(int row_iter = 0; row_iter < result.num_of_rows; row_iter++) {
        for(int col_iter = 0; col_iter < result.num_of_cols; col_iter++) {
            cout << result.field_names[col_iter] << ": " << result.result[row_iter][col_iter] << " ";
        }
        cout << "<br/>";
    }

    cout << test.fieldPosition(result, "titles") << "<br/>";*/
   
    cout << "</body></html>";

    return 0;
}
