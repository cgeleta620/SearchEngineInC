//
// Created by Christopher Geleta on 4/18/16.
//

#include "linked_list.h"

struct node {

    struct entry *value;
    struct node *next;

};

Node *list_create() {

    struct node *dummy = malloc(sizeof(struct node));
    if (dummy == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(-1);
    }
    dummy->value = NULL;
    dummy->next = NULL;
    return dummy;

}

int search_list(struct node *node) {

    int bool = 0;
    if ((node->value != NULL) || (node->next != NULL)) {
        bool = 1;
    }

    return bool;
}

struct entry *get_entry_from_list(struct node *head, char *e) {

    Node *tmp;
    for (tmp = head; tmp->next != NULL; tmp = tmp->next) {
        if (strcmp(get_key(tmp->next->value), e) == 0) {
            return tmp->next->value;
        }
    }
    return NULL;
}

Node *list_insert(Node *head, struct entry *entry) {

    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "Out of ");
        fprintf(stderr, "memory");
        fprintf(stderr, "\n");
        exit(-1);
    }
    new_node->value = entry;
    new_node->next = NULL;

    if (head == NULL) {
        head = list_create();
    }

    Node *tmp = head;
    new_node->next = tmp->next;
    tmp->next = new_node;
    return head;

}

Node *list_delete(Node *head, struct entry *e) {
    Node *tmp;

    if (head == NULL) {
        return NULL;
    }
    for (tmp = head; tmp->next != NULL; tmp = tmp->next) {
        if (strcmp(get_key(tmp->next->value), get_key(e)) == 0) {
            Node *rm = tmp->next;
            tmp->next = tmp->next->next;
            free(rm->value);
            free(rm);
            return head;
        }
    }
    return head;
}

void list_print(Node *head) {

    if (head == NULL) {
        printf("Warning list == ");
        printf("NULL someone ");
        printf("didn't call ");
        printf("create!\n");
    }
    else {
        Node *tmp;
        for (tmp = head->next; tmp != NULL; tmp = tmp->next) {
            printf("%s \n", get_key(tmp->value));
        }
    }
}

