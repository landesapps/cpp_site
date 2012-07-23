#ifndef MODEL_CPP
#define MODEL_CPP

#include "model.h"

/**
 * When the model is created, create a connection to the database
 */
Model::Model() {
    host = "127.0.0.1";
    user = "david";
    pass = "";
    schema = "sm_www";

    mysql_init(&mysql);
    connection = mysql_real_connect(&mysql, host.c_str(), user.c_str(), pass.c_str(), schema.c_str(), 0, 0, 0);

     if(connection == NULL) {
         cout << mysql_error(&mysql) << endl;
         exit(1);
    }
}

/**
 * When the model destructs, close the mysql connection
 */
Model::~Model() {
    mysql_close(connection);
}

/**
 * Query the database and get the results back
 *
 * @param string sql The query you want to execute
 *
 * @return return_query
 */
//TODO: Turn queries into prepare statements
return_query Model::query(string sql) {
    int query_state;
    int rows, fields;
    MYSQL_ROW row;
    MYSQL_FIELD *field_values;

    query_state = mysql_query(connection, sql.c_str());

    if(query_state != 0) {
        cout << mysql_error(connection) << endl;
        exit(1);
    }

    result =  mysql_store_result(connection);
    rows = mysql_num_rows(result);
    fields = mysql_num_fields(result);

    res = new (nothrow) string*[rows];

    for(int row_iter = 0; row_iter < rows; row_iter++) {
        row = mysql_fetch_row(result);
        res[row_iter] = new string[fields];
        for(int col_iter = 0; col_iter < fields; col_iter++) {
            res[row_iter][col_iter] = row[col_iter];
        }
    }
    
    string *field_names = new (nothrow) string[fields];
    field_values = mysql_fetch_fields(result);

    for(int iter = 0; iter < fields; iter++) {
        field_names[iter] = field_values[iter].name;
    }

    mysql_free_result(result);

    ret_query.num_of_rows = rows;
    ret_query.num_of_cols = fields;
    ret_query.result = res;
    ret_query.field_names = field_names;

    return ret_query;
}

/**
 * Returns the position in the result of the field
 *
 * @param return_query res The results of the query
 * @param string field The name of the field
 *
 * @return int -1 if not found
 */
int Model::fieldPosition(return_query res, string field) {
    for(int iter = 0; iter < res.num_of_cols; iter++) {
        if(res.field_names[iter].compare(field) == 0) {
            return iter;
        }
    }

    return -1;
}

#endif
