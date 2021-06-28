// Given a linked list(singly - linked, non - circular), write a program to swap the kth node from beginning
// with the kth last node in the list. Note that the length of the list is not known.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};

void swap_kth_begin_last(struct Node *head, int n)		// Function to get the nth node from the last of a linked list
{
	int len = 0, i;
	struct Node *temp = head, *temp2 = head;

	while (temp != NULL)	// count the number of nodes in Linked List
	{
		temp = temp->next;
		len++;
	}

	if (len < n)			// check if value of n is not more than length of the linked list
	{
		printf("enter value of n less than length of the Linked List");
		return;
	}

	temp = head;
	
	for (i = 1; i < len - n + 1; i++)		// get the (len-n) th node from the beginning
		temp = temp->next;

	for (i = 1; i < n; i++)					// get the n th node from the beginning
		temp2 = temp2->next;

	int swap = temp->data;
	temp->data = temp2->data;
	temp2->data = swap;

	temp = head;
	for (i = 0; i < len; i++)
	{
		printf(" %d ", temp->data);
		temp = temp->next;
	}
}

Node* push(struct Node *head_ref, int new_data)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack Overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = head_ref;
		head_ref = new_node;
		return head_ref;
	}
}

int main()
{
	struct Node *head = NULL;		// Start with the empty list 

	head = push(head, 20);			// create linked list 35->15->4->20
	head = push(head, 4);
	head = push(head, 15);
	head = push(head, 35);

	swap_kth_begin_last(head, 3);
	
	_getch();
}