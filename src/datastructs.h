
#ifndef __DS_DATASTUCTS_H__
#define __DS_DATASTUCTS_H__


/** \mainpage DATASTRUCTS - Simple C data structures library
 *
 * \section intro_sec Introduction
 *
 * Datastructs is a C library that provides a simple implementation of:
 *
 * * a linked list
 * * a doubly linked list
 * * a hash table that uses linked lists to store data internally
 *
 * \section quickstart_sec Quickstart
 * 
 *     #include <stdio.h>
 *     #include <datastructs.h>
 *     
 *     int main(){
 *     
 *     
 *         ds_linked_list* list = ds_linked_list_create();
 *         
 *         ds_linked_list_add(list, "John Doe");
 *         ds_linked_list_add(list, "Jane Plain");
 *         ds_linked_list_insert_at(list, "Jack Smith", 1);
 *         ds_linked_list_add(list, "Mary Merry");
 *         
 *         int i;
 *         for (i = 0; i < ds_linked_list_length(list); i ++){
 *             printf("Name: %s\n", (char *) ds_linked_list_get(list, i) );
 *         }
 *         
 *         ds_linked_list_delete(&list);
 *     
 *     }
 *     
 * \section unittests_sec Unit Tests
 * To build and run the unit tests you need [check](http://check.sourceforge.net/).
 * Then execute:
 *
 *     cd test
 *     ./build_tests.sh
 *     ./check_datastructs
 *     
 *    
 */
 
/** The default capacity (bucket count) for linked hashtables. */
#define DS_LINKED_HASHTABLE_DEFAULT_CAPACITY_C 10000

/** Structure for linked lists. */
typedef struct ds_linked_list ds_linked_list;

/** Structure for doubly linked lists. */
typedef struct ds_doubly_linked_list ds_doubly_linked_list;

/** Structure for linked hashtables. */
typedef struct ds_linked_hashtable ds_linked_hashtable;

/** 
 * Structure for linked hashtable keys.
 *
 * The {@link ds_linked_hashtable_keys} function returns the keys of a linked hashtable 
 * a {@link ds_linked_list} with each item being of this struct type.
 */
typedef struct ds_linked_hashtable_key {

    void* key;
    size_t key_length;
    
} ds_linked_hashtable_key;

/**
 * Creates a linked list and returns a pointer to the newly allocated structure.
 *
 * The size of the created list is 0 and its head is pointing to NULL.
 *
 * **IMPORTANT:** Do NOT deallocate the memory pointed to by the pointer returned
 *              by this function manually by calling `free` on it. That would 
 *              result in memort leaks since memory for list's nodes would not 
 *              be deallocated. 
 *              To safely free all the memory used by a list call the 
 *              `ds_linked_list_delete()` function.
 *
 * @return A pointer to the newly created list.
 */
ds_linked_list* ds_linked_list_create();

/**
 * Returns the length of the given list.
 *
 * @param list The list.
 *
 * @return The number of items in the given list. 
 */
int ds_linked_list_length(ds_linked_list* list);

/**
 * Deallocates the memory used by a linked list and all its internal nodes.
 *
 * **IMPORTANT:** The memory for node data is not deallocated - it is up to the 
 *              caller to manage the memory for the actual list node data.
 *
 * The list pointer (*list_ptr) should point to after this function returns.
 *
 * @param list_ptr A pointer to the list's pointer.
 */
void ds_linked_list_delete(ds_linked_list** list_ptr);

/**
 * Deallocates the memory used by the list's internal nodes and sets its size 
 * to 0.
 *
 * **IMPORTANT:** The memory for node data is not deallocated - it is up to the 
 *              caller to manage the memory for the actual list node data.
 *
 * The list's head should point to NULL after this function returns.
 *
 * @param list A pointer to the list.
 */
void ds_linked_list_clear(ds_linked_list* list);

/**
 * Appends an item to the end of the list.
 * 
 * @param list A pointer to the list.
 * @param item A pointer to the item (node's data) to be added to the list.
 */
void ds_linked_list_add(ds_linked_list* list, void* item);

/**
 * Inserts an item to the list at the given index.
 * 
 * @param list A pointer to the list.
 * @param item A pointer to the item (node's data) to be added to the list.
 * @param index The index at which the item should be inserted.
 *              If index <= 0, the item is inserted at the beginning of the list.
 *              If index >= size, the item is inserted at the end of the list.
 */
void ds_linked_list_insert_at(ds_linked_list* list, void* item, int index);

