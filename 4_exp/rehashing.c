#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define Size 10
#define load_factor 0.7

void insert();
void display();
void search();
void rehash();

int size = Size;
int hash_table[Size] = {0};
int n;

void main() {
    int choice;
    printf("Ronit Satish Mehta 60009230207\n");
    do {
        printf("\n\t\t\t HASH ALLOCATION \n");
        printf("\nEnter the choice for operations:\n");
        printf("\n1.insert\n2.display\n3.search\n4.Rehasing\n5.exit");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                rehash();
                printf("\n rehashing successful");
                break;
            case 5:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid Choice!!!");
                break;
        }
    } while (choice != 5);
}

void insert() {
    int key, index, i, flag = 0, hkey;
    printf("\nEnter the value for hash key: ");
    scanf("%d", &key);
    hkey = key % size;
    for (int i = 0; i < size; i++) {
        index = (hkey + i) % size;
        if (hash_table[index] == 0) {
            hash_table[index] = key;
            break;
        }
    }
    if (i == size) {
        printf("\nElements cannot be inserted.\n");
    }
}

void display() {
    int i;
    printf("\n The hash Table is as follows");
    printf("\n Index \t value \n");
    for (int i = 0; i < size; i++) {
        printf("\n");
        printf("%d\t %d\t", i, hash_table[i]);
    }
}

void search() {
    int key, index, i, flag = 0, hkey;
    printf("\nEnter Search Element:");
    scanf("%d", &key);
    hkey = key % size;
    for (int i = 0; i < size; i++) {
        index = (hkey + i) % size;
        if (hash_table[index] == key) {
            printf("\nThe value was found at this index %d", index);
            break;
        }
    }
    if (size == i) {
        printf("\nValue not found\n");
    }
}

void rehash() {
    int new_size = size * 2;
    int* new_hash_table = (int*)malloc(new_size * sizeof(int));
    for (int i = 0; i < new_size; i++) {
        new_hash_table[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        if (hash_table[i] != 0) {
            int key = hash_table[i];
            int hkey = key % new_size;
            int index;
            for (int j = 0; j < new_size; j++) {
                index = (hkey + j) % new_size;
                if (new_hash_table[index] == 0) {
                    new_hash_table[index] = key;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < new_size; i++) {
        hash_table[i] = new_hash_table[i];
    }
    size = new_size;
    free(new_hash_table);
}
