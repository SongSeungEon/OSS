#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes
void print_all_records(Record[]);
void add_a_record(Record[]);
void load_data(Record[]);
void save_data(Record[]);
void update_record(Record[]);
void delete_record(Record[]);
int return_count(); // this function performs retrun the value of count to extras.c

#endif
