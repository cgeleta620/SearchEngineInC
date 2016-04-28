//
// Created by Christopher Geleta on 4/15/16.
//

#include "hash_table.h"


struct table {
    int size;
    struct node **table;
};

Table *create_table(int size) {

    Table *new_table;

    new_table = malloc(sizeof(Table));
    if (new_table == NULL) {
        return NULL;
    }

    new_table->table = malloc(sizeof(Node *) * size);
    new_table->size = size;

    if (new_table->table == NULL) {
        return NULL;
    }

    int i = 0;
    for (; i < size; i++) {
        new_table->table[i] = NULL;
    }

    return new_table;

}

Table *insert(Table *t, struct entry *entry) {

    int pos = 0;
    pos = hash(t, get_key(entry));
    t->table[pos] = list_insert(t->table[pos], entry);

    return t;

}

void table_dump(Table *t) {

    int q = 0;
    for (; q < t->size; q++) {
        if (t->table[q] != NULL) {
            list_print(t->table[q]);
        }
    }

}

struct entry *get_entry_from_table(Table *t, char *word) {

    int pos = 0;
    pos = hash(t, word);
    struct entry *e = NULL;
    e = get_entry_from_list(t->table[pos], word);
    return e;

}

Table *delete_item(Table *t, struct entry *entry) {

    int pos = 0;
    pos = hash(t, get_key(entry));
    t->table[pos] = list_delete(t->table[pos], entry);
    t->table[pos] = NULL;

    return t;

}

int search_table(Table *t, char *str) {

    int hash_val = hash(t, str);
    int bool = 0;
    if (t->table[hash_val] != NULL) {
        bool = search_list(t->table[hash_val]);
    }
    return bool;
}

int hash(Table *table, char *key) {

    unsigned int hashValue, alpha = 31415, beta = 27183;
    for (hashValue = 0; *key != 0;
         key++, alpha = alpha * beta % (table->size - 1))
        hashValue = (alpha * hashValue + *key) % table->size;
    return hashValue;
}


