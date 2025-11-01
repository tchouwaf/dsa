#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list_t init_list(int x){
    list_t list =  malloc(sizeof(*list));
    if(!list) exit(EXIT_FAILURE);

    list->next = NULL;
    list->prev = NULL;
    list->data = x;

    return list;
}

void insert_list(list_t* Q, int x){
    list_t new_block = malloc(sizeof(*new_block));
    new_block->data = x;

    if(*Q == NULL) return;

    list_t head = *Q;

    while(head->next != NULL){
        head = head->next;
    }
    new_block->next = NULL;
    new_block->prev = head;
    head->next = new_block;
}

int remove_list(list_t* Q){
    if (*Q == NULL) return -1;

    list_t prev = NULL;
    list_t curr = *Q;

    prev = curr;
    curr = curr->next;

    *Q = curr;

    int x = prev->data;
    free(prev);

    return x;
}

int size_list(list_t Q){
    int len = 0;
    while(Q!=NULL){
        len++;
        Q = Q->next;
    }
    return len;
}

void print_list(list_t Q){
    if (Q == NULL) {
        printf("Empty\n");
        return;
    }
    while (Q != NULL) {
        printf("%d <-> ", Q->data);
        Q = Q->next;
    }
    printf("NULL\n");
}

list_t insert_first(list_t* Q, int x){
    list_t new_element = malloc(sizeof(*new_element));
    new_element->data = x;

    if(*Q==NULL){
        new_element->next = NULL;
        new_element->prev = NULL;
        return new_element;
    }

    list_t head = *Q;

    new_element->prev = NULL;
    new_element->next = head;

    head->next->prev = new_element;
    head->next = new_element;

    return new_element;
}

list_t insert_last(list_t* Q, int x){
    list_t new_element = malloc(sizeof(*new_element));
    new_element->data = x;

    if(*Q==NULL){
        new_element->next = NULL;
        new_element->prev = NULL;
        return new_element;
    }

    list_t head = *Q;

    while(head->next != NULL){
        head = head->next;
    }

    head->next = new_element;
    new_element->prev = head;

    new_element->next = NULL;

    return head;
}

list_t remove_first(list_t* Q){
    if(*Q==NULL) return NULL;

    list_t x = *Q;
    list_t head = *Q;
    head->next = head->next->next;
    head->next->prev = head;

    return x;
}

list_t remove_last(list_t* Q){
    if(*Q==NULL) return NULL;

    list_t head = *Q;
    while(head->next !=NULL){
        head = head->next;
    }

    list_t x = head->prev;
    head->prev = head->prev->prev;
    head->prev->next = NULL;

    return x;

}

int find_list(list_t Q, int x){
    if(Q==NULL) return -1;
    while (Q->data != x){
        Q = Q->next;
    }
    return Q->data;
}

list_t reverse_list(list_t Q);

list_t sort_list(list_t Q){
        int n = size_list(Q);
    if (n == 0) return NULL;

    int* list = malloc(n * sizeof(int));
    if(!list) exit(EXIT_FAILURE);
    for (int i = 0; i < n; i++) {
        list[i] = Q->data;
        Q = Q->next;
    }

    merge_sort(list, 0, n-1);

    list_t sorted = malloc(sizeof(*sorted));
    for (int i = n - 1; i >= 0; i--) {
        insert_list(&sorted, list[i]);
    }

    free(list);
    return sorted;
}

void free_list(list_t Q){
    list_t next = NULL;
    while (Q != NULL) {
        next = Q->next;
        free(Q);
        Q = next;
    }
}