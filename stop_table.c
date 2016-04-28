//
// Created by Christopher Geleta on 4/24/16.
//

#include "stop_table.h"

struct stop_table {
    int size;
    struct stop_node **stop_table;
};

Stop_table *create_table_stop(int size) {

    Stop_table *new_table;

    new_table = malloc(sizeof(Stop_table));
    if (new_table == NULL) {
        return NULL;
    }

    new_table->stop_table = malloc(sizeof(struct stop_node *) * size);
    new_table->size = size;

    if (new_table->stop_table == NULL) {
        return NULL;
    }

    int i = 0;
    for (; i < size; i++) {
        new_table->stop_table[i] = NULL;
    }

    return new_table;
}

Stop_table *insert_stop(Stop_table *t, struct stop_word *buff) {

    int pos = 0;
    pos = hash_stop(t, get_stop_word(buff));
    t->stop_table[pos] = list_insert_stop(t->stop_table[pos], buff);
    return t;
}

int search_stop(Stop_table *t, char *str) {

    int hash_val = hash_stop(t, str);
    int bool = 0;
    if (t->stop_table[hash_val] != NULL) {
        bool = search_list_stop(t->stop_table[hash_val]);
    }
    return bool;
}

int hash_stop(Stop_table *table, char *key) {
    unsigned int hashValue, alpha = 31415, beta = 27183;
    for (hashValue = 0; *key != 0;
         key++, alpha = alpha * beta % (table->size - 1))
        hashValue = (alpha * hashValue + *key) % table->size;
    return hashValue;
}

void table_dump_stop(Stop_table *t) {

    int q = 0;
    for (; q < t->size; q++) {
        if (t->stop_table[q] != NULL) {
            list_print_stop(t->stop_table[q]);
        }
    }
}

