//
// Created by Christopher Geleta on 4/25/16.
//

#include "stop_word.h"

struct stop_word {
    char *stop_word;
};

struct stop_word *create_stop_word(char *word) {

    struct stop_word *temp = malloc(sizeof(struct stop_word));
    //    printf("Test one\n");
    temp->stop_word = (char *) calloc(strlen(word) + 1, sizeof(char));
    // printf("Test 2\n");

    strcpy(temp->stop_word, word);
    // printf("Test 3\n");


    return temp;
}

char *get_stop_word(struct stop_word *word) {
    return word->stop_word;
}
