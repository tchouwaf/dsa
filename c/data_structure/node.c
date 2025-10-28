#include <stdio.h>
#include "node.h"
#include <stdlib.h>

node_t init_linked_list(int x){

    node_t head = (node_t*)malloc(sizeof(node_t));
    head->data = x;
    head->next = NULL;

    return head;
}

void insert(node_t *head, int x) {
    node_t new_node = (node_t*)(sizeof(node_t));
    new_node->data = x;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node_t curr = *head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = new_node;
}


int remove(node_t *head) {
    if (*head == NULL) return -1;

    node_t prev = NULL;
    node_t curr = *head;

    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    int val = curr->data;

    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }

    free(curr);
    return val;
}

int size(node_t head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void print(node_t head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


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