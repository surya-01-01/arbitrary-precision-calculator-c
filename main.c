/*
------------------------------------------------------------------------------------------
NAME : SURYA G
DATE : 27-02-2025
DESCRIPTION : To performing mathematical calculation like addition, subraction, 
mutiplication, division with larger datas.
------------------------------------------------------------------------------------------
*/

#include "apc.h"
int minus_flag = 0;// Flag to indicate whether the result of subtraction should be negative
int main(int argc, char *argv[])
{
	// Check if there are enough arguments (program name + two numbers + operator)
	if(argc<4)
	{
		printf("LESS ARGUMENTS\n");
		return 1;//return failure
	}

	// /* Declare the pointers */
	Dlist *head1 = NULL, *tail1 = NULL;
	Dlist *head2 = NULL, *tail2 = NULL;
	Dlist *headR = NULL, *tailR = NULL;

	char operator= argv[2][0];// Operator (+, -, X, /) passed as the third argument

	// Convert the input numbers (argv[1] and argv[3]) into linked lists
	digit_to_list(&head1, &tail1, &head2, &tail2, argv);

	switch (operator)
	{
	case '+':
		/* call the function to perform the addition operation */
		addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		break;
	case '-':
		//to handle negative numbers ,swapping the numbers
		if (strlen(argv[1]) < strlen(argv[3]))
		{
			// interchanging list1 and list2
			Dlist *temp = head1;
			head1 = head2;
			head2 = temp;
			temp = tail1;
			tail1 = tail2;
			tail2 = temp;
			minus_flag = 1;//setting negative flag
		}
		else if ((strlen(argv[1]) == strlen(argv[3])) && (strcmp(argv[1], argv[3]) < 0))
		{
			// If the numbers are the same length and the first is smaller, swap the numbers
			Dlist *temp = head1;
			head1 = head2;
			head2 = temp;
			temp = tail1;
			tail1 = tail2;
			tail2 = temp;
			minus_flag = 1;//setting negative flag
		}
		/* call the function to perform the subtraction operation */
		subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		break;
	case 'X':
		/* call the function to perform the multiplication operation */
		multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		break;
	case '/':
		/* call the function to perform the division operation */
		if(division(&head1, &tail1, &head2, &tail2, &headR, &tailR)==0)
		{
			printf("ERROR:CANNOT DIVIDED BY ZERO\n");
			return 1;// Return failure if division by zero occurs
		}
		break;
	default:
		printf("Invalid Input:-( Try again...\n");
	}

	// Print the result
	print_ans(headR);
	return 0;//return success
}


// Function to convert the input strings (argv[1] and argv[3]) into linked lists
void digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
	int i = 0;

	// Convert the first number 
	while (argv[1][i])
	{
		// Insert each digit into the linked list
		if (insert_last(head1, tail1, argv[1][i] - '0'))
			i++;
		else
			return;
	}

	i = 0;

	// Convert the second number
	while (argv[3][i])
	{
		// Insert each digit into the linked list
		if (insert_last(head2, tail2, argv[3][i] - '0'))
			i++;
		else
			return;
	}
}


// Function to insert a node with data at the end 
int insert_last(Dlist **head, Dlist **tail, int data)
{
	Dlist *new = malloc(sizeof(Dlist));// Allocate memory for the new node

	// If the node is not created the returning failure
	if (!new)
	{
		return FAILURE;
	}
	new->data = data;// Set the data of the new node
	new->prev = NULL;
	new->next = NULL;

	// If the list is empty then inserting the node as first node
	if (!*head && !*tail)
	{
		*head = *tail = new;
		return 1;
	}

	// Insert the new node at the end of the list
	new->prev = *tail;
	if (*tail)
		(*tail)->next = new;
	*tail = new;
	return 1;
}


// Function to print the result list in a readable format
void print_ans(Dlist *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");// If the list is empty, print a message
	}
	else
	{
		printf("Head -> ");
		// Traverse the list and print each node's data
		while (head)
		{
			/* Printing the list */
			printf("%d <-", head->data);

			/* Travering in forward direction */
			head = head->next;
			if (head)
				printf("> ");
		}
		printf(" Tail\n");
	}
}
