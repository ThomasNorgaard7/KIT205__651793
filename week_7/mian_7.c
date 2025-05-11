#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* String;

// Swap two strings in the array
void swap(String* a, String* b) {
    String temp = *a;
    *a = *b;
    *b = temp;
}

// Quicksort function for strings
void quicksort(String* a, int first, int last) {
    if (first < last) {
        int i = first, j = last - 1;
        String pivot = a[last];

        while (i <= j) {
            while (i < last && strcmp(a[i], pivot) <= 0) i++;
            while (j >= first && strcmp(a[j], pivot) > 0) j--;
            if (i < j) {
                swap(&a[i], &a[j]);
            }
        }
        swap(&a[i], &a[last]);

        quicksort(a, first, j);
        quicksort(a, i + 1, last);
    }
}

int main() {
    FILE* file = NULL;
    fopen_s(&file, "input_7.txt", "r");  // Open the input file for reading
    if (file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    int n;
    fscanf_s(file, "%d", &n);  // Read number of strings

    String* strings = malloc(n * sizeof(String));
    char buffer[100];

    for (int i = 0; i < n; i++) {
        fscanf_s(file, "%99s", buffer, (unsigned)_countof(buffer));
        strings[i] = malloc(strlen(buffer) + 1);
        strcpy_s(strings[i], strlen(buffer) + 1, buffer);
    }

    fclose(file);  // Close the file after reading

    quicksort(strings, 0, n - 1);

    printf("\nSorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }
    free(strings);

    return 0;
}
