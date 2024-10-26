#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure and create an alias 'Node'
typedef struct node {
    char word[100];
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(const char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    // Initialize the next pointer to NULL
    newNode->next = NULL;

     // Return the pointer to the new node
    return newNode;
}

// Function to insert a new node after a given node
void insertAfter(Node* prevNode, const char* newWord) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    Node* newNode = createNode(newWord);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s -> ", current->word);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create the linked list with initial words
    Node* head = createNode("bat");
    head->next = createNode("book");
    head->next->next = createNode("banana");

    printf("Original list:\n");
    printList(head);

    // Insert a new word "blue" after "bat"
    insertAfter(head, "blue");

    printf("List after insertion:\n");
    printList(head);

    // Free allocated memory (not shown here, but important in real code)
    return 0;
}
