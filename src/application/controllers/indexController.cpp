#ifndef INDEXCONTROLLER_CPP
#define INDEXCONTROLLER_CPP

#include "indexController.h"

void IndexController::index(stringStruct params) {
    assoc* test = NULL;

    AssocArr::add("[[content]]", "index.tpl", "file", &test);

    view.render("template.tpl", test);
}

#endif
