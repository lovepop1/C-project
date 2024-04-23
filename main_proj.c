#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#define N 5
#include "ProjectFunctions.h"


//This was done by nishal
struct Patient {
  char name[50];
  int age;
  char sex;
  int phone;
  int emergency_contact;
  char sickness[50];
  int patient_id;
};//to create the structure patient
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
struct Doctor{
    char name[50];
    char field[50];
    int availability;
};

int main(){
    int app_n=6,app_m=1;
    Patient *head=NULL;
    char *appointment_slots[10]={"10am","11am","3pm","4pm","5pm","6pm"};
    FILE *fp = fopen("account.txt", "a");
    fclose(fp);
    struct Patient *p;
    int n;
    p=(struct Patient *)malloc(sizeof(struct Patient));
        FILE *rd = fopen("ROOMCOUNT.txt","a");
        fseek(rd,0,SEEK_END);
        if(ftell(rd)==0){
            fprintf(rd,"%d %d %d",20,40,70);
        }
        fclose(rd);
    int cnt=0;
    int *counter=&cnt;

    while(1){
    count_patients(counter);
    printf("Type 1 for adding patient\nType 2 to display patient info\nType 3 to assign room to patient\nType 4 to delete patient info and checkout\nType 5 for booking appointment\n");
    scanf("%d",&n);
    
    if(n==1){
        int a,b,c,d;
        char e[20];
        char g[30];
        char f;
        printf("Enter the patient in the order Patient name , age ,sex , phone , emergency contact , patient id\n");
        scanf("%s %d %c %d %d %d",e,&a,&f,&b,&c,&d);
        printf("Enter the name of the condition the patient needs to be treated for \n1.Diabetes\n2.Flu\n3.Kidney\n4.Skin\n5.Eyesight\n6.Covid\n7.Cancer\n8.Arthritis\n9.UTI\n10.Heart\n");
        scanf("%s",g);
        strcpy(p->name,e);
        strcpy(p->sickness,g);
        p->age=a;
        p->sex=f;
        p->phone=b;
        p->emergency_contact=c;
        p->patient_id=d;
        
        patient_account_creation(p->name,p->age,p->sex,p->phone,p->emergency_contact,p->sickness,p->patient_id,counter);
        doctor_assign(p->name,p->sickness);
        printf("\n\nRedirecting back to main menu\n");
    }
    if(n==2){
        printf("Enter the name of the patient whose info needs to be displayed\n");
        char temp[50];
        scanf("%s",temp);
        patient_info_display(temp);
        
    }
    if(n==3){
        printf("Enter the details of the patient the room needs to be assigned in the order name , sex , phone number\n");
        char name[50];
        char sex;
        int phone;
        scanf("%s %c %d",name,&sex,&phone);
        room_assign(name,phone,sex,counter);
        printf("Room successfully assigned\n");
    }
    if(n==4){
        printf("Enter the name of the patient whose info needs to be deleted\n");
        char temp[50];
        scanf("%s",temp);
        if(delete_patient_info(temp,counter)==1){
        int n=billing(temp);
        if(n==-1)
        printf("The patient was never assigned a room please try again\n");
        else{
            printf("The cost is $%d\n",n);
            while(1)
            {
                int temp;
                printf("Please Enter 0 if the patient paid the full amount\n");
                scanf("%d",&temp);
                if(temp==0) break;
            }
        }
        }
    }
    if(n==5){
        book_appointment(&head,&app_n,&app_m,appointment_slots);
    }
    if(n==0){
        break;
    }
    }
    
}
