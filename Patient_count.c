#include <stdio.h>
#include <time.h>
#define N 5
#include "ProjectFunctions.h"

//This was done by Shreyas Arun
int count_patients(){
    int count=0;
    FILE *fp = fopen("account.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        return count;
    }

    // allocate arrays to store patient info
    char **name_list = malloc(50 * sizeof(char *));
    char **sickness_list = malloc(50 * sizeof(char *));
    int *age_list = malloc(50 * sizeof(int));
    char *sex_list = malloc(50 * sizeof(char));
    int *phone_list = malloc(50 * sizeof(int));
    int *emergency_contact_list = malloc(50 * sizeof(int));
    int *patient_id_list = malloc(50 * sizeof(int));    
    int j=0;
    while (1) {
        name_list[j]=(char *)malloc(20*sizeof(char));
    
        sickness_list[j]=(char *)malloc(20*sizeof(char));

        if(fscanf(fp,"%s %d %c %d %d %s %d",name_list[j], &age_list[j], &sex_list[j], &phone_list[j],
                  &emergency_contact_list[j], sickness_list[j], &patient_id_list[j]) !=7)
                  break;
       count+=1;
       //printf("count=%d in function \n ",count);
    }
    return count;
}//This function is used in patient acc creation and deletion