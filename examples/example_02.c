#include <stdio.h>
#include <string.h>
#include <datastructs.h>

int main(){

    ds_linked_hashtable* contacts_list = ds_linked_hashtable_create();
    
    ds_linked_hashtable_put(contacts_list, "John Doe", strlen("John Doe"), "john.doe@mail_server.com");
    ds_linked_hashtable_put(contacts_list, "Jack Smith", strlen("Jack Smith"), "jack.smith@mail_server.com");
    ds_linked_hashtable_put(contacts_list, "Jane Plain", strlen("Jane Plain"), "jane.plain@mail_server.com");
    ds_linked_hashtable_put(contacts_list, "Mary Merry", strlen("Mary Merry"), "mary.merry@mail_server.com");
    
    ds_linked_list* keys = ds_linked_hashtable_keys(contacts_list);
    
    int i;
    for(i=0; i<ds_linked_list_length(keys); i++){
        ds_linked_hashtable_keys_list_item* key_entry = ds_linked_list_get(keys, i);
        printf("Name: %s, Email: %s\n", (char*) key_entry->key, (char*) ds_linked_hashtable_get(contacts_list, key_entry->key, key_entry->key_length) );
    }
    
    ds_linked_hashtable_keys_delete(&keys);
    
    char* removed_email = (char*) ds_linked_hashtable_remove(contacts_list, "Jane Plain", strlen("Jane Plain"));
    
    printf("\n*** Removed 'Jane Plain (%s)' from the contact list.\n\n", removed_email);
    
    keys = ds_linked_hashtable_keys(contacts_list);
    
    for(i=0; i<ds_linked_list_length(keys); i++){
        ds_linked_hashtable_keys_list_item* key_entry = ds_linked_list_get(keys, i);
        printf("Name: %s, Email: %s\n", (char*) key_entry->key, (char*) ds_linked_hashtable_get(contacts_list, key_entry->key, key_entry->key_length) );
    }
    
    ds_linked_hashtable_keys_delete(&keys);
    
    
    
    ds_linked_hashtable_delete(&contacts_list);

}

