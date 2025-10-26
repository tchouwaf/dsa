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
    
    for(int i=0; i<n_1; i++){
        L[i] = list[p+i-1];
    }

    for(int j=0; j<n_2; j++){
        R[j] = list[q+j];
    }

    L[n_1+1] = INT_MAX;
    R[n_2+1] = INT_MAX;

    int i = 1;
    int j = 1;

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

void merge_sort(int* list, int p, int r, int n){

    if(n==0){
        return NULL;
    }

    assert(p<r);

    int q = floor((p+r)/2);

    merge_sort(list, p, q, r);
    merge_sort(list, q, r, n);

    merge(list, p, q, r);
}