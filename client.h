//
// Created by Christopher Geleta on 4/15/16.
//

#ifndef PA6_CLIENT_H
#define PA6_CLIENT_H

#include "entry.h"
#include "hash_table.h"
#include "stop_table.h"
#include "stop_word.h"
//#include "memwatch.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void process(int argc, char *argv[]);

void create_stop_table(const char *stop_file, Stop_table *stop_table);

int str_cmp( const void* a, const void* b);

#endif //PA6_CLIENT_H


