#include<stdio.h>
#include<stdlib.h>

// Strucuture of each node
struct node {
	struct node* parent;
	struct node* left;
	int value;
	struct node* right;
};

typedef struct node* tree;

tree ROOT = NULL;

tree create() {
	tree temp = (tree) malloc(sizeof(struct node));
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	return temp;
}

void insert(tree head, tree newNode) {
	if(newNode->value < head->value) {
		if(head->left == NULL) {
			head->left = newNode;
			head->left->parent = head;
		} else {
			insert(head->left, newNode);
		}
	} else if(newNode->value > head->value) {
		if(head->right == NULL) {
			head->right = newNode;
			head->right->parent = head;
		} else {
			insert(head->right, newNode);
		}
	}	
}

tree searchInTheTree(tree head, int value) {
	if(head == NULL || head->value == value) {
		return head;
	} else if(head->value > value) {
		searchInTheTree(head->left, value);
	} else {
		searchInTheTree(head->right, value);
	}	
}

void displayTheTree(tree head) {
	if(head == NULL) {
		return;
	}
	displayTheTree(head->left);
	printf("-> %d\n", head->value);
	displayTheTree(head->right);
}

/*	1. Deletion in a Binary Search Tree,
*		a). Leaf Node deletion with no children,	--> Make its parent point to NULL, and delete the node
*		b). Node with one child,					--> Make its parent point to its child node.
*		c). Node with two children,					--> Find the next higher node, change the value of deletable value to the highest value and then delete the old highest value.
*/

tree findTheHighestNode(tree head) {
	if(head->right != NULL) { 
		findTheHighestNode(head->right);
	} else {
		return head;
	}
}

void destroyTheTree(tree head) {
	if(head->right == NULL && head->left == NULL) {
		free(head);
	}
}

void emptyTheRoot(tree head) {
	if(head == NULL && ROOT == head) {
		ROOT = NULL;	// make the root NULL don't free the ROOT, bcz you may want to add nodes again.
	}
}

void deleteTheLeafNode(tree head, int value) {
	if(head->value == value) {
		//	a). Leaf Node with no children,	
		if(head->parent->right->value == value) {	// using the parent pointer check your value is in the right side, if yes
			head->parent->right = NULL; 	// make the parent right NULL,
			free(head);		// and then free the node.
		} else {	// it must be a left node
			head->parent->left = NULL;		// make the parent left NULL,
			free(head);		// and then free the head.
		}		
	}
}

void deleteOneChildNode(tree head, int value) {
	if(head->parent->right->value == value) {
		head->parent->right = head->right;
		free(head);
	} else if(head->parent->left->value == value) {
		head->parent->left = head->left;
		free(head);
	}
}

void deleteTwoChildNode(tree head) {
	tree HigherNode = findTheHighestNode(head->left);
	if(HigherNode != NULL) {
		head->value = HigherNode->value;
		HigherNode->parent->right = NULL;
		free(HigherNode);
	}
}

tree delete(int deleteValue) {
	tree searchReturnNode;
	searchReturnNode = searchInTheTree(ROOT, deleteValue);
	
	if(searchReturnNode == NULL) {
		return NULL;
	}
	
	if(searchReturnNode->left != NULL && searchReturnNode->right != NULL) {
		
		printf("\nIts a parent node\n\n");
		deleteTwoChildNode(searchReturnNode);
		
	} else if((searchReturnNode->left != NULL && searchReturnNode->right == NULL)	||
				(searchReturnNode->left == NULL && searchReturnNode->right != NULL)) {
		
		printf("\nOne child\n\n");
		deleteOneChildNode(searchReturnNode, deleteValue);
		
	}
	else if(searchReturnNode->left == NULL && searchReturnNode->right == NULL) { 	// check that the node has no children
		
		if(searchReturnNode == ROOT) {		// check if it is a root node, if yes
			emptyTheRoot(searchReturnNode);
		} else {
			deleteTheLeafNode(searchReturnNode, deleteValue);
		}
		
	}
	return searchReturnNode;
}

int main() {
	int choice;
	int searchNode=0;
	int deleteNode=0;
	tree temp;
	while(1) {
		printf("1. Insertion\n2. Searching\n3. Display\n4. Delete\n5. Exit\n >>> ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				temp = create();
				printf("Enter the Number >> ");
				scanf("%d", &temp->value);
				tree searchReturnNode = searchInTheTree(ROOT, temp->value);
				if(searchReturnNode == NULL) {					
					if(ROOT == NULL) {
						temp->parent = NULL;		
						ROOT = temp;
					} else {					
						insert(ROOT, temp);
					}
				} else {
					printf("\nElement Already found!\n\n");
				}
				break;
			case 2:
				if(ROOT == NULL) {
					printf("\nTree is Empty!\n\n");
					break;
				}
				printf("Enter the search Term >> ");
				scanf("%d",&searchNode);
				searchReturnNode = searchInTheTree(ROOT, searchNode);
				if(searchReturnNode != NULL) {
					printf("\nElement found : %d\n\n", searchReturnNode->value);
				} else {
					printf("\nElement Not found\n\n");
				}
				break;
			case 3:
				if(ROOT == NULL) {
					printf("\nTree is Empty!\n\n");
					break;
				}
				displayTheTree(ROOT);
				break;
			case 4:
				if(ROOT == NULL) {
					printf("\nTree is Empty!\n\n");
					break;
				}
				printf("Enter the value To delete >> ");
				scanf("%d",&deleteNode);
				if(delete(deleteNode) == NULL) {
					printf("\nElement Not found to delete.\n\n");
				} else {
					printf("\nElement Deleted\n\n");
				}
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("\nWrong Choice\n\n");
		}		
	}
	return 0;
}
