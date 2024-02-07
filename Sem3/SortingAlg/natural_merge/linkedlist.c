#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted linked lists
struct Node* merge(struct Node* left, struct Node* right) {
    struct Node dummy;
    struct Node* current = &dummy;

    // Compare elements from both lists and merge them
    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    // If any elements are remaining in either list, append them
    if (left != NULL) {
        current->next = left;
    } else {
        current->next = right;
    }

    return dummy.next;
}

// Function to perform merge sort on a linked list
struct Node* sort(struct Node* head) {
    // Base case: if the list is empty or has only one element
    if (head == NULL || head->next == NULL) {
        return head;
    }
    // Split the list into two halves
    struct Node *slow, *fast, *prevSlow;
    slow = fast = prevSlow = head;

    while (fast != NULL && fast->next != NULL) {
        if (fast->data > fast->next->data) break;
        fast = fast->next;
    }

    slow = fast->next;
    fast->next = NULL;

    // Recursively sort the two halves
    struct Node* left = sort(slow);

    // Merge the sorted halves
    return merge(head, left);
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test merge sort for linked list
int main() {
    struct Node* head = NULL;

    // Example: Inserting elements into the linked list
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 6);

    printf("Original linked list: ");
    printList(head);

    // Perform merge sort
    head = sort(head);

    printf("Linked list after merge sort: ");
    printList(head);

    return 0;
}
