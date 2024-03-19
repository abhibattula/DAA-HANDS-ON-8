#include <stdio.h>
#include <stdlib.h>


struct Node 
{
    int data;
    struct Node* next;
};


struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** headRef, int data) 
{
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) 
    {
        *headRef = newNode;
    } else {
        struct Node* current = *headRef;
        while (current->next != NULL) 
        {
            current = current->next;

        }
        current->next = newNode;
    }
    printf("Element %d added to the linked list.\n", data);
}


void deleteLastNode(struct Node** headRef) 
{
    if (*headRef == NULL) 
    {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }
    if ((*headRef)->next == NULL) 
    {
        free(*headRef);
        *headRef = NULL;
        printf("Last element deleted from the linked list.\n");
        return;
    }
    struct Node* prev = NULL;
    struct Node* current = *headRef;
    while (current->next != NULL) 
    {
        prev = current;
        current = current->next;
    }
    free(current);
    prev->next = NULL;
    printf("Last element deleted from the linked list.\n");
}


void displayList(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Elements in the linked list: ");
    struct Node* current = head;
    while (current != NULL)
     {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


void freeList(struct Node** headRef) 
{
    struct Node* current = *headRef;
    struct Node* next;
    while (current != NULL) 
    {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

int main() 
{
    struct Node* head = NULL;
    int choice, element;

    while (1) 
    {
        printf("\nLinked List Operations:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Last Element\n");
        printf("3. Display Elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertNode(&head, element);
                break;
            case 2:
                deleteLastNode(&head);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                freeList(&head);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
