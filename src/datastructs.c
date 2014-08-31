#include <stdlib.h>
#include <string.h>
#include <datastructs.h>

typedef struct ds_linked_list_node ds_linked_list_node;

typedef struct ds_doubly_linked_list_node ds_doubly_linked_list_node;

typedef struct ds_linked_hashtable_list_item ds_linked_hashtable_list_item;

typedef struct ds_linked_list_node {

    void* data;
    ds_linked_list_node * next;
    
} ds_linked_list_node ;

typedef struct ds_doubly_linked_list_node {

    void* data;
    ds_doubly_linked_list_node * previous;
    ds_doubly_linked_list_node * next;
    
} ds_doubly_linked_list_node ;

typedef struct ds_linked_hashtable_list_item {

    void* key;
    size_t key_length;
    void* value;
    
} ds_linked_hashtable_list_item;

typedef struct ds_linked_list {

    ds_linked_list_node* head;
    int size;
    
} ds_linked_list;

typedef struct ds_doubly_linked_list {

    ds_doubly_linked_list_node* head;
    int size;
    
} ds_doubly_linked_list;

typedef struct ds_linked_hashtable {
    
    int (*hash_func)(ds_linked_hashtable* hashtable, void* key, size_t key_length);
    ds_linked_list** buckets;
    int capacity;
    
} ds_linked_hashtable;

ds_linked_list* ds_linked_list_create(){

    ds_linked_list* result = malloc(sizeof(ds_linked_list));
    result->head = NULL;
    result->size = 0;
    return result;

}

