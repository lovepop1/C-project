#include <stdio.h>
#include <time.h>
#define N 5
#include "ProjectFunctions.h"
//This was done by Shreyas Arun

void delay(int time)

{

// this function will create a pause in the runtime process for the number of milliseconds that is given in 'time'

long pause;

clock_t time1,time2; // data_type variable_name

pause = time ; // if you want to be more accurate replace time with ' time * (CLOCKS_PER_SEC/1000); ' // i.e. 1000

time2 = time1 = clock(); // the clock() returns back the number of ticks till it has been called .

while( (time1-time2) < pause )

{

time1 = clock(); // this will initialize the current number of ticks to time1 ;

}

}
//To create patient account based on the info guven by the patient and it increases the count of patients.

void patient_account_creation(char *name, int age, char sex, int phone, int emergency_contact, char *sickness, int patient_id, int *counter)
{
    FILE *fp = fopen("account.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        return;
    }
    char tmp[50] = {0}; // initialize to null characters
    int control = 0;
    while (fscanf(fp, "%s", tmp) == 1) // limit string read to 49 characters to avoid buffer overflow
    {
        if (strcmp(tmp, name) == 0)
        {
            control = 1;
            break;
        }
    }
    fclose(fp);

    if (control) {
        printf("Patient account already exists, redirecting back to main menu...\n");
        delay(N);
    }
    else {
        FILE *fp2 = fopen("account.txt", "a+");
        if (fp2 == NULL) {
            printf("Error: Cannot open file\n");
            return;
        }
        fprintf(fp2, "%s %d %c %d %d %s %d\n", name, age, sex, phone, emergency_contact, sickness, patient_id);
        fclose(fp2);
        printf("Patient account successfully created\n");
        delay(N);
    }
}