//
// Created by Christopher Geleta on 4/15/16.
//

#ifndef PA6_HASH_TABLE_H
#define PA6_HASH_TABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <search.h>
#include "linked_list.h"
//#include "memwatch.h"

typedef struct table Table;

Table *create_table(int size);

Table *insert(Table *t, struct entry *entry);

void table_dump(Table *t);

int hash(Table *table, char *key);

int search_table(Table *t, char *str);

Table *delete_item(Table *t, struct entry *entry);

struct entry *get_entry_from_table(Table *t, char *word);

#endif //PA6_HASH_TABLE_H



