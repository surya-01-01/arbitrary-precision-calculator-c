#ifndef APC_H
#define APC_H

// Standard library headers for input/output, memory allocation, and string manipulation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define constants for success and failure return values
#define SUCCESS 0
#define FAILURE -1

// Define a structure for doubly linked list nodes
typedef struct node
{
	struct node *prev;// Pointer to the previous node in the list
	int data;// The data stored in the node (integer)
	struct node *next;// Pointer to the next node in the list
}Dlist;

/* Include the prototypes here */

/*store the operands into the list */
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);


/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

// Function to insert a node with data at the end of the doubly linked list
int insert_last(Dlist **head,Dlist **tail,int data);

// Function to insert a node with data at the beginning of the doubly linked list
int insert_first(Dlist **head,Dlist **tail,int data);

// Function to print the content of the linked list
void print_ans(Dlist *head);

// Function to delete all nodes in the doubly linked list and free memory
int dl_delete_list(Dlist **head, Dlist **tail);

// Function to compare two linked lists for equality 
int compare_list(Dlist *head1,Dlist *head2);

#endif
