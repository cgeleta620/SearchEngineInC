//
// Created by Christopher Geleta on 4/25/16.
//

#ifndef PA6_STOP_WORD_H
#define PA6_STOP_WORD_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//#include "memwatch.h"

struct stop_word *create_stop_word(char *word);

char *get_stop_word(struct stop_word *word);

#endif //PA6_STOP_WORD_H
