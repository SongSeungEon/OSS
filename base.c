#include <stdio.h>
#include "base.h"
#include <string.h>
int count;


// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function

// records 의 모든 원소들을 출력
// 필요하다면 data.txt 파일에 저장.
void print_all_records(Record records[]){
  printf("No--Student Number-----Name-------------Major---------\n");
  for(int i=0;i<count;i++){
    printf(" %d     %d\t\t%s\t\t%s\n",i+1,records[i].id,records[i].name,records[i].major);
  }
  printf("\n\n");
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function

// 구조체 Record 변수 records 에 입력을 해주는 함수
void add_a_record(Record records[]){
  char dummy;
  printf("What is Student number? : ");
  scanf("%d",&records[count].id);
  scanf("%c",&dummy);
  printf("What is name? :");
  fgets(records[count].name,30,stdin);
  records[count].name[strlen(records[count].name)-1]='\0';
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
  printf("\"You can input word that only you can understand.\"\n");
  printf("ex) CSEE, GLS\n");
  printf("\nWhat is major? :");
  fgets(records[count].major,100,stdin);
  records[count].major[strlen(records[count].major)-1]='\0';
  count++;
}


// TODO: Add more functions to fulfill the requirements
// 데이터 파일을 불러오는 함수
void load_data(Record records[]){
  char dummy_s[30];
  FILE* file= fopen("data.txt","r"); 
  char dummy;
  if(file==NULL)
  printf("\n!There is no Data!\n\n");
  else{
    fgets(dummy_s,30,file);
    fscanf(file,"%d",&count);
    fscanf(file,"%c",&dummy);
    fgets(dummy_s,30,file);
    fgets(dummy_s,30,file);
    fgets(dummy_s,30,file);
    fgets(dummy_s,30,file);
    for(int i=0;i<count;i++){
      fgets(dummy_s,30,file);
      fgets(records[i].name,30,file);
      fscanf(file,"%d",&records[i].id);
      fscanf(file,"%c",&dummy);
      fgets(records[i].major,100,file);
      records[i].major[strlen(records[i].major)-1]='\0';
      records[i].name[strlen(records[i].name)-1]='\0';
    }
    printf("\nData Loaded\n\n");
  }
}

// 데이터 파일에 저장하는 함수
void save_data(Record records[]){
  printf("The previous data will be deleted.\n");
  printf("...");
  FILE* file = fopen("data.txt","w");
  fprintf(file,"||The count of the members||\n%d\n",count);
  fprintf(file,"===========INDEX=========\n");
  fprintf(file,"[Name]\n[Student number]\n[Major]\n");
  fprintf(file,"=========================\n");
  for(int i=0;i<count;i++){
    fprintf(file,"%s\n%d\n%s\n",records[i].name,records[i].id,records[i].major);
    fprintf(file,"=========================\n");
  }
  printf("Data Saved.\n\n");
  
}

// records 에 입력되어있는 정보를 수정하는 함수
void update_record(Record records[]){
  print_all_records(records);
  int num;
  printf("Enter a number that you want to update. : ");
  scanf("%d",&num);
  if(num>count||num<1)printf("You entered wrong number.\n");
  else{
    char dummy;
    printf("What is Student number? : ");
    scanf("%d",&records[num-1].id);
    scanf("%c",&dummy);
    printf("What is name? :");
    fgets(records[num-1].name,30,stdin);
    records[num-1].name[strlen(records[num-1].name)-1]='\0';
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
    printf("\n\"You can input word that only you can understand.\"\n");
    printf("ex) CSEE, GLS\n");
    printf("\nWhat is major? :");
    fgets(records[num-1].major,100,stdin);
    records[num-1].major[strlen(records[num-1].major)-1]='\0';
  }

}

// records에 입력되어있는 정보를 삭제하는 함수
// 삭제로 인해 생기는 빈 record 는 자동으로 당겨지게 설정함.
// fragmentation 함수를 내제하고 있음.
void delete_record(Record records[]){
  print_all_records(records);
  char dummy;
  int num;
  printf("Enter a number that you want to delete. : ");
  scanf("%d",&num);
  scanf("%c",&dummy);
  if(num>count||num<1)printf("You entered wrong number.\n\n");
  else{
    char delete_check;
    printf("Do you want to delete %dth student?\n",num);
    printf("Yes : y | No : n\n");
    scanf("%c",&delete_check);
    scanf("%c",&dummy);
    if(delete_check=='y'){
      for(int i=num-1;i<count-1;i++){
        records[i].id=records[i+1].id;
        strcpy(records[i].major,records[i+1].major);
        strcpy(records[i].name,records[i+1].name);
      }
      count--;
      printf("\nThe data is deleted.\n");
      printf("Automatically the list will be defragmented.\n\n");
    }
    else{
      printf("Go back to the menu...\n");
    }
  }
}

int return_count(){
  return count;
}// this function performs retrun the value of count to extras.c
