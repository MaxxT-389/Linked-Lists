LINKED LISTS
Maxwell Thuo SCT221-0347/2023
Ian Gichana SCT221-0102/2023

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;


void insert(int value) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = head;
    head = ptr;
}

void traverse() {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


void search(int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            printf("Element %d found in the list.\n", key);
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the list.\n", key);
}


void delete(int value) {
    struct Node* current = head;
    struct Node* prev = NULL;


    if (current != NULL && current->data == value) {
        head = current->next; // Change head
        free(current); // Free old head
        printf("Element %d deleted.\n", value);
        return;
    }


    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", value);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Element %d deleted.\n", value);
}

void menu() {
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 4:
                traverse();
                break;
            case 5:
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    menu(); // Start the menu-driven program
    return 0;
}
