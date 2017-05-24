#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node{
	int obj;
	struct Node *next;
	struct Node *prev;
} Node;

// function to add item at the very end of the list
void append(struct Node **head, int data){
	if(*head == NULL) {	
		struct Node *new_node =  malloc(sizeof(struct Node));
		new_node->next = new_node->prev = new_node;
		(new_node->obj) = data;
		*head = new_node;// call by reference used for this 
	} else {
		struct Node *tmp;
		struct Node *new_node = malloc(sizeof(struct Node));
		tmp = (*head)->prev;
		tmp->next = new_node;
		(*head)->prev = new_node;
		new_node->prev = tmp;
		new_node->next = *head;
		new_node->obj = data;
	}
}

// print the linked list
void print_ll(struct Node **start, int reverse){
	struct Node *tmp = *start;
	//printf("%d\n\n\n", tmp->next->obj);
	if(reverse != 1) {	
		while(tmp->next != *start){
			printf("%d\n", tmp->obj);
			tmp = tmp->next;
		}
		printf("%d\n", tmp->obj);
	} else {
		while(tmp->prev != *start){
			printf("%d\t", tmp->obj);
			tmp = tmp->prev;
		}
		printf("%d\n", tmp->obj);
	}
}

// free all the nodes
void free_ll(struct Node **start){
	struct Node *tmp = *start;
	while(*start != tmp->next){
		tmp = tmp->next;
		free(tmp->prev);
	}
	free(tmp);
}

int main(){
	struct Node *head = NULL;
	// call by reference used in functions
	append(&head, 7);
	append(&head, 5);
	append(&head, 3);
	// print the linked list in forward order
	print_ll(&head, 0);
	// print the linked list in reverse order
	//print_ll(&head, 1);
	// deleting the linked list to free all the mallocs
	free_ll(&head);
	return 0;
}

