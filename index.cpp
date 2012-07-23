#include <iostream>
#include <stdlib.h>
#include "src/system/router.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "Content-type: text/html" << endl << endl;

    Router route;
    route.route(argc, argv);

    return 0;
}
