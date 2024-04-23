#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProjectFunctions.h"
//This was done by Vishal
int difference_between_dates(char *date1, char *date2)
{
    int d1, m1, d2, m2;
    sscanf(date1, "%d/%d", &d1, &m1);
    sscanf(date2, "%d/%d", &d2, &m2);
    
    int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int days1 = d1;
    for (int i = 1; i < m1; i++) {
        days1 += month_days[i];
    }
    
    int days2 = d2;
    for (int i = 1; i < m2; i++) {
        days2 += month_days[i];
    }
    
    return (days2 - days1);
}
//Calculates the difference between dates assuming the year to be constant. Based on this differnece we can calculate the bill.
float billing(char *name){
      char *price_room;
      printf("Was the person staying in a room Y/N\n");
      char option;
      scanf(" %c",&option);
      float Finalprice;
      int price_pharma;
      if(option=='Y' || option=='y'){
        char *entry = deassign_room(name, &price_room);
        char entrydate[10];
        strcpy(entrydate,entry);
        if(strcmp(entrydate,"NULL")==0) return -1;
        int price;
        if (strlen(price_room) == 9 && strncmp(price_room, "Price=$", 7) == 0) {
            // extract the price value from the input string and convert it to an integer
            price = atoi(price_room + 7);
        } else if (strlen(price_room) == 10 && strncmp(price_room, "Price=$", 7) == 0) {
            price = atoi(price_room + 7);
        }
        printf("Enter the date on which the patient exited the room(DD/MM)\n");
        char exitdate[10];
        scanf("%s",exitdate);
        int diff=difference_between_dates(entrydate,exitdate);
        printf("Enter the cost of pharma:\n");
        scanf("%d",&price_pharma);
        Finalprice=(price*diff +price_pharma);
        //add the function to dessign rooms and increase the count of the specific room by 1
    }
      else{
        printf("Enter the cost of pharma:\n");
        scanf("%d",&price_pharma);
        Finalprice=price_pharma;
      }
      return Finalprice;
}//This checks if the patient was in a room or not, and depending on this we calculate the bill.