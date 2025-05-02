#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1 = *tail1; // storing
	Dlist *temp2 = *tail2;
	Dlist *headR1 = NULL, *headR2 = NULL;
	Dlist *tailR1 = NULL, *tailR2 = NULL;
	while ((*head1)->data == 0 && (*head1)->next != NULL)
	{
		(*head1) = (*head1)->next;
		(*head1)->prev = NULL;
	}
	while ((*head2)->data == 0 && (*head2)->next != NULL)
	{
		(*head2) = (*head2)->next;
		(*head2)->prev = NULL;
	}
	int sum = 0, carry = 0, count = 0, i = 0, val;
	while (temp2)
	{
		val = temp2->data;
		while (temp1)
		{
			sum = (val * temp1->data) + carry;
			carry = 0;
			if (sum > 9)
			{
				carry = sum / 10;
				sum = sum % 10;
			}
			if (count == 0)
				insert_first(headR, tailR, sum);
			else
				insert_first(&headR2, &tailR2, sum);
			temp1 = temp1->prev;
			sum = 0;
		}
		if (carry && count == 0)
			insert_first(headR, tailR, carry);
		else if (carry)
			insert_first(&headR2, &tailR2, carry);
		carry = 0;
		if (headR2 != NULL && count != 0)
		{
			addition(headR, tailR, &headR2, &tailR2, &headR1, &tailR1);
			dl_delete_list(headR, tailR);
			dl_delete_list(&headR2, &tailR2);
			*headR = headR1;
			*tailR = tailR1;
			headR1 = NULL;
			tailR1 = NULL;
		}
		count++;
		i = 0;
		//printf("digit : %d\n", count);
		while (i != count && temp2->prev != NULL)
		{
			insert_first(&headR2, &tailR2, 0);
			i++;
		}
		temp2 = temp2->prev;
		temp1 = *tail1;
	}

	while ((*headR)->data == 0 && (*headR)->next != NULL)
	{
		(*headR) = (*headR)->next;
		(*headR)->prev = NULL;
	}

	// addition(&headR1,&tailR1,&headR2,&tailR2,headR,tailR);
	return 0;
}

int dl_delete_list(Dlist **head, Dlist **tail)
{
	// cheaking the list is empty or not;
	if (*head == NULL)
		return FAILURE;
	Dlist *temp = *head, *prev = *head;
	while (temp != NULL)
	{
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	*head = *tail = NULL;
	return SUCCESS;
}
