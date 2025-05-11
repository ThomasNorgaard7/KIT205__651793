#include <stdio.h>
#include <stdlib.h>
#include "list_2.h"

// Function to create and return a new empty list.
List new_list() {
    List temp;
    temp.head = NULL;
    return temp;
}

// Function to print the contents of a list.
void print_list(List* self) {
    ListNodePtr current = self->head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;

        if (current != NULL)
            printf(", ");
    }
    printf("\n");
}

// Function to insert a new node with given data at the front of the list.
void insert_at_front(List* self, int data) {
    ListNodePtr new_node = malloc(sizeof * new_node);
    new_node->data = data;
    new_node->next = self->head;
    self->head = new_node;
}

// Function to insert a new node with given data in the list in ascending order.
void insert_in_order(List* self, int data) {
    ListNodePtr current = self->head;
    ListNodePtr prev = NULL;

    ListNodePtr new_node = malloc(sizeof * new_node);
    new_node->data = data;
    new_node->next = NULL;

    while (current != NULL && current->data < data) {
        prev = current;
        current = current->next;
    }

    if (current == self->head) { // at front
        new_node->next = current;
        self->head = new_node;
    }
    else { // middle
        new_node->next = current;
        prev->next = new_node;
    }
}

// Function to delete the first occurrence of a node with given data from the list.
void delete_list(List* self, int data) {
    ListNodePtr current = self->head;
    ListNodePtr prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) { // front of list
                self->head = current->next;
                free(current);
                current = self->head;
            }
            else { // middle of list
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

// Function to free the memory allocated to a list and all its nodes.
void destroy_list(List* self) {
    ListNodePtr current = self->head;
    while (current != NULL) {
        ListNodePtr to_free = current;
        current = current->next;
        free(to_free);
    }
    self->head = NULL;
}

// Function to test insert_at_front
void list_test() {
    List list = new_list();
    printf("Testing insert_at_front... \n");
    insert_at_front(&list, 5);
    insert_at_front(&list, 3);
    insert_at_front(&list, 7);
    insert_at_front(&list, 2);
    insert_at_front(&list, 0);

    printf("Expected: 0, 2, 7, 3, 5 \n");
    printf("Result: ");
    print_list(&list);
    destroy_list(&list);
}

// Ad-hoc interactive test function
void list_adhoc_test() {
    List my_list = new_list();
    int quit = 0;
    while (!quit) {
        int option;
        printf("\nMenu: \n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("0. Quit\n");
        printf("Choose an option: ");
        scanf_s("%d", &option);

        if (option == 0) {
            quit = 1;
        }
        else if (option == 1) {
            int data;
            printf("Enter a number to insert: ");
            scanf_s("%d", &data);
            insert_at_front(&my_list, data);
        }
        else if (option == 2) {
            int data;
            printf("Enter a number to delete: ");
            scanf_s("%d", &data);
            delete_list(&my_list, data);
        }
        else if (option == 3) {
            print_list(&my_list);
        }
    }
    destroy_list(&my_list);
}

// Function to reverse the list
List reverse(List* self) {
    List reversed = new_list();
    ListNodePtr current = self->head;
    while (current != NULL) {
        insert_at_front(&reversed, current->data);
        current = current->next;
    }
    return reversed;
}

// Function to merge two sorted lists into one sorted list
List merge(List* list1, List* list2) {
    List merged = new_list();
    ListNodePtr current1 = list1->head;
    ListNodePtr current2 = list2->head;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data < current2->data) {
            insert_in_order(&merged, current1->data);
            current1 = current1->next;
        }
        else {
            insert_in_order(&merged, current2->data);
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        insert_in_order(&merged, current1->data);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        insert_in_order(&merged, current2->data);
        current2 = current2->next;
    }

    return merged;
}