/**
 * Returns the list item at the given index.
 * 
 * @param list A pointer to the list.
 * @param index The index of the item to be returned.
 *              If index <= 0, the first item of the list is returned.
 *              If index >= size, the last item of the list is returned.
 *
 * @return A pointer to the item (node's data) at the given index.
 */
void* ds_linked_list_get(ds_linked_list* list, int index);

/**
 * Removes the list item at the given index from the list.
 * 
 * @param list A pointer to the list.
 * @param index The index of the item to be removed.
 *              If  index < 0 or index >= size the list is not modified.
 *
 * @return A pointer to the removed node's data or NULL if no list node was removed.
 */
void* ds_linked_list_remove(ds_linked_list* list, int index);

/**
 * Creates a linked list and returns a pointer to the newly allocated structure.
 *
 * The size of the created list is 0 and its head is pointing to NULL.
 *
 * **IMPORTANT:** Do NOT deallocate the memory pointed to by the pointer returned
 *              by this function manually by calling `free` on it. That would 
 *              result in memort leaks since memory for list's nodes would not 
 *              be deallocated. 
 *              To safely free all the memory used by a list call the 
 *              `ds_doubly_linked_list_delete()` function.
 *
 * @return A pointer to the newly created list.
 */
ds_doubly_linked_list* ds_doubly_linked_list_create();

/**
 * Returns the length of the given list.
 *
 * @param list The list.
 *
 * @return The number of items in the given list. 
 */
int ds_doubly_linked_list_length(ds_doubly_linked_list* list);


/**
 * Deallocates the memory used by a linked list and all its internal nodes.
 *
 * **IMPORTANT:** The memory for node data is not deallocated - it is up to the 
 *              caller to manage the memory for the actual list node data.
 *
 * The list pointer (*list_ptr) should point to NULL after this function returns.
 *
 * @param list_ptr A pointer to the list's pointer.
 */
void ds_doubly_linked_list_delete(ds_doubly_linked_list** list);

/**
 * Deallocates the memory used by the list's internal nodes and sets its size 
 * to 0.
 *
 * **IMPORTANT:** The memory for node data is not deallocated - it is up to the 
 *              caller to manage the memory for the actual list node data.
 *
 * The list's head should point to NULL after this function returns.
 *
 * @param list A pointer to the list.
 */
void ds_doubly_linked_list_clear(ds_doubly_linked_list* list);

/**
 * Appends an item to the end of the list.
 * 
 * @param list A pointer to the list.
 * @param item A pointer to the item (node's data) to be added to the list.
 */
void ds_doubly_linked_list_add(ds_doubly_linked_list* list, void* data);

/**
 * Inserts an item to the list at the given index.
 * 
 * @param list A pointer to the list.
 * @param item A pointer to the item (node's data) to be added to the list.
 * @param index The index at which the item should be inserted.
 *              If index <= 0, the item is inserted at the beginning of the list.
 *              If index >= size, the item is inserted at the end of the list.
 */
void ds_doubly_linked_list_insert_at(ds_doubly_linked_list* list, void* data, int index);

/**
 * Returns the list item at the given index.
 * 
 * @param list A pointer to the list.
 * @param index The index of the item to be returned.
 *              If index <= 0, the first item of the list is returned.
 *              If index >= size, the last item of the list is returned.
 *
 * @return A pointer to the item (node's data) at the given index.
 */
void* ds_doubly_linked_list_get(ds_doubly_linked_list* list, int index);

/**
 * Removes the list item at the given index from the list.
 * 
 * @param list A pointer to the list.
 * @param index The index of the item to be removed.
 *              If  index < 0 or index >= size the list is not modified.
 *
 * @return A pointer to the removed node's data or NULL if no list node was removed.
 */
void* ds_doubly_linked_list_remove(ds_doubly_linked_list* list, int index);

/**
 * Creates a hashtable that uses linked lists to resolve hashing conflicts.
 *
 * The hashtable has the capacity defined by {@link DS_LINKED_HASHTABLE_DEFAULT_CAPACITY_C}
 * and uses the default hashing function.
 *
 * The default hashing function treats input as a byte array and 
 * returns the modulo of the sum of the array's (signed) byte values and the 
 * hashtable's capacity.
 *
 * The newly allocated hashtable should be deallocated using the {@link ds_linked_hashtable_delete} 
 * function.
 *
 * @return A pointer to the new hashtable.
 */
ds_linked_hashtable* ds_linked_hashtable_create();