int ds_linked_list_length(ds_linked_list* list){

    return list->size;

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

int ds_doubly_linked_list_length(ds_doubly_linked_list* list){

    return list->size;

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
        if(n != NULL){
            n->previous = new_node;
        }
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

int ds_default_hash_func(ds_linked_hashtable* hashtable, void* key, size_t key_length){
    size_t i;
    int sum = 0;
    for (i=0; i<key_length; i++){
        sum += (int)(((char*)key)[i]);
    }
    if (sum < 0){
        sum *= -1;
    }
    return (sum % hashtable->capacity);
}

/*
int ds_default_hash_func(ds_linked_hashtable* hashtable, void* key, size_t key_length){
    
    return (((int) key) % hashtable->capacity);
    
}
*/

ds_linked_hashtable* ds_linked_hashtable_create_with_hash_func_and_capacity(int (*hash_func)(ds_linked_hashtable* hashtable, void* key, size_t key_length), int capacity) {

    if (capacity <= 0) {
        capacity = DS_LINKED_HASHTABLE_DEFAULT_CAPACITY_C;
    }

    ds_linked_hashtable* result = malloc(sizeof(ds_linked_hashtable));
    
    result->hash_func = hash_func;
    result->capacity = capacity;
    result->buckets = malloc(sizeof(ds_linked_list) * capacity);
    memset(result->buckets, (unsigned int)NULL, sizeof(ds_linked_list) * capacity);
    
    return result;

}

ds_linked_hashtable* ds_linked_hashtable_create_with_capacity(int capacity) {

    return ds_linked_hashtable_create_with_hash_func_and_capacity(ds_default_hash_func, capacity);

}

ds_linked_hashtable* ds_linked_hashtable_create_with_hash_func(int (*hash_func)(ds_linked_hashtable* hashtable, void* key, size_t key_length)) {

    return ds_linked_hashtable_create_with_hash_func_and_capacity(hash_func, DS_LINKED_HASHTABLE_DEFAULT_CAPACITY_C);

}

ds_linked_hashtable* ds_linked_hashtable_create() {
    
    return ds_linked_hashtable_create_with_hash_func_and_capacity(ds_default_hash_func, DS_LINKED_HASHTABLE_DEFAULT_CAPACITY_C);

}

void ds_linked_hashtable_delete_bucket(ds_linked_list* bucket_contents){

    // We do not use ds_linked_list_delete() because we also
    // need to deallocate the memory used for hashtable items and their keys
    // in one loop.
    
    ds_linked_list_node* tmp = NULL;
    ds_linked_list_node* cur = bucket_contents->head;
    ds_linked_hashtable_list_item* list_item = NULL;
    while(cur != NULL){
        tmp = cur;
        cur = cur->next;
        if(tmp->data!=NULL){
            
            list_item = tmp->data;
            if(list_item->key != NULL){
                free(list_item->key);
            }
            
            free(tmp->data);
        }
        free(tmp);
    }
    bucket_contents->size = 0;
    
}

void ds_linked_hashtable_clear(ds_linked_hashtable* hashtable) {

    int i;
    for (i=0; i<(hashtable->capacity); i++) {
        if ( (hashtable->buckets)[i] != NULL) { // the bucket contains a linked list
            ds_linked_hashtable_delete_bucket( (hashtable->buckets)[i] ); // deallocates the nodes and node data of the list in the bucket
            free( (hashtable->buckets)[i] ); // deallocates the list
        }
    }
    memset(hashtable->buckets, (unsigned int)NULL, sizeof(ds_linked_list) * hashtable->capacity);

}

void ds_linked_hashtable_delete(ds_linked_hashtable** hashtable_ptr) {

    ds_linked_hashtable* hashtable = (*hashtable_ptr);
    ds_linked_hashtable_clear(hashtable);
    free((*hashtable_ptr)->buckets);
    free(*hashtable_ptr);
    (*hashtable_ptr) = NULL;

}

int ds_linked_hashtable_get_bucket_item_index(ds_linked_list* bucket_list, void* key, size_t key_length) {
    
    int i;
    ds_linked_hashtable_list_item* list_item = NULL;
    for(i=0; i<ds_linked_list_length(bucket_list); i++) {
        list_item = ds_linked_list_get(bucket_list, i);
        if ( ( key_length == list_item->key_length ) && ( memcmp( key, list_item->key, key_length )  == 0 ) ) {
            return i;
        }
    }
    
    return -1;
    
}


ds_linked_hashtable_list_item* ds_linked_hashtable_get_bucket_item(ds_linked_list* bucket_list, void* key, size_t key_length) {
    
    int i;
    ds_linked_hashtable_list_item* list_item = NULL;
    for(i=0; i<ds_linked_list_length(bucket_list); i++) {
        list_item = ds_linked_list_get(bucket_list, i);
        if ( ( key_length == list_item->key_length ) && ( memcmp( key, list_item->key, key_length )  == 0 ) ) {
            return list_item;
        }
    }
    
    return NULL;
    
}

void ds_linked_hashtable_put(ds_linked_hashtable* hashtable, void* key, size_t key_length, void* value) {

    if (value == NULL){ // NULL is not inserted in the hashtable.
        return;
    }

    int hash = hashtable->hash_func(hashtable, key, key_length);
    
    if ((hashtable->buckets)[hash] == NULL) {
        (hashtable->buckets)[hash] = ds_linked_list_create();
    }
    
    ds_linked_hashtable_list_item* item = ds_linked_hashtable_get_bucket_item((hashtable->buckets)[hash], key, key_length);
    
    if (item != NULL){
        
        item->value = value;
        
    } else {
    
        item = malloc(sizeof(ds_linked_hashtable_list_item));
        item->key = malloc(key_length);
        memcpy(item->key, key, key_length);
        item->key_length = key_length;
        item->value = value;
        ds_linked_list_add((hashtable->buckets)[hash], item);
    }

}

void* ds_linked_hashtable_get(ds_linked_hashtable* hashtable, void* key, size_t key_length) {

    if ((key==NULL) || (key_length == 0)){
        return NULL;
    }

    int hash = hashtable->hash_func(hashtable, key, key_length);
    
    if ((hashtable->buckets)[hash] == NULL) {
        return NULL;
    }
    
    ds_linked_hashtable_list_item* item = ds_linked_hashtable_get_bucket_item((hashtable->buckets)[hash], key, key_length);
    
    if (item != NULL){
        
        return item->value;
        
    } else {
    
        return NULL;
    }

}

void* ds_linked_hashtable_remove(ds_linked_hashtable* hashtable, void* key, size_t key_length) {

    if ((key==NULL) || (key_length == 0)){
        return NULL;
    }

    int hash = hashtable->hash_func(hashtable, key, key_length);
    
    if ((hashtable->buckets)[hash] == NULL) {
        return NULL;
    }
    
    int index = ds_linked_hashtable_get_bucket_item_index((hashtable->buckets)[hash], key, key_length);
    
    if (index != -1){
    
        ds_linked_hashtable_list_item* item = ds_linked_list_remove( (hashtable->buckets)[hash], index );
        
        if(item!=NULL){
            
            if(item->key != NULL){
                free(item->key);
            }
            
            void* result = item->value;
            
            free(item);
            
            return result;
            
        } else {
            
            return NULL;
            
        }
        
    } else {
    
        return NULL;
    }

}

ds_linked_list* ds_linked_hashtable_keys(ds_linked_hashtable* hashtable) {

    ds_linked_list* result = ds_linked_list_create();
    
    int i;
    int j;
    ds_linked_hashtable_list_item* list_item;
    ds_linked_hashtable_key* item;
    
    for (i=0; i<(hashtable->capacity); i++) {
        if( (hashtable->buckets)[i] != NULL ){
            for(j=0; j<ds_linked_list_length( (hashtable->buckets)[i] ); j++){
                list_item = ds_linked_list_get( (hashtable->buckets)[i], j);
                item = malloc(sizeof(ds_linked_hashtable_key));
                item->key = list_item->key;
                item->key_length = list_item->key_length;
                ds_linked_list_add(result, item);
            }
        }
    }
    
    return result;

}

void ds_linked_hashtable_keys_delete(ds_linked_list** keys_list_ptr) {

    ds_linked_list_node* tmp = NULL;
    ds_linked_list_node* cur = (*keys_list_ptr)->head;
    while(cur != NULL){
        tmp = cur;
        cur = cur->next;
        if(tmp->data != NULL){
            free(tmp->data);
        }
        free(tmp);
    }
    (*keys_list_ptr)->size = 0;
    free(*keys_list_ptr);
    *keys_list_ptr = NULL;
}


