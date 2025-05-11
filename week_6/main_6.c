#include <stdio.h>
#include "hashtable_wk5.h"

void hash_adhoc_test() {
    int command = 1;
    HashTable table = create_hashtable(11);  // Example size
    char buffer[100];

    while (command) {
        printf("Enter command (1: Insert, 2: Remove, 3: Print): ");
        scanf_s("%d", &command);
        switch (command) {
        case 1:
            printf("Enter string to insert: ");
            scanf_s("%s", buffer, 100);
            hash_insert(&table, buffer);
            break;
        case 2:
            printf("Enter string to remove: ");
            scanf_s("%s", buffer, 100);
            hash_remove(&table, buffer);
            break;
        case 3:
            hash_print(&table);
            break;
        }
        printf("\n");
    }
    hash_destroy(&table);
}

int main() {
    hash_adhoc_test();
    return 0;
}
