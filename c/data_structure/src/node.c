#include <stdio.h>
#include "node.h"
#include <stdlib.h>

node_t init_node(int x){

    node_t head = malloc(sizeof(*head));
    if(!head) exit(EXIT_FAILURE);
    head->data = x;
    head->next = NULL;

    return head;
}

void insert_node(node_t *head, int x) {
    node_t new_node = malloc(sizeof(*new_node));
    if(!new_node) exit(EXIT_FAILURE);
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


int remove_node(node_t *head) {
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

int size_node(node_t head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void print_node(node_t head) {
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


node_t front_insert_node(node_t head, int x){
    node_t new_head = malloc(sizeof(*new_head));
    if (!new_head) exit(EXIT_FAILURE);

    new_head->data = x;
    if(head==NULL){
        new_head->next = NULL;
        return new_head;
    }

    new_head->next = head;
    return new_head;
}


int find_node(node_t head, int x){
    if (head == NULL) return 0;
    while (head != NULL) {
        if (head->data == x)
            return 1;
        head = head->next;
    }
    return 0;
}

node_t reverse_node(node_t head) {
    node_t prev = NULL, next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}


node_t sort_node(node_t head) {
    int n = size_node(head);
    if (n == 0) return NULL;

    int* list = malloc(n * sizeof(int));
    if(!list) exit(EXIT_FAILURE);
    node_t tmp = head;
    for (int i = 0; i < n; i++) {
        list[i] = tmp->data;
        tmp = tmp->next;
    }

    merge_sort(list, 0, n-1);

    node_t sorted = malloc(sizeof(*sorted));
    for (int i = n - 1; i >= 0; i--) {
        insert_node(&sorted, list[i]);
    }

    free(list);
    return sorted;
}

void free_node(node_t head) {
    node_t next = NULL;
    while (head != NULL) {
        next = head->next;
        free(head);
        head = next;
    }
}