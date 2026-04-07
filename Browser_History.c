/*
Write a C program to implement a browser history system using  stack implemented with a linked list, supporting
visit,back, and display operations and displaying memory growth through memory address changes during execution.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char url[20];
    struct Node* next;
};

struct Node* top = NULL;

void visit(char* url) {
    struct Node* newNode = malloc(sizeof(struct Node));
    sprintf(newNode->url, "%s", url);
    newNode->next = top;
    top = newNode;
    printf("Visited %s at address: %p\n", url, (void*)newNode);
}

void back() {
    if (!top) { printf("No history!\n"); return; }
    struct Node* temp = top;
    top = top->next;
    printf("Left %s. Freeing: %p\n", temp->url, (void*)temp);
    free(temp);
}

void display() {
    struct Node* curr = top;
    while (curr) {
        printf("[%s | %p] -> ", curr->url, (void*)curr);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    char url[20];

    while (1) {
        printf("\n1.Visit 2.Back 3.Display 4.Exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter URL: ");
            scanf("%s", url);
            visit(url);
        } else if (choice == 2) {
            back();
        } else if (choice == 3) {
            display();
        } else {
            break;
        }
    }
    return 0;
}
