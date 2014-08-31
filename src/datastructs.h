
#ifndef __DS_DATASTUCTS_H__
#define __DS_DATASTUCTS_H__


/** \mainpage DATASTRUCTS - Simple C data structures library
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Download
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
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

void ds_linked_hashtable_delete(ds_linked_hashtable** hashtable_ptr);

void ds_linked_hashtable_clear(ds_linked_hashtable* hashtable);

// WARNING: when a value is overwritten, if there are no other pointers to the 
// previous value then it will not be possible to reclaim the memory allocated 
// for that value (if it was dynamically allocated) anymore.
void ds_linked_hashtable_put(ds_linked_hashtable* hashtable, void* key, size_t key_length, void* value);

void* ds_linked_hashtable_get(ds_linked_hashtable* hashtable, void* key, size_t key_length);

void* ds_linked_hashtable_remove(ds_linked_hashtable* hashtable, void* key, size_t key_length);

ds_linked_list* ds_linked_hashtable_keys(ds_linked_hashtable* hashtable);

void ds_linked_hashtable_keys_delete(ds_linked_list** keys_list_ptr);

#endif

