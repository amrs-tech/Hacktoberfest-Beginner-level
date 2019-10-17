// below is the C program to search an element in a linked list 
#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h> 

// Link list node 
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

/* Given a reference (pointer to pointer) to the head 
of a list and an int, push a new node on the front 
of the list. */
void push(struct Node** head, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = 
			(struct Node*) malloc(sizeof(struct Node)); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head); 

	/* move the head to point to the new node */
	(*head) = new_node; 
} 

/* Checks whether the value x is present in linked list */
bool search(struct Node* head, int x) 
{ 
	struct Node* current = head; // Initialize current 
	while (current != NULL) 
	{ 
		if (current->data == x) 
			return true; 
		current = current->next; 
	} 
	return false; 
} 

/* Driver program to test count function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 
	int x ;
	int d,i;
	do
    {
        printf("\nEnter your option\n1. insert\n2. exit\n");
        scanf("%d", &d);
        switch (d)
        {
        case 1:
            printf("enter data");
            scanf("%d",&i);
            push(&head,i);
            break;
        default:
            break;
        }
    } while (d != 2);

	/* Use push() to construct below list */
	printf("enter data to search\n");
	scanf("%d",&x);
	search(head, x)? printf("Yes") : printf("No"); 
	return 0; 
} 
