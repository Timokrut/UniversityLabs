#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the linked list
typedef struct Node {
    char *word;
    struct Node *next;
} Node;

// Create a new node
Node* createNode(char *word) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->word = strdup(word);
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end of linked list
void insertNode(Node **head, char *word) {
    Node *newNode = createNode(word);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// print linked list
void printList(Node *head) {
    while (head != NULL) {
        printf("%s ", head->word);
        head = head->next;
    }
}

// sort linked list by word length
void sortList(Node **head) {
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    if (*head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (strlen(ptr1->word) > strlen(ptr1->next->word)) {
                char *temp = ptr1->word;
                ptr1->word = ptr1->next->word;
                ptr1->next->word = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// free memory allocated for linked list
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->word);
        free(temp);
    }
}

int main() {
    FILE *file1, *file2, *file3;
    char word[100];

    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head3 = NULL;

    file1 = fopen("file1.txt", "r");
    file2 = fopen("file2.txt", "r");
    file3 = fopen("file3.txt", "r");

    while (fscanf(file1, "%s", word) != EOF) {
        insertNode(&head1, word);
    }

    while (fscanf(file2, "%s", word) != EOF) {
        insertNode(&head2, word);
    }

    while (fscanf(file3, "%s", word) != EOF) {
        insertNode(&head3, word);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);

    // Concatenate the linked lists
    Node *current = head1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head2;
    current = head2;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head3;

    sortList(&head1);

    printf("Sorted List:\n");
    printList(head1);

    freeList(head1);

    return 0;
}
