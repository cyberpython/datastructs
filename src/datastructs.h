
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

/**
 * Node structure for linked lists. 
 *
 * Users do not need to worry about this struct since it only used internally
 * by the library.
 */
typedef struct ds_linked_list_node ds_linked_list_node;

/**
 * Node structure for doubly linked lists. 
 *
 * Users do not need to worry about this struct since it only used internally
 * by the library.
 */
typedef struct ds_doubly_linked_list_node ds_doubly_linked_list_node;

/**
 * Structure for linked lists. 
 *
 */
typedef struct {

    /** Pointer to the list's first node. */
    ds_linked_list_node* head;
    
    /** Integer variable containing the size (number of nodes) of the list. */
    int size;
    
} ds_linked_list;

typedef struct {
    
    /** Pointer to the list's first node. */
    ds_doubly_linked_list_node* head;
    
    /** Integer variable containing the size (number of nodes) of the list. */
    int size;
} ds_doubly_linked_list;

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

// TODO: array_list

// TODO: array_hash_map

// TODO: linked_hash_map

#endif

