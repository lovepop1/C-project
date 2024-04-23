#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ProjectFunctions.h"
struct Doctor{
    char name[50];
    char field[50];
    int availability;
};
void doctor_assign(char *name,char * sickness){//assigning doctor to patient based on availability

    FILE *fp1=fopen("DOC.txt","r");
    FILE *fp3=fopen("account.txt","r");


    
    char **name_list = malloc(7 * sizeof(char *));
    char **field_list = malloc(7 * sizeof(char *));
    int *avail_list = malloc(7 * sizeof(int));

    int j=0;


    


    char tmp_name[50];
    int tmp_age, tmp_phone, tmp_emergency_contact, tmp_sickness_level;
    char tmp_sex, tmp_sickness[50];

    char docname[50],fieldname[50];
    int avail;

    int count = 0;

    int found = 0;
    j = 0;
    int index_of_name;
    


    while (fscanf(fp3, "%s %d %c %d %d %s %d", tmp_name, &tmp_age, &tmp_sex, &tmp_phone, &tmp_emergency_contact, tmp_sickness, &tmp_sickness_level) == 7) {
        if (strcmp(tmp_name, name) == 0) {
            if(strcmp(sickness,"Diabetes")==0){
                while(1){
                name_list[j]=(char *)malloc(20*sizeof(char));
    
                field_list[j]=(char *)malloc(20*sizeof(char));
                if(fscanf(fp1,"%s %s %d",name_list[j],field_list[j],&avail_list[j])== 3){
                    if((strcmp(field_list[j],"General_Medicine")==0) && avail_list[j]==1){
                        printf("Appointment successfull, %s assigned\n",name_list[j]);
                        avail_list[j]=0;  
		    }
                    else{
                        avail_list[j]=1;
                    }
                }
                else{break;}
                
                j++;
                }
            }
        
            else if(strcmp(sickness,"Flu")==0){
                while(1){
                name_list[j]=(char *)malloc(20*sizeof(char));
    
                field_list[j]=(char *)malloc(20*sizeof(char));
                if(fscanf(fp1,"%s %s %d",name_list[j],field_list[j],&avail_list[j])== 3){
                    if((strcmp(field_list[j],"General_Medicine")==0) && avail_list[j]==1){
                        printf("Appointment successfull, %s assigned\n",name_list[j]);
                        avail_list[j]=0;  
		    }
                    else{
                        avail_list[j]=1;
                    }
                }
                else{break;}
                
                j++;
                }
            }
            else if(strcmp(sickness,"Cardiac")==0){
                 while(1){
                name_list[j]=(char *)malloc(20*sizeof(char));
    
                field_list[j]=(char *)malloc(20*sizeof(char));
                if(fscanf(fp1,"%s %s %d",name_list[j],field_list[j],&avail_list[j])== 3){
                    if((strcmp(field_list[j],"Cardiology")==0) && avail_list[j]==1){
                        printf("Appointment successfull, %s assigned\n",name_list[j]);
                        avail_list[j]=0;  
		    }
                    else{
                        avail_list[j]=1;
                    }
                }
                else{break;}
                
                j++;
                }
                
            }
            else if(strcmp(sickness,"Arthritis")==0){
                while(1){
                name_list[j]=(char *)malloc(20*sizeof(char));
    
                field_list[j]=(char *)malloc(20*sizeof(char));
                if(fscanf(fp1,"%s %s %d",name_list[j],field_list[j],&avail_list[j])== 3){
                    if((strcmp(field_list[j],"Orthopaedics")==0) && avail_list[j]==1){
                        printf("Appointment successfull, %s assigned\n",name_list[j]);
                        avail_list[j]=0;  
		    }
                    else{
                        avail_list[j]=1;
                    }
                }
                else{break;}
                
                j++;
                }
            }

            else if(strcmp(sickness,"Eyesight")==0){
                while(1){
                name_list[j]=(char *)malloc(20*sizeof(char));
    
                field_list[j]=(char *)malloc(20*sizeof(char));
                if(fscanf(fp1,"%s %s %d",name_list[j],field_list[j],&avail_list[j])== 3){
                    if((strcmp(field_list[j],"Opthamology")==0) && avail_list[j]==1){
                        printf("Appointment successfull, %s assigned\n",name_list[j]);
                        avail_list[j]=0;  
		    }
                    else{
                        avail_list[j]=1;
                    }
                }
                else{break;}
                
                j++;
                }
            }  
            else if(strcmp(sickness,"Covid")==0){
                while(1){
                name_list[j]=(char *)malloc(20*sizeof(char));
    
                field_list[j]=(char *)malloc(20*sizeof(char));
                if(fscanf(fp1,"%s %s %d",name_list[j],field_list[j],&avail_list[j])== 3){
                    if((strcmp(field_list[j],"General_Medicine")==0) && avail_list[j]==1){
                        printf("Appointment successfull, %s assigned\n",name_list[j]);
                        avail_list[j]=0;  
		    }
                    else{
                        avail_list[j]=1;
                    }
                }
                else{break;}
                
                j++;
                }
            } 
            else if(strcmp(sickness,"Cancer")==0){
                while(1){
                name_list[j]=(char *)malloc(20*sizeof(char));
    
                field_list[j]=(char *)malloc(20*sizeof(char));
                if(fscanf(fp1,"%s %s %d",name_list[j],field_list[j],&avail_list[j])== 3){
                    if((strcmp(field_list[j],"Oncology")==0) && avail_list[j]==1){
                        printf("Appointment successfull, %s assigned\n",name_list[j]);
                        avail_list[j]=0;  
		    }
                    else{
                        avail_list[j]=1;
                    }
                }
                else{break;}
                
                j++;
                }
            }    
            else if(strcmp(sickness,"Skin")==0){
                while(1){
                name_list[j]=(char *)malloc(20*sizeof(char));
    
                field_list[j]=(char *)malloc(20*sizeof(char));
                if(fscanf(fp1,"%s %s %d",name_list[j],field_list[j],&avail_list[j])== 3){
                    if((strcmp(field_list[j],"Dermatology")==0) && avail_list[j]==1){
                        printf("Appointment successfull, %s assigned\n",name_list[j]);
                        avail_list[j]=0;  
		    }
                    else{
                        avail_list[j]=1;
                    }
                }
                else{break;}
                
                j++;
                }
            }    
            else if(strcmp(sickness,"UTI")==0){
                while(1){
                name_list[j]=(char *)malloc(20*sizeof(char));
    
                field_list[j]=(char *)malloc(20*sizeof(char));
                if(fscanf(fp1,"%s %s %d",name_list[j],field_list[j],&avail_list[j])== 3){
                    if((strcmp(field_list[j],"Urology")==0) && avail_list[j]==1){
                        printf("Appointment successfull, %s assigned\n",name_list[j]);
                        avail_list[j]=0;  
		    }
                    else{
                        avail_list[j]=1;
                    }
                }
                else{break;}
                
                j++;
                }
            } 
            else if(strcmp(sickness,"Kidney")==0){
                while(1){
                name_list[j]=(char *)malloc(20*sizeof(char));
    
                field_list[j]=(char *)malloc(20*sizeof(char));
                if(fscanf(fp1,"%s %s %d",name_list[j],field_list[j],&avail_list[j])== 3){
                    if((strcmp(field_list[j],"Urology")==0) && avail_list[j]==1){
                        printf("Appointment successfull, %s assigned\n",name_list[j]);
                        avail_list[j]=0;  
		    }
                    else{
                        avail_list[j]=1;
                    }
                }
                else{break;}
                
                j++;
                }
            } 
            }
    }

        
    fclose(fp1);
    fclose(fp3);
    FILE *assign0=fopen("DOC.txt", "w");        
    for(int i=0;i<7;i++){
        fprintf(assign0,"%s %s %d\n",name_list[i],field_list[i],avail_list[i]);
    }
    fclose(assign0);
}