#ifndef ROUTER_H
#define ROUTER_H

#include "../application/controllers/indexController.cpp"
#include "../application/controllers/testController.cpp"
#include "strHelper.cpp"

class Router {
    public:
        void route(int argc, char *argv[]);
};

#endif
