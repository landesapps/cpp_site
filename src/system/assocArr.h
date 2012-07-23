#ifndef ASSOCARR_H
#define ASSOCARR_H

#include <string>

struct assoc {
    string name;
    string content;
    string type;
    assoc* prev;
    assoc* next;
};

class AssocArr {
    public:
        static void add(string name, string content, string type, assoc **arr);
};

#endif
