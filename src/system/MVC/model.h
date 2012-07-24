#ifndef MODEL_H
#define MODEL_H

#include <mysql.h>
#include <string.h>

using namespace std;

struct return_query {
    int     num_of_rows;
    int     num_of_cols;
    string  **result;
    string  *field_names;
};

class Model {
    private:
        MYSQL       *connection, mysql;
        MYSQL_STMT  *stmt;
        MYSQL_RES   *result;

        //Set the config files
        string      host;
        string      user;
        string      pass;
        string      schema;
        string      **res;
        return_query ret_query;
    public:
        Model();
        ~Model();
        return_query    query(string sql, MYSQL_BIND *bind);
        int             fieldPosition(return_query res, string field);
};

#endif
