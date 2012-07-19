#include "testModel.h"

return_query TestModel::index() {
    return_query result = query("SELECT id, title FROM prod_item ORDER BY id DESC LIMIT 10");
    return result;
}
