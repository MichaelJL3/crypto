#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void insert(struct node *head, int n){
	struct node *new=malloc(sizeof(struct node));
	while(head->next!=NULL)
		head=head->next;

	new->val=n;
	new->next=head->next;
	head->next=new; 
}

struct node* find(struct node *head, int n){
	struct node* curr=head;
	while(curr){
		if(curr->val==n)
			break;
		
		curr=curr->next;
	}
	return curr;
}

void list_n(struct node *head){
	struct node* curr=head;
	while(curr!=NULL){
		printf("ind: %d\n", curr->val);
		curr=curr->next;
	}
}