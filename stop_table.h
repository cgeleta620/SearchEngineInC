//
// Created by Christopher Geleta on 4/24/16.
//

#ifndef PA6_STOP_TABLE_H
#define PA6_STOP_TABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <search.h>

#include "stop_linked_list.h"
#include "stop_word.h"
//#include "memwatch.h"

typedef struct stop_table Stop_table;

Stop_table *create_table_stop(int size);

Stop_table *insert_stop(Stop_table *t, struct stop_word *buff);

void table_dump_stop(Stop_table *t);

int search_stop(Stop_table *t, char *str);

int hash_stop(Stop_table *table, char *key);

#endif //PA6_STOP_TABLE_H
