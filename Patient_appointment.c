#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include "ProjectFunctions.h"
//This file was made by Nikhilesh

typedef struct Patient_appointment {
  char name[50];
  int age;
  char sex[7];
  char phone[20];
  char doctor[20];
  char problem[10];
  char appointment_time[4];
  struct Patient_appointment *next;    //creates a linked list structure of the patient details
}Patient;
Patient* read_new_patient(){
	Patient* temp = malloc(sizeof(Patient));
	scanf("%s %d %s %s",temp->name,&temp->age,temp->sex,temp->phone);   //creates a new node to the structure
	temp->next = NULL;
	return temp;
}

void display_slots(char *appointment_slots[],int n){
    printf("Here are the available slots:\n");
    for(int i=0;i<n;i++)
        printf("%s ",appointment_slots[i]);  //shows the available appointment slots
    printf("\n");
}

void remove_slot(char *appointment_slots[],char *slot,int *n){
    for(int i=0;i<(*n);i++){
        if (strcmp(slot,appointment_slots[i])==0){
            for(int j=i;j<(*n)-1;j++){
                appointment_slots[j]=appointment_slots[j+1];         //removes the booked appointment slot
            }
            (*n)=(*n)-1;                   // effectively decreases the size of the array
        }
    }
}
void details_file(Patient *ptr,int m,FILE *f_details){
    fprintf(f_details,"--------Appointment Form--------\n");
	fprintf(f_details,"Name of the Patient: %s\n",ptr->name);     //printing the details in a file
    fprintf(f_details,"Age: %d\n",ptr->age);
    fprintf(f_details,"Sex: %s\n",ptr->sex);
    fprintf(f_details,"Phone No.: %s\n",ptr->phone);
    fprintf(f_details,"Location of the Problem: %s\n",ptr->problem);
    fprintf(f_details,"Appointment Time: %s\n",ptr->appointment_time);
    
}
void book_appointment(Patient **head,int *n,int *m,char *appointment_slots[]){
    char i,slot[10];
    int x;
    (*m)++;
    if(*n==0){         //all slots are booked
        printf("There are no appointment slots available.\nPlease Try Again Later.\n");
        printf("Redirecting Back to Main Menu...\n");
        return;
    }
    printf("Would you like to make an appointment(Y/N)?\n");
    scanf("%s",&i);
    if((i=='Y') || (i=='y')){
        Patient *ptr=malloc(sizeof(Patient));
        printf("Enter the patient's name,age,sex and phone no.\n");
            int flag=0;
            char temp[50]={0};
            ptr=read_new_patient();
            FILE *p_names=fopen("p_names.txt","a+");   //checks the file to see if the patient already made an appointment
            while (fscanf(p_names, "%s", temp) == 1){
                if (strcmp(temp,ptr->name)==0)
                    flag=1;        //flag value 1 means it found the patient name already exists
                if(flag==1){
                    printf("Patient has already made an appointment.\n");
                    printf("Returning back to main menu.\n");
                    return;
                }
            }
            fprintf(p_names,"%s\n",ptr->name);          //if it's a new patient then it adds the name to the file for future checks
            fclose(p_names);

            printf("If your problem is related to \nHead(Type 1)\nBody(Type 2)\nArms(Type 3)\nLegs(Type 4)\n");
            scanf("%d",&x);
            switch(x){                //depending on x, the problem variable gets assigned to different values
                case 1:
                    strcpy(ptr->problem,"Head");
                    break;
                case 2:
                    strcpy(ptr->problem,"Body");
                    break;
                case 3:
                    strcpy(ptr->problem,"Arms");
                    break;
                case 4:
                    strcpy(ptr->problem,"Legs");
                    break;
            }

            while(1){
            display_slots(appointment_slots,*n);        //display all the available slots
                int flag1=0;
                printf("Pick a slot\n");
                scanf("%s",slot);
                for(int i=0;i<*n;i++){
                    if (strcmp(slot,appointment_slots[i])==0){
                        flag1=1;       //flag value 1 if the patient picks an invalid slot
                        break;
                    }
                }
                if (flag1==0)
                    printf("Slot is not available.Please pick an available slot.\n");
                if(flag1==1)
                    break;
            }
            strcpy(ptr->appointment_time,slot);          //assignes the slot to appointment_time member of the structure
            remove_slot(appointment_slots,slot,n);          //removes the slot for future patient registrations
            printf("Appointment Booked successfully.\n");

            if(*head==NULL){
                *head=ptr;      //makes the node if head if its's the first entry
            }else{
                Patient *temp=*head;
                while(temp->next!=NULL)
                    temp=temp->next;
                temp->next=ptr;         //adds the node to the end of linked list
            }
            
            
        FILE *f_details=fopen("Appointment_Form.txt","w"); 
        details_file(ptr,*m,f_details);             //prints the details into a new file
        fclose(f_details);   //closes the appointment form file
        printf("Your appointment details have been printed into a new file.\n");
        printf("Returning back to main menu...\n");
        return;
    }
    
    else{
        printf("Redirecting back to main menu...\n");
        return;
    }
}
	
