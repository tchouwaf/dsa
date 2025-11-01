#ifndef NODE_H
#define NODE_H
#include "sort.h"

typedef struct node{
    int data;
    struct node* next;
} *node_t;


//init our linked list
node_t init_node(int x);

//add an element to our list
void insert_node(node_t* head, int x);

//remove the last element of our list and return it
int remove_node(node_t* head);

//return the size of the list
int size_node(node_t head);

//print the linked list
void print_node(node_t head);

//insert an element in the linked list as first element
node_t front_insert_node(node_t head, int x);

//return 1 if we find the element x in our list, 0 in the other case
int find_node(node_t head, int x);

//reverse our linked list
node_t reverse_node(node_t head);

//sorting algorithm
node_t sort_node(node_t head);

//free our linked list
void free_node(node_t head);

#endif