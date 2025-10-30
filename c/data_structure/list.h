#ifndef LIST_H
#define LIST_H
#include "../algorithm/sort.h"

typedef struct list{
    int data;
    struct list* next;
    struct list* prev;
} *list_t;


//init our double linked list
list_t init_list(int x);

//add an element to our list
void insert_list(list_t* Q, int x);

//remove the last element of our double list and return it
int remove_list(list_t* Q);

//return the size of the double list
int size_list(list_t Q);

//print the double linked list
void print_list(list_t Q);

//insert an element in the double linked list as first element
list_t insert_first(list_t* Q, int x);

//insert x in the last position of our double list
list_t insert_last(list_t* Q, int x);

//remove the first element of our double list
list_t remove_first(list_t* Q);

//remove the last element of our double list
list_t remove_last(list_t* Q);

//return 1 if we find the element x in our double list, 0 in the other case
int find_list(list_t Q, int x);

//reverse our double linked list
list_t reverse_list(list_t Q);

//sorting algorithm
list_t sort_list(list_t Q);

//free our double linked list
void free_list(list_t Q);

#endif