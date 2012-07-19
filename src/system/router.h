#ifndef ROUTER_H
#define ROUTER_H

#include "../application/indexController.cpp"
#include "strHelper.cpp"

class Router {
    public:
        void route(int argc, char *argv[]);
};

#endif
