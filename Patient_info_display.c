
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 5
#include "ProjectFunctions.h"
//This was done by Shreyas Arun


void patient_info_display(char *name)
{
    FILE *fp = fopen("account.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        return;
    }

    char tmp_name[50];
    int tmp_age, tmp_phone, tmp_emergency_contact, tmp_patient_id;
    char tmp_sex, tmp_sickness[50];

    int found = 0;

    while (fscanf(fp, "%s %d %c %d %d %s %d", tmp_name, &tmp_age, &tmp_sex, &tmp_phone, &tmp_emergency_contact, tmp_sickness, &tmp_patient_id) == 7) {
        if (strcmp(tmp_name, name) == 0) {
            found = 1;
            printf("-----------------------------\n");
            printf("Patient Name: %s\nAge: %d\nSex: %c\nPhone Number: %d\nEmergency Contact: %d\nSickness: %s\nPatient ID: %d\n", tmp_name, tmp_age, tmp_sex, tmp_phone, tmp_emergency_contact, tmp_sickness, tmp_patient_id);
            printf("-----------------------------\n");
            printf("\nEnter 0 to go to the main menu\n");

            int tmp;
            
            while(1){
                scanf("%d",&tmp);
                if(tmp==0){
                    printf("\n\n");
                    break;
                }
            }
        }
    }

    if (!found) {
        printf("Patient account for %s does not exist\n\nRedirecting you to main menu....\n\n", name);
    }

    fclose(fp);
}//Based on the name entered it displays the patient's details