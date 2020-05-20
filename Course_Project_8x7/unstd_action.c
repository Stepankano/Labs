/*
 * Дополнение списка копиями элемента до определенной длины
 */
#include "data.h"

struct cell* unstd_act(struct cell *tmp,type_name val,int range){
    while(std_size(tmp) < range ){
        tmp = std_insert(tmp, val);
    }
    return tmp;
}