#include <stdlib.h>
#include <stdio.h>
#include "lib/arrayList.h"

int main(int argc, char const *argv[]){
    
    ArrayList* list = newArrayList();


    for (size_t i = 0; i < 10; i++){
        list->add(list,i);
    }

    list->insert(list,5,9999);
    list->removeItem(list,5);
    list->set(list,5,500);
    for (size_t i = 0; i < list->size(list); i++){
        printf("%d  ", list->get(list,i));
    }
    printf("\n");
  
    return 0;
}
