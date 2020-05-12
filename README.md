Membership Management System
=====

In main funcion
-----
It shows menus by 

	display_menu();

and it takes a number to select menu.

And according to the number it performs function like below.

	if(selection==1) add_a_record(records);
	else if(selection==2) print_all_records(records);
	else if(selection==3) update_record(records);
	else if(selection==4) delete_record(records);
	else if(selection==5) load_data(records);
	else if(selection==6) save_data(records);
	else if(selection==7) rearrange(records);
	else if(selection==8) {
		if(another_selection==1) find_student_num(records);
		else if(another_selection==2) find_student_major(records);
	}
	else if(selection==9) make_groups(records);
	else if(selection==99) //end the program//
	else //print error//

In "add_a_record" function
----

User inputs student number, name and major.

And "count" (it means the number of data) increases 1.

In "print_all_records" function
----
It displays all the data in the record as much as count.

In "update_record" function
---
User inputs a number.

Then it checks whether the number is ranged between 0 and count.

If it is true, user can modify the information.

But if it is false, it prints error.

In "delete_record" function
---
User inputs a number.

Then it checks whether the number is ranged between 0 and count.

If it is true, the information will be deleted. 
And the blank array will be defragmented automatically. 
And "count" decreases 1.

But if it is false, it prints error.

In "load_data" function
--
Automatically, the project opens file ("data.txt") with reading mode.

If the file does not exist, it prints error.

If the file exists, the data will be loaded to the project.

In "save_data" function
---
Once saved, the previous data will be deleted.

The project opens file ("data.txt") with writing mode.

At first, it saves the count ( the number of data).

And then the present record will be saved with the format.

In "rearrange" function
---
It performs that the record rearranges from senior to freshman.

In "find_student_num" function
---
User inputs a grade number (like 19 or 18) that he wants to find.

It changes the student number into grade number ( like 21900384 -> 19) and finds corresponding students.

And it displays the students with their information.

In "find_student_major" function
---
User inputs a major that he wants to find.

It finds corresponding students and displays the students with their information.

In "make_groups" function
---
In this function, the project makes some groups randomly by using rand().

User inputs a number that means the number of students in one group.

And the project makes some groups according to the user's input.
