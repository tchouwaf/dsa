#include <stdio.h>
#include <stdlib.h>
#include "../c/algorithm/sort.h"


int main(void){

    FILE* school_stat = fopen("../data_set/archive/StudentsPerformance.csv", "r+");
    if (school_stat==NULL){
        printf("Error: could not open the file");
        exit(-1);
    }
    printf("File opened !");

    return 0;
}