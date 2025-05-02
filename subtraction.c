#include "apc.h"
extern int minus_flag;
// Function to perform subtraction of two large numbers represented as doubly linked lists
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	//initializing temporary pointers for traversing
	Dlist *temp1 = *tail1; // pointer to the tail of the first number
	Dlist *temp2 = *tail2; //for second number

	//skipping the leading zeros in the first number
	while ((*head1)->data == 0 && (*head1)->next != NULL)
	{
		(*head1) = (*head1)->next;
		(*head1)->prev = NULL;
	}
	//skipping the leading zeros in the second number
	while ((*head2)->data == 0 && (*head2)->next != NULL)
	{
		(*head2) = (*head2)->next;
		(*head2)->prev = NULL;
	}

	int borrow = 0, sum = 0, flag = 0, oper2 = 0;

	//loop through the lists untill two lists become empty
	while (temp1 || temp2)
	{
		if (temp1)
		{
			sum = temp1->data;//get data and update to sum
			temp1 = temp1->prev;//move to previous node
		}

		sum = sum - borrow;//subract any borrow from previous step
		borrow = 0;//reset borrow 
		if (temp2)
		{
			oper2 = temp2->data;//get data from second number
			temp2 = temp2->prev;//move to previous node
		}
		else
			oper2 = 0;//if the second number is shorter

		//check if we need borrow
		if (sum < oper2)
		{
			sum = sum + 10 - oper2;
			borrow = 1;//set the borrow flag
		}
		else
		{
			sum = sum - oper2;
		}
		//Insert the result into the result list
		insert_first(headR, tailR, sum);
		sum = 0;//reset the sum
	}

	//remove any leading zeros
	while ((*headR)->data == 0 && (*headR)->next != NULL)
	{
		(*headR) = (*headR)->next;
	}

	//if result is negative
	if (minus_flag)
		(*headR)->data = -(*headR)->data;

	return 1;//Return success
}
