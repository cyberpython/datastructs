#include <stdio.h>
#include <datastructs.h>

int main(){

    typedef struct user_data {
        char name[100];
        char email[100];
    } user_data;
    
    user_data a = {"John Doe", "john.doe@mail_server.com"};
    user_data b = {"Jack Smith", "jack.smith@mail_server.com"};
    user_data c = {"Jane Plain", "jane.plain@mail_server.com"};
    user_data d = {"Mary Merry", "mary.merry@mail_server.com"};
    
    user_data* data = NULL;
    
    // list creation:
    ds_linked_list* list = ds_linked_list_create();
    
    ds_linked_list_insert_at(list, &a, 0);
    ds_linked_list_add(list, &b);
    ds_linked_list_add(list, &c);
    ds_linked_list_add(list, &d);
    
    int i;
    for (i = 0; i < list->size; i ++){
        data = ds_linked_list_get(list, i);
        printf("Name: %s, Email: %s\n", data->name, data->email );
    }
    
    ds_linked_list_delete(&list);

}

