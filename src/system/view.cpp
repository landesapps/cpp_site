#ifndef VIEW_CPP
#define VIEW_CPP

#include "view.h"

void View::render(string file, assoc *data) {
    cout << getContent(baseDir + file, data);
};

void View::render(string file) {
    cout << getContent(baseDir + file, NULL);
};

string View::getContent(string file, assoc *data) {
    string line, content;
    ifstream templateFile(file.c_str());

    if(templateFile.is_open()) {
        while(templateFile.good()) {
            getline(templateFile, line);
            content.append(line);
        }

        templateFile.close();
    } else {
        cout << "Could not open file" << endl;
    }

    if(data != NULL) {
        while(data != NULL) {
            if(content.find(data->name) != string::npos) {
                if(data->type.compare("string") == 0) {
                    content.replace(content.find(data->name), data->name.length(), data->content);
                } else if(data->type.compare("file") == 0) {
                    content.replace(content.find(data->name), data->name.length(), getContent(baseDir + data->content, data->child));
                }
            }

            data = data->next;
        }
    }

    return content;
};

View::View() {
    baseDir = "/var/www/cpp_site/src/application/views/";
}

#endif
