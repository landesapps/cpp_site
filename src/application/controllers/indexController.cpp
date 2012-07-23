#ifndef INDEXCONTROLLER_CPP
#define INDEXCONTROLLER_CPP

#include "indexController.h"

void IndexController::index(stringStruct params) {
    assoc* test = NULL;
    assoc* child = NULL;

    AssocArr::add("[[child]]", "child.tpl", "file", &child);
    AssocArr::add("[[content]]", "index.tpl", "file", &test, child);

    view.render("template.tpl", test);
}

#endif
