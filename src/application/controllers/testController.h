#ifndef TESTCONTROLLER_H
#define TESTCONTROLLER_H

#include "../../system/MVC/controller.cpp"

class TestController: public Controller {
    public:
        void index(stringStruct params);
};

#endif
