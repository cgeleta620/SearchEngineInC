//
// Created by Christopher Geleta on 4/24/16.
//

#ifndef PA6_STOP_LINKED_LIST_H
#define PA6_STOP_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stop_word.h"
//#include "memwatch.h"

typedef struct stop_node Stop_node;

void list_print_stop(Stop_node *head);

Stop_node *list_create_stop_node();

Stop_node *list_insert_stop(Stop_node *head, struct stop_word *);

int search_list_stop(struct stop_node *);

#endif //PA6_STOP_LINKED_LIST_H
