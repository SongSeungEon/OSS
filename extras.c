#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "base.h"
#include "extras.h"



// Function: rearrange()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Rearrange the records from senior to freshman.
void rearrange(Record records[]){
int count = return_count();
	// TODO: Modify this function as you need
	printf("Your records will be rearranged from senior to freshman.\n");
  printf("Rearranging...\n");
  for(int i=0;i<count;i++){
    for(int j=i;j<count;j++){
      if(records[i].id>records[j].id){
        int tmp_id;
        tmp_id=records[i].id;
        records[i].id=records[j].id;
        records[j].id=tmp_id;
        char tmp_major[100];
        strcpy(tmp_major,records[i].major);
        strcpy(records[i].major,records[j].major);
        strcpy(records[j].major,tmp_major);
        char tmp_name[30];
        strcpy(tmp_name,records[i].name);
        strcpy(records[i].name,records[j].name);
        strcpy(records[j].name,tmp_name);
      }
    }
  }
  printf("Complete!!\n\n");
}

void find_student_num(Record records[]){
  int count = return_count();
  int num;
  char dummy;
  printf("Which grade do you want to find? ex) 19 or 18\n");
  scanf("%d",&num);
  scanf("%c",&dummy);
  printf("This is the list whose grade is %d\n\n",num);
  for(int i=0;i<count;i++){
    if((records[i].id/100000)-200==num){
      printf("%d\t\t%s\t\t%s\n",records[i].id,records[i].name,records[i].major);
    }
  }
  printf("\n\n");
}
void find_student_major(Record records[]){
  int count = return_count();
  char find_major[100];
  printf("The list of major\n\n");
  printf("-Global Leadership School\n");
  printf("-International Studies, Languages and Literature\n");
  printf("-Management and Economics\n");
  printf("-Law\n");
  printf("-Counseling Psychology and Social Welfare\n");
  printf("-Communication Arts and Science\n");
  printf("-Spatial Environment System Engineering\n");
  printf("-Mechanical and Control Engineering\n");
  printf("-Contents Convergence Design\n");
  printf("-Life Science\n");
  printf("-Computer Science and Electrical Engineering\n");
  printf("-Global Entrepreneurship and information, Communication Technology\n");
  printf("-Creative Convergence Education\n");
  printf("\n\nWhich major do you want to find?\n");
  fgets(find_major,100,stdin);
  find_major[strlen(find_major)-1]='\0';
  printf("\n\nThis is the list whose major is %s\n\n",find_major);
  for(int i=0;i<count;i++){
    if(strcmp(records[i].major,find_major)==0){
      printf("%d\t\t%s\t\t%s\n",records[i].id,records[i].name,records[i].major);
    }
  }
  printf("\n\n");
}

void make_groups(Record records[]){
    srand(time(NULL));
  int count=return_count();
  int num[count];
  for(int i=0;i<count;i++){
    num[i]=rand()%1000;
  }
  int group_count;
  char dummy;
  printf("How many students do you want to organize in one group?\n");
  scanf("%d",&group_count);
  scanf("%c",&dummy);
  int now_count=1;
  int total_group=1;
  int first=rand()%count;
  printf("-----Group 1------------------\n");
  printf("%d   %s  %s\n",records[first].id,records[first].name,records[first].major);
  num[first]+=1000;
  for(int i=0;i<count;i++){
    if(now_count==group_count){
      total_group++;
      now_count=0;
      printf("\n-----Group %d------------------\n",total_group);
    }
    if(num[i]<1000){
      if(num[i]>800){
        printf("%d   %s  %s\n",records[i].id,records[i].name,records[i].major);
        num[i]+=1000;
        now_count++;
      }
      else if(num[i]>0&&num[i]<=200){
        printf("%d   %s  %s\n",records[i].id,records[i].name,records[i].major);
        num[i]+=1000;
        now_count++;
      }
      else if(num[i]>400&&num[i]<=600){
        printf("%d   %s  %s\n",records[i].id,records[i].name,records[i].major);
        num[i]+=1000;
        now_count++;
      }
      else if(num[i]>200&&num[i]<=400){
        printf("%d   %s  %s\n",records[i].id,records[i].name,records[i].major);
        num[i]+=1000;
        now_count++;
      }
      else if(num[i]>600&&num[i]<=800){
        printf("%d   %s  %s\n",records[i].id,records[i].name,records[i].major);
        num[i]+=1000;
        now_count++;
        
      }
    }
  }
  printf("------------------------------\n\n");
}

void Advanced_Search(Record records[]){

	printf("Advanced_Search\n");
	int count = return_count();
	
	
	char condition_name[20];
	printf("put the name condition 0(doesn't care) or student name: ");
  	fgets(condition_name,20,stdin);
  	condition_name[strlen(condition_name)-1]='\0';
	
	char major_condition[100];	
	printf("put the major condition 0(doesn't care) or student name: ");
  	fgets(major_condition,100,stdin);
  	major_condition[strlen(major_condition)-1]='\0';
	
	for(int i = 0 ; i < count ; i++){
		if(((strcmp(records[i].major, major_condition)==0) || (strcmp(major_condition,"0")==0)) && ((strcmp(records[i].name,condition_name)==0) || (strcmp(condition_name,"0")==0)))		printf("%d\t\t%s\t\t%s\n",records[i].id,records[i].name,records[i].major);
	}
}



// TODO: Add more functions to fulfill the optional requirements
