#include <stdlib.h>
#include <datastructs.h>

typedef struct ds_linked_list_node {
    void* data;
    ds_linked_list_node * next;
} ds_linked_list_node ;

typedef struct ds_doubly_linked_list_node {

    void* data;
    ds_doubly_linked_list_node * previous;
    ds_doubly_linked_list_node * next;

} ds_doubly_linked_list_node ;

ds_linked_list* ds_linked_list_create(){

    ds_linked_list* result = malloc(sizeof(ds_linked_list));
    result->head = NULL;
    result->size = 0;
    return result;

}

void ds_linked_list_delete(ds_linked_list** list_ptr){
    
    ds_linked_list_clear(*list_ptr);
    free(*list_ptr);
    *list_ptr = NULL;
}

void ds_linked_list_clear(ds_linked_list* list){
    
    ds_linked_list_node* tmp = NULL;
    ds_linked_list_node* cur = list->head;
    while(cur != NULL){
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->size = 0;
}

void ds_linked_list_add(ds_linked_list* list, void* data){
    
    ds_linked_list_node* new_node = malloc(sizeof(ds_linked_list_node));
    new_node->data = data;
    new_node->next = NULL;
    
    if(list->head == NULL){ // the list is empty
        list->head = new_node;
        list->size = 1;
    } else {
        ds_linked_list_node* cur = list->head;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = new_node;
        list->size ++;
    }
}

void ds_linked_list_insert_at(ds_linked_list* list, void* data, int index){
    
    int cur_index = 0;
    
    ds_linked_list_node* n = list->head;
    
    ds_linked_list_node* new_node = malloc(sizeof(ds_linked_list_node));
    new_node->data = data;
    
    if((n == NULL) || (index <= 0)){ // insert at list head
        list->head = new_node;
        new_node->next = n;
        list->size ++;
    } else if((index > 0) && (index < list->size)){ // insert at specified index
        while((cur_index<index-1) && (n!=NULL)){
            n = n->next;
            cur_index++;
        }
        if(n!=NULL){
            new_node->next = n->next;
            n->next = new_node;
            list->size ++;
        } else {
            free(new_node);
        }
    } else if((index > 0) && (index >= list->size)){ // insert at list end
        while(n->next!=NULL){
            n = n->next;
        }
        if(n!=NULL){
            new_node->next = NULL;
            n->next = new_node;
            list->size ++;
        } else {
            free(new_node);
        }
    }  else {
        free(new_node);
    }
    
}

void* ds_linked_list_get(ds_linked_list* list, int index){
    
    ds_linked_list_node* n = NULL;
    int cur_index = 0;
    n = list->head;
    
    if (index <= 0) { // return the first element
        n = list->head;
    } else if((index > 0) && (index < list->size)){ // return the element at the given index
        while((cur_index<index) && (n!=NULL)){
            n = n->next;
            cur_index++;
        }
    }  else if((index > 0) && (index >= list->size)){ // return the last element
        while(n->next!=NULL){
            n = n->next;
        }
    }
    if (n!=NULL) {
        return n->data;
    } else {
        return NULL;
    }
    
}

void* ds_linked_list_remove(ds_linked_list* list, int index){
    
    ds_linked_list_node* n = NULL;
    ds_linked_list_node* tmp = NULL;
    void* result = NULL;
    int cur_index = 0;
    n = list->head;
    
    if((index == 0)&&(list->size>0)){
        result = n->data;
        list->head = n->next;
        free(n);
        list->size --;
        return result;
    } else if((index > 0) && (index < list->size)){
        while((cur_index<index-1) && (n!=NULL)){
            n = n->next;
            cur_index++;
        }
        if((n!=NULL)&&(n->next!=NULL)){
            tmp = n->next;
            n->next = tmp->next;
            result = tmp->data;
            free(tmp);
            list->size --;
            return result;
        }
    }
    return NULL;
    
}

ds_doubly_linked_list* ds_doubly_linked_list_create(){

    ds_doubly_linked_list* result = malloc(sizeof(ds_doubly_linked_list));
    result->head = NULL;
    result->size = 0;
    return result;

}

void ds_doubly_linked_list_delete(ds_doubly_linked_list** list_ptr){

    ds_doubly_linked_list_clear(*list_ptr);
    free(*list_ptr);
    *list_ptr = NULL;

}

void ds_doubly_linked_list_clear(ds_doubly_linked_list* list){
    
    ds_doubly_linked_list_node* tmp = NULL;
    ds_doubly_linked_list_node* cur = list->head;
    while(cur != NULL){
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->size = 0;

}

void ds_doubly_linked_list_add(ds_doubly_linked_list* list, void* data){
    
    ds_doubly_linked_list_node* new_node = malloc(sizeof(ds_doubly_linked_list_node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->previous = NULL;
    
    if(list->head == NULL){ // the list is empty
        list->head = new_node;
        list->size = 1;
    } else {
        ds_doubly_linked_list_node* cur = list->head;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = new_node;
        new_node->previous = cur;
        list->size ++;
    }

}

void ds_doubly_linked_list_insert_at(ds_doubly_linked_list* list, void* data, int index){
    
    int cur_index = 0;
    
    ds_doubly_linked_list_node* n = list->head;
    
    ds_doubly_linked_list_node* new_node = malloc(sizeof(ds_doubly_linked_list_node));
    new_node->data = data;
    
    if((n == NULL) || (index <= 0)){ // insert at list head
        list->head = new_node;
        new_node->next = n;
        n->previous = new_node;
        list->size ++;
    } else if((index > 0) && (index < list->size)){ // insert at specified index
        while((cur_index<index-1) && (n!=NULL)){
            n = n->next;
            cur_index++;
        }
        if(n!=NULL){
            new_node->next = n->next;
            new_node->previous = n;
            n->next = new_node;
            if (new_node->next != NULL){
                new_node->next->previous = new_node;
            }
            list->size ++;
        } else {
            free(new_node);
        }
    } else if((index > 0) && (index >= list->size)){ // insert at list end
        while(n->next!=NULL){
            n = n->next;
        }
        if(n!=NULL){
            new_node->next = NULL;
            new_node->previous = n;
            n->next = new_node;
            list->size ++;
        } else {
            free(new_node);
        }
    } else {
        free(new_node);
    }
    
}

void* ds_doubly_linked_list_get(ds_doubly_linked_list* list, int index){
    
    ds_doubly_linked_list_node* n = NULL;
    int cur_index = 0;
    n = list->head;
    
    if (index <= 0) { // return the first element
        n = list->head;
    } else if((index > 0) && (index < list->size)){ // return the element at the given index
        while((cur_index<index) && (n!=NULL)){
            n = n->next;
            cur_index++;
        }
    }  else if(index >= list->size){ // return the last element
        while(n->next!=NULL){
            n = n->next;
        }
    }
    if (n!=NULL) {
        return n->data;
    } else {
        return NULL;
    }
    
}

void* ds_doubly_linked_list_remove(ds_doubly_linked_list* list, int index){
    
    ds_doubly_linked_list_node* n = NULL;
    void* result = NULL;
    int cur_index = 0;
    n = list->head;
    
    if((index == 0)&&(list->size>0)){
        result = n->data;
        list->head = n->next;
        list->head->previous = NULL;
        free(n);
        list->size --;
        return result;
    } else if((index > 0) && (index < list->size)){
        while((cur_index<index) && (n!=NULL)){
            n = n->next;
            cur_index++;
        }
        if(n!=NULL){
            if (n->next!=NULL) {
                n->next->previous = n->previous;
            }
            if (n->previous!=NULL) {
                n->previous->next = n->next;
            }
            free(n);
            list->size --;
            return result;
        }
    }
    return NULL;
    
}
