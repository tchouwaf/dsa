#ifndef NODE_H
#define NODE_H

typedef struct node{
    int data;
    struct node* next;
} *node_t;


//init our linked list
node_t init_linked_list(int x);

//add an element to our list
void insert(node_t head, int x);

//remove the last element of our list and return it
int remove(node_t* head);

//return the size of the list
int size(node_t head);

//print the linked list
void print(node_t head);

//insert an element in the linked list as first element
void insert_front(node_t head, int x);

//remove the first element in our linked list
void remove_first(node_t head);

//return 1 if we find the element x in our list, 0 in the other case
int find_list(node_t head, int x);

//reverse our linked list
void reverse_list(node_t head);

//sorting algorithm
void sort_list(node_t head);

//free our linked list
void free_list(node_t head);

#endif