//
// Created by Christopher Geleta on 4/18/16.
//

#ifndef PA6_LINKED_LIST_H
#define PA6_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include "entry.h"
//#include "memwatch.h"

typedef struct node Node;

Node *list_create();

Node *list_insert(Node *node, struct entry *entry);

Node *list_delete(Node *head, struct entry *e);

void list_print(Node *head);

int search_list(struct node *node);

struct entry *get_entry_from_list(struct node *head, char *e);


#endif //PA6_LINKED_LIST_H
