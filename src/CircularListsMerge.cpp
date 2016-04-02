/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	struct node *result_head = NULL;
	struct node *walker1 = *head1;
	struct node *walker2 = *head2;
	struct node *r_walker = result_head;
	int len = 0;

	if (!walker1 && !walker2){
		return -1;
	}
	if (walker1 == NULL){
		while (walker2 != *head2){
			walker2 = walker2->next;
			len++;
		}
		*head1 = *head2;
		return len;
	}
	else if (walker2 == NULL){
		while (walker1 != *head1){
			walker1 = walker1->next;
			len++;
		}
		//*head1 = *head2;
		return len;
	}

	if ((*head1)->data < (*head2)->data){
		result_head = *head1;
		r_walker = result_head;
		walker1 = walker1->next;
	}
	else{
		result_head = *head2;
		r_walker = result_head;
		walker2 = walker2->next;
	}
	while (walker1 != *head1 && walker2 != *head2){
		if (walker1-> data <= walker2-> data){
			r_walker->next = walker1;
			r_walker = r_walker->next;
			walker1 = walker1->next;
		}
		else{
			r_walker->next = walker2;
			r_walker = r_walker->next;
			walker2 = walker2->next;
		}
		len++;
	}
	while (walker2 != *head2){
		r_walker->next = walker2;
		r_walker = r_walker->next;
		walker2 = walker2->next;
		len++;
	}
	while (walker1 != *head1){
		r_walker->next = walker1;
		r_walker = r_walker->next;
		walker1 = walker1->next;
		len++;
	}
	r_walker->next = result_head;
	*head1 = result_head;
	printf("\nReturning %d", len);
	return len;
}