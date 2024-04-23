#include <stdio.h>
#include <stdlib.h>
#define N 5
#include "ProjectFunctions.h"
//This was done by Shreyas Arun
//It deletes the patient information
int delete_patient_info(char *name, int *count) {
    FILE *fp = fopen("account.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        return 0;
    }

    // allocate arrays to store patient info
    char **name_list = malloc(*count * sizeof(char *));
    char **sickness_list = malloc(*count * sizeof(char *));
    int *age_list = malloc(*count * sizeof(int));
    char *sex_list = malloc(*count * sizeof(char));
    int *phone_list = malloc(*count * sizeof(int));
    int *emergency_contact_list = malloc(*count * sizeof(int));
    int *patient_id_list = malloc(*count * sizeof(int));
    int found = 0;
    int j = 0;
    int index_of_name;
    
    while (1) {
        name_list[j]=(char *)malloc(20*sizeof(char));
    
        sickness_list[j]=(char *)malloc(20*sizeof(char));

        if(fscanf(fp,"%s %d %c %d %d %s %d",name_list[j], &age_list[j], &sex_list[j], &phone_list[j],
                  &emergency_contact_list[j], sickness_list[j], &patient_id_list[j]) !=7)
                  {break;}
        
        if (strcmp(name_list[j], name) == 0) {
            found = 1;
            index_of_name=j;
            
        }
        j++; 
    }
    fclose(fp);

    if (found) {
        int i;
        int count=count_patients();
        printf("New count=%d\n",count_patients());
        FILE *fpw = fopen("account.txt", "w");
        if (fpw == NULL) {
            printf("Error: Cannot open file\n");
            return 0;
        }
        
        for ( i = 0; i< count; i++) {
            if(i!=index_of_name)
                fprintf(fpw, "%s %d %c %d %d %s %d\n", name_list[i], age_list[i], sex_list[i], phone_list[i],
                    emergency_contact_list[i], sickness_list[i], patient_id_list[i]);
            //free(name_list[i]);
            //free(sickness_list[i]);
        }
        printf("Patient account successfully removed. Redirecting back to main menu...\n\n");
        fclose(fpw);
        return 1;
    } else {
        printf("Patient name does not exist\n");
        return 0;
    }
    

    // free memory for arrays
    
    /*free(name_list);
    free(sickness_list);
    free(age_list);
    free(sex_list);
    free(phone_list);
    free(emergency_contact_list);
    free(sickness_level_list);*/
}