#ifndef INDEXCONTROLLER_H
#define INDEXCONTROLLER_H

#include "../../system/MVC/controller.cpp"
#include "../../system/helpers/assocArr.cpp"

class IndexController: public Controller {
    public:
        void index(stringStruct params);
};

#endif