/**
 * Creates a hashtable that uses linked lists to resolve hashing conflicts.
 *
 * The hashtable has the given capacity and uses the default hashing function.
 *
 * The default hashing function treats input as a byte array and 
 * returns the modulo of the sum of the array's (signed) byte values and the 
 * hashtable's capacity.
 *
 * The newly allocated hashtable should be deallocated using the {@link ds_linked_hashtable_delete} 
 * function.
 *
 * @param capacity The number of buckets in the hashtable.
 *
 * @return A pointer to the new hashtable.
 */
ds_linked_hashtable* ds_linked_hashtable_create_with_capacity(int capacity);

/**
 * Creates a hashtable that uses linked lists to resolve hashing conflicts.
 *
 * The hashtable has the capacity defined by {@link DS_LINKED_HASHTABLE_DEFAULT_CAPACITY_C}
 * and uses the given hashing function.
 *
 * The newly allocated hashtable should be deallocated using the {@link ds_linked_hashtable_delete} 
 * function.
 *
 * @param hash_func The hashing function to be used to compute the correct bucket index for each key.
 *
 * @return A pointer to the new hashtable.
 */
ds_linked_hashtable* ds_linked_hashtable_create_with_hash_func(int (*hash_func)(ds_linked_hashtable* hashtable, void* key, size_t key_length));

/**
 * Creates a hashtable that uses linked lists to resolve hashing conflicts.
 *
 * The hashtable has the given capacity and uses the given hashing function.
 *
 * The newly allocated hashtable should be deallocated using the {@link ds_linked_hashtable_delete} 
 * function.
 *
 * @param hash_func The hashing function to be used to compute the correct bucket index for each key.
 * @param capacity The number of buckets in the hashtable.
 *
 * @return A pointer to the new hashtable.
 */
ds_linked_hashtable* ds_linked_hashtable_create_with_hash_func_and_capacity(int (*hash_func)(ds_linked_hashtable* hashtable, void* key, size_t key_length), int capacity);

/**
 * Deallocates the memory used by the hashtable.
 *
 * **IMPORTANT:** The memory for the actual data is not deallocated - it is up to the 
 *              caller to manage the memory for the actual hashtable data.
 *
 * @param hashtable_ptr A pointer to the hashtable.
 */
void ds_linked_hashtable_delete(ds_linked_hashtable** hashtable_ptr);

/**
 * Deallocates the memory used by the hashtable's buckets.
 *
 * **IMPORTANT:** The memory for the actual data is not deallocated - it is up to the 
 *              caller to manage the memory for the actual hashtable data.
 *
 * @param hashtable A pointer to the hashtable.
 */
void ds_linked_hashtable_clear(ds_linked_hashtable* hashtable);

/**
 * Puts a key-value pair into the hashtable.
 *
 * If a value is already mapped to the given key, it is overwritten.
 * NOTE: When a value gets overwritten, if there are no other pointers to the 
 * it then it will not be possible to reclaim the memory allocated for it 
 * (if it was dynamically allocated).
 *
 * @param hashtable A pointer to the hashtable.
 * @param key A pointer to the key.
 * @param key_length The key's length.
 * @param value A pointer to value to be inserted to the hashtable.
 */
void ds_linked_hashtable_put(ds_linked_hashtable* hashtable, void* key, size_t key_length, void* value);

/**
 * Returns the hashtable value for the given key.
 *
 * @param hashtable A pointer to the hashtable.
 * @param key A pointer to the key.
 * @param key_length The key's length.
 *
 * @return The hashtable value for the given key.
 *         If the key is NULL or does not exist in the hashtable then NULL is returned.
 */
void* ds_linked_hashtable_get(ds_linked_hashtable* hashtable, void* key, size_t key_length);

/**
 * Removes the key-value pair from the hashtable for the given key.
 *
 * @param hashtable A pointer to the hashtable.
 * @param key A pointer to the key.
 * @param key_length The key's length.
 *
 * @return The hashtable value for the given key.
 *         If the key is NULL or does not exist in the hashtable then NULL is returned.
 */
void* ds_linked_hashtable_remove(ds_linked_hashtable* hashtable, void* key, size_t key_length);

/**
 * Returns the hashtable keys as a linked list.
 *
 * A new linked list is constructed with each call.
 * The list should be deleted using the {@link ds_linked_hashtable_keys_delete}
 * function.
 *
 * @param hashtable A pointer to the hashtable.
 *
 * @return A pointer to the newly created list of hashtable keys.
 */
ds_linked_list* ds_linked_hashtable_keys(ds_linked_hashtable* hashtable);

/**
 * Deletes the given linked list of hashtable keys.
 *
 * @param keys_list_ptr A pointer to the list of keys.
 */
void ds_linked_hashtable_keys_delete(ds_linked_list** keys_list_ptr);


#endif

