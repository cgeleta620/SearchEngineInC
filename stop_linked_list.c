//
// Created by Christopher Geleta on 4/24/16.
//

#include "stop_linked_list.h"

struct stop_node {
    struct stop_word *value;
    struct stop_node *next;
};

Stop_node *list_create_stop_node() {

    struct stop_node *dummy = malloc(sizeof(struct stop_node));
    if (dummy == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(-1);
    }

    dummy->value = NULL;
    dummy->next = NULL;
    return dummy;

}

int search_list_stop(struct stop_node *stop_node) {

    int bool = 0;

    if ((stop_node->value != NULL) || (stop_node->next != NULL)) {
        bool = 1;
    }

    return bool;
}


Stop_node *list_insert_stop(Stop_node *head, struct stop_word *entry) {

    Stop_node *new_node = malloc(sizeof(Stop_node));

    if (new_node == NULL) {
        fprintf(stderr, "Out of ");
        fprintf(stderr, "memory");
        fprintf(stderr, "\n");
        exit(-1);
    }
    new_node->value = entry;
    new_node->next = NULL;

    if (head == NULL) {
        head = list_create_stop_node();
    }

    Stop_node *tmp = head;
    new_node->next = tmp->next;
    tmp->next = new_node;
    return head;

}

void list_print_stop(Stop_node *head) {

    if (head == NULL) {
        printf("Warning list == ");
        printf("NULL someone ");
        printf("didn't call ");
        printf("create!\n");
    }
    else {
        Stop_node *tmp;
        for (tmp = head->next; tmp != NULL; tmp = tmp->next)
            printf("%s \n", get_stop_word(tmp->value));
    }
}


