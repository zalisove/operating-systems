#include <stdlib.h>
#include <stdio.h>
#include "lib/linkedList.h"

int main(int argc, char const *argv[]){
    
    LinkedList* list = newLinkedList();


    for (size_t i = 0; i < 10; i++){
        list->add(list,i);
    }

    list->insert(list,0,9999);
    list->removeItem(list,0);
    list->set(list,5,500);
    list->removeItem(list,5);

    Node* tmp = list->root; 
    for (size_t i = 0; i < list->size(list); i++){
        printf("%d  ", list->get(list,i));
    }
    printf("\n");
  
    return 0;
}
