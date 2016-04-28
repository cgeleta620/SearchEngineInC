//
// Created by Christopher Geleta on 4/18/16.
//

#include "entry.h"

struct entry {

    char *key;
    char **documents;

};

struct entry *create_entry(char *key, char **documents) {

    struct entry *temp = (struct entry *) malloc(sizeof(struct entry));
    temp->key = (char *) calloc(strlen(key) + 1, sizeof(char));
    strcpy(temp->key, key);

    int q = 0;
    for (; q < 9000; q++) {
        temp->documents = (char **) malloc(256 * sizeof(char *));
    }

    int a = 0;
    for (; a < 9000; a++) {
        temp->documents[a] = documents[a];
    }

    return temp;
}

char *get_key(struct entry *e) {
    return e->key;
}

char **get_docs(struct entry *e) {
    return e->documents;
}


