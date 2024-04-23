#include <stdio.h>
#include <stdlib.h>
#define N 5
#include "ProjectFunctions.h"
//This was done by me

void room_assign(char *name,int phone,char sex,int *counter/*,int *cntL,int *cntM,int *cntE*/){
    printf("What type of room would you like to choose?\n");
    FILE *fp3=fopen("ROOMDETAILS.txt","a");
    
    printf("Type 1 for Luxury\nType 2 for medium\nType 3 for economy\nType 4 for no room\n");
    int n;


   
    scanf("%d",&n);
    if(n==1){
        char *date;
        date=(char *)malloc(7*sizeof(char *));
        printf("Please enter entry date\n");
        
        scanf("%s",date);
        int cntroom1,cntroom2,cntroom3;
        FILE *rd=fopen("ROOMCOUNT.txt","r");
        fscanf(rd,"%d %d %d",&cntroom1,&cntroom2,&cntroom3);
        fclose(rd);
        fprintf(fp3,"%s %d %c %s %s ",name,phone,sex,"Luxury",date);
        if(cntroom1>10){
            fprintf(fp3,"Price=$%d\n",100);
        }
        else if(cntroom1>5 && cntroom1<10){
            fprintf(fp3,"Price=$%d\n",150);
        }
        else{
            fprintf(fp3,"Price=$%d\n",180);
        }
        fclose(fp3);
        rd=fopen("ROOMCOUNT.txt","w");
        
        cntroom1=cntroom1-1;
        fprintf(rd,"%d %d %d",cntroom1,cntroom2,cntroom3);
        fclose(rd);
        free(date);
        
        return;
    }
    if(n==2){
        char *date;
        date=(char *)malloc(7*sizeof(char *));
        printf("Please enter entry date");
        
        scanf("%s",date);
        int cntroom1,cntroom2,cntroom3;
        FILE *rd=fopen("ROOMCOUNT.txt","r");
        fscanf(rd,"%d %d %d",&cntroom1,&cntroom2,&cntroom3);
        fclose(rd);
        fprintf(fp3,"%s %d %c %s %s ",name,phone,sex,"Medium",date);
        if(cntroom2>25){
            fprintf(fp3,"Price=$%d\n",60);
        }
        else if(cntroom2<25 && cntroom2>10){
            fprintf(fp3,"Price=$%d\n",70);
        }
        else{
            fprintf(fp3,"Price=$%d\n",80);
        }


        fclose(fp3);
        rd=fopen("ROOMCOUNT.txt","w");
        
        cntroom2=cntroom2-1;
        fprintf(rd,"%d %d %d",cntroom1,cntroom2,cntroom3);
        fclose(rd);
        free(date);
        
        return;
    }
    if(n==3){
        char *date;
        date=(char *)malloc(7*sizeof(char *));
        printf("Please enter entry date");
        
        scanf("%s",date);
        int cntroom1,cntroom2,cntroom3;
        FILE *rd=fopen("ROOMCOUNT.txt","r");
        fscanf(rd,"%d %d %d",&cntroom1,&cntroom2,&cntroom3);
        fclose(rd);
        
        fprintf(fp3,"%s %d %c %s %s Price=$%d\n",name,phone,sex,"Economy",date,20);
        
        fclose(fp3);
        rd=fopen("ROOMCOUNT.txt","w");
        
        cntroom3=cntroom3-1;
        fprintf(rd,"%d %d %d",cntroom1,cntroom2,cntroom3);
        fclose(rd);
        free(date);
        
        return;
    }
    if(n==4){
        fprintf(fp3,"%s %d %c %s Price=%s\n",name,phone,sex,"No room","N/A");
    fclose(fp3);
}
}
char *deassign_room(char *name, char **price_room)
{
    FILE *fp1 = fopen("ROOMDETAILS.txt", "r");
    if (fp1 == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char tmp_name[50][20];
    int tmp_ph[50];
    char tmp_sex[50];
    char *tmp_type[50];
    char *tmp_date[50];
    char *tmp_price[50];
    int i = 0;
    int found = 0, index = -1;
    while (fscanf(fp1, "%s %d %c %ms %ms %ms", tmp_name[i], &tmp_ph[i], &tmp_sex[i], &tmp_type[i], &tmp_date[i], &tmp_price[i]) == 6) {
        if (strcmp(tmp_name[i], name) == 0) {
            found = 1;
            index = i;
        }
        i++;
    }

    if (found) {
        FILE *fp2 = fopen("ROOMDETAILS.txt", "w");
        if (fp2 == NULL) {
            perror("Error opening file");
            return NULL;
        }
        for (int j = 0; j < i; j++) {
            if (j != index)
                fprintf(fp2, "%s %d %c %s %s %s\n", tmp_name[j], tmp_ph[j], tmp_sex[j], tmp_type[j], tmp_date[j], tmp_price[j]);
        }
        fclose(fp2);
        *price_room = strdup(tmp_price[index]);
        printf("Patient room successfully deassigned\n");
        return strdup(tmp_date[index]);
    }
    else {
        printf("Patient was not assigned a room\n");
        fclose(fp1); // close the file pointer before returning
        return NULL;
    }

    // reopen the file pointer to read remaining room details
    fclose(fp1);
    fp1 = fopen("ROOMDETAILS.txt", "r");
    if (fp1 == NULL) {
        perror("Error opening file");
        return NULL;
    }
    while (fscanf(fp1, "%s %d %c %ms %ms %ms", tmp_name[i], &tmp_ph[i], &tmp_sex[i], &tmp_type[i], &tmp_date[i], &tmp_price[i]) == 6) {
        printf("%s %d %c %s %s %s\n", tmp_name[i], tmp_ph[i], tmp_sex[i], tmp_type[i], tmp_date[i], tmp_price[i]);
        i++;
    }
    fclose(fp1);
}//It asssigns room to the patients and keeps track of number of rooms. When patient account is deleted the the room is deassigned

