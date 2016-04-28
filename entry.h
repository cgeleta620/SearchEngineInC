//
// Created by Christopher Geleta on 4/18/16.
//

#ifndef PA6_ENTRY_H
#define PA6_ENTRY_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "memwatch.h"

struct entry *create_entry(char *key, char **documents);

char *get_key(struct entry *e);

char **get_docs(struct entry *e);

#endif //PA6_ENTRY_H

