#ifndef ASSOCARR_CPP
#define ASSOCARR_CPP

#include "assocArr.h"

void AssocArr::add(string name, string content, string type, assoc **arr) {
    assoc* newData = new assoc;
    newData->name = name;
    newData->content = content;
    newData->type = type;
    newData->prev = *arr;
    newData->next = NULL;

    if(*arr != NULL) {
        assoc* current = *arr;

        while(current->next != NULL) {
            current = current->next;
        }

        current->next = newData;
    } else {
        *arr = newData;
    }
}

#endif
