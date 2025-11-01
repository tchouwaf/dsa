#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "sort.h"

void insertion_sort(int* list, int n){
    for(int j=1; j<n; j++){
        int key = list[j];
        int i = j-1;

        while(i>0 && list[i]>key){
            list[i+1] = list[i];
            i = i-1;
        }

        list[i+1] = key;
    }
}


void merge(int* list, int p, int q, int r){
    int n_1 = q-p+1;
    int n_2 = r-q;

    int* L = malloc((n_1+1)*sizeof(int*));
    int* R = malloc((n_2+1)*sizeof(int*));

    assert(L && R);
    
    for(int i=0; i<n_1; i++){
        L[i] = list[p+i];
    }

    for(int j=0; j<n_2; j++){
        R[j] = list[q+j+1];
    }

    L[n_1] = INT_MAX;
    R[n_2] = INT_MAX;

    int i = 0;
    int j = 0;

    for(int k=p; k<r; k++){
        if(L[i] <= R[j]){
            list[k] = L[i];
            i++;
        }
        else{
            list[k] = R[j];
            j++;
        }
    }
    free(R);
    free(L);
}

void merge_sort(int *a, int p, int r) {
    if (p >= r) return;
    int q = p + (r - p) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
}