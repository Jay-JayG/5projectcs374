#include "llist.h"
#include <stdio.h>// for printf(), perror()
#include <stdlib.h> // for exit(), malloc()
#include <string.h>

struct node *node_alloc(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void llist_insert_head(struct node **head, struct node *n) {
    n->next = *head;
    *head = n;
}

struct node *llist_delete_head(struct node **head) {
    if (*head == NULL) {
        return NULL;
    }
    struct node *h;
    h = *head;
    *head = h->next;
    h->next = NULL;
    return h;
}

void llist_insert_tail(struct node **head, struct node *n) {
    if (*head == NULL) {
        *head = n;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void llist_print(struct node *head) {
    if (head == NULL) {
        printf("[empty]\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("%d\n", temp->value);
}

void node_free(struct node *n) {
    if (n != NULL) {
        free(n);
    }
}

void llist_free(struct node **head) {
    while (*head != NULL) {
        node_free(llist_delete_head(head));
    }
}

int main(int argc, char *argv[]) {

    struct node *head = NULL;

    if (argc < 2) {
        printf("Not eough arguments\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "ih") == 0) {
            i++;
            int value = atoi(argv[i]);
            llist_insert_head(&head, node_alloc(value));
        }
        if (strcmp(argv[i], "it") == 0) {
            i++;
            int value = atoi(argv[i]);
            llist_insert_tail(&head, node_alloc(value));
        }
        if (strcmp(argv[i], "dh") == 0) {
            node_free(llist_delete_head(&head));
        }
        if (strcmp(argv[i], "f") == 0) {
            llist_free(&head);
        }
        if (strcmp(argv[i], "p") == 0) {
            llist_print(head);
        }
    }
}