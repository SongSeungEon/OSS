#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], Record[]);
void display_menu();

// main function
int main(){
	Record records[MAX_RECORDS];
	char user_input[64] = "";
	while(strcmp(user_input, "99") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[]){

	// TODO: Modify this function as you need

	if(!strcmp(input, "1"))
		add_a_record(records);
	else if(!strcmp(input, "2"))
		print_all_records(records);	
	else if(!strcmp(input, "3"))
		update_record(records);
	else if(!strcmp(input, "4"))
		delete_record(records);	
  else if(!strcmp(input, "5"))
    load_data(records);
  else if(!strcmp(input,"6"))
    save_data(records);
  else if(!strcmp(input,"7"))
    rearrange(records);
  else if(!strcmp(input,"8")){
    printf("Which one do you want to find?\n");
    printf("1. Student number\n");
    printf("2. Major\n");
    int choice;
    char dummy;
    scanf("%d",&choice);
    scanf("%c",&dummy);
    if(choice ==1)find_student_num(records);
    else if(choice ==2)find_student_major(records);
    else printf("You entered wrong menu!!\n\n");
  }
  else if(!strcmp(input,"9")){
    make_groups(records);
  }
  else if(!strcmp(input,"10")){
    Advanced_Search(records);
}
	else if(!strcmp(input, "99"))
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	// TODO: Modify this function as you need

	printf("******************************\n");
	printf(" Membership management system \n");
	printf("******************************\n");
	printf(" 1. Add a new member\n");
	printf(" 2. Print all members\n");
	printf(" 3. Update the record\n");
	printf(" 4. Delete a member (including defragmentation)\n");
  printf(" 5. Load Data\n");
  printf(" 6. Save Data\n");
  printf(" 7. Rearrange (extra function)\n");
  printf(" 8. Find students (extra function)\n");
  printf(" 9. Make random groups(extra function)\n");
  printf(" 10. Advaned Search(extra function _ GH)\n");
	printf(" 99. Quit\n");
}
