#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#define N 5


struct Patient;
void patient_account_creation(char *name, int age, char sex, int phone, int emergency_contact, char *sickness, int patient_id, int *counter);
void patient_info_display(char *name);
int count_patients();
int delete_patient_info(char *name, int *count);
void room_assign(char *name,int phone,char sex,int *counter);
typedef struct Patient_appointment Patient;
Patient* read_new_patient();
void display_slots(char *appointment_slots[],int n);
void remove_slot(char *appointment_slots[],char *slot,int *n);
void details_file(Patient *ptr,int m,FILE *f_details);
void book_appointment(Patient **head,int *n,int *m,char *appointment_slots[]);
int difference_between_dates(char *date1, char *date2);
char *deassign_room(char *name, char **price_room);
float billing(char *name);
struct Doctor;
void doctor_assign(char *name,char * sickness);
void delay(int time);



