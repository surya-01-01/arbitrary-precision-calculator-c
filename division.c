#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
	int count=0,size1=0,size2=0,flag1=0,flag=0,flag2=0;
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
	if((*head2)->next==NULL && (*head2)->data==0)
	{
		return 0;
	}
	if((*head2)->next==NULL && (*head2)->data==0)
	{
		*headR=*head1;
		*tailR=*tail1;
		return 1;
	}
	Dlist *temp1H = *head1;
	Dlist *temp1T = *tail1; 
	Dlist *temp2H = *head2;
	Dlist *temp2T = *tail2;
	Dlist *headR1 = NULL;
	Dlist *tailR1 = NULL;
	Dlist *headR2 = NULL;
	Dlist *tailR2 = NULL;
	while(temp1H)
	{
		size1++;
		temp1H=temp1H->next;
	}
	temp1H = *head1; 
	while(temp2H)
	{
		size2++;
		temp2H=temp2H->next;
	}
	temp2H = *head2;
	int i=0;
	while(i!=size2)					
	{
		insert_last(&headR1,&tailR1,temp1H->data);
		if(temp1H)
			temp1H=temp1H->next;
		i++;
	}
	while(temp1H)
	{
		flag2=1;
		flag=0;
		while(compare_list(headR1,temp2H)==0 && temp1H!=NULL)
		{
				insert_last(&headR1,&tailR1,temp1H->data);
				if(flag || temp1H==NULL)
				{
					insert_last(headR,tailR,0);
				}
				if(temp1H)
					temp1H=temp1H->next;
				flag=1;
		}
		while(compare_list(headR1,temp2H))
		{
			flag1=1;
			subtraction(&headR1,&tailR1,&temp2H,&temp2T,&headR2,&tailR2);
			dl_delete_list(&headR1, &tailR1);
			headR1=headR2;
			tailR1=tailR2;
			headR2=NULL;
			tailR2=NULL;
			count++;
		}
		if(flag1)
			insert_last(headR,tailR,count);
		flag1=0;
		count=0;
	}
	if(flag2==0)
	{
		while(compare_list(headR1,temp2H))
		{
			flag1=1;
			subtraction(&headR1,&tailR1,&temp2H,&temp2T,&headR2,&tailR2);
			dl_delete_list(&headR1, &tailR1);
			headR1=headR2;
			tailR1=tailR2;
			headR2=NULL;
			tailR2=NULL;
			count++;
		}
		insert_last(headR,tailR,count);
	}

		return 1;

}

	

int compare_list(Dlist *head1,Dlist *head2)
{
	while ((head1)->data == 0 && (head1)->next != NULL)
	{
		(head1) = (head1)->next;
		(head1)->prev = NULL;
	}
	while ((head2)->data == 0 && (head2)->next != NULL)
	{
		(head2) = (head2)->next;
		(head2)->prev = NULL;
	}
	int size1=0,size2=0;
	Dlist *temp1=head1;
	Dlist *temp2=head2;
	while(temp1)
	{
		size1++;
		temp1=temp1->next;
	}
	while(temp2)
	{
		size2++;
		temp2=temp2->next;
	}
	if(size1<size2)
		return 0;
	else if(size1>size2)
		return 1;
	else
	{
		while(head1->next)
		{
			if(head1->data>head2->data)
				return 1;
			else if(head1->data<head2->data)
				return 0;
			    
			head1=head1->next;
			head2=head2->next;
		}
		if(head1->data>=head2->data)
			return 1;
	}
	return 0;
}
