/*
 * Поиск копий элемента в списке. В случае наличия, весь список стирается.
 */
#include "data.h"

struct cell* unstd_act(struct cell *tmp,enum sign val){
    struct cell*root =tmp;
    while(tmp){
        if(tmp->value==val){
            while(root){
            tmp = root->next;
            free(root);
            root=tmp;
            }
            return NULL;
        }
        if(tmp->next){
            tmp=tmp->next;
        }else{
            return root;
        }
    }
    return root;
}