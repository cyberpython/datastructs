DATASTRUCTS - Simple C data structures library
==============================================

Introduction
------------

Datastructs is a C library that provides a simple implementation of:

 * a linked list
 * a doubly linked list
 * a hash table that uses linked lists to store data internally

Quickstart
----------
 
     #include <stdio.h>
     #include <datastructs.h>
     
     int main(){
     
     
         ds_linked_list* list = ds_linked_list_create();
         
         ds_linked_list_add(list, "John Doe");
         ds_linked_list_add(list, "Jane Plain");
         ds_linked_list_insert_at(list, "Jack Smith", 1);
         ds_linked_list_add(list, "Mary Merry");
         
         int i;
         for (i = 0; i < ds_linked_list_length(list); i ++){
             printf("Name: %s\n", (char *) ds_linked_list_get(list, i) );
         }
         
         ds_linked_list_delete(&list);
     
     }
     
Unit Tests
----------

To build and run the unit tests you need [check](http://check.sourceforge.net/).
Then execute:

    cd test
    ./build_tests.sh
    ./check_datastructs
     
  
