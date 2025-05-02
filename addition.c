#include "apc.h"
// Function to perform addition of two large numbers
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    //initializing temporary pointers for traversing
    Dlist *temp1 = *tail1; //pointer to the tail of the first number
    Dlist *temp2 = *tail2; //pointer to the tail of the second number
    int carry = 0, sum = 0;//initializes carry flag and sum
    
    //loop through the lists untill two lists become empty
    while (temp1 || temp2)
    {
        if (temp1)
        {
            sum = temp1->data;// Add the data of the first number
            temp1 = temp1->prev;// Move to the previous node
        }
        if (temp2)
        {
            sum = sum + temp2->data;// Add the data of the second number
            temp2 = temp2->prev;// Move to the previous node
        }


        sum = sum + carry;//add carry from previous step
        carry = 0;//rest carry

        //checkin if sum more than 9 to set the carry
        if (sum > 9)
        {
            sum = sum % 10;//extracting the unit digit of the sum
            carry = 1;//set carry flag
        }

        //insert digit into result list
        insert_first(headR, tailR, sum);
        sum = 0;//reset sum
    }

    // If there's a remaining carry, insert it into the result
    if (carry)
        insert_first(headR, tailR, carry);

    //removing leading zeros
    while ((*headR)->data == 0 && (*headR)->next != NULL)
    {
        (*headR) = (*headR)->next;
        (*headR)->prev = NULL;
    }
    return 1;//return success
}


// Function to insert a new node with given data at the first
int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));//allocates memory for the new node

    // If the node is not created the returning failure
    if (!new)
    {
        return 0;
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    // If the list is empty then inserting the node as first node
    if (!*head && !*tail)
    {
        *head = *tail = new;
        return 1;
    }

    //Insert the new node at the beginning of the list
    new->next = *head;
    if (*head)
        (*head)->prev = new;//update head to point to the new node
    *head = new;
    return 1;
}
