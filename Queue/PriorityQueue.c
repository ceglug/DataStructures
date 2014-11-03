#include<stdio.h>
#include<stdlib.h>
int MAX;
typedef struct l
{
	struct l *next;
	int item;
	int key;
}queue;
queue *insert(queue *head,int key)
{
	queue *temp = malloc(sizeof(queue)*1);
	temp->key = key;
	printf("\nEnter value");
	scanf("%d",&(temp->item));
	if(temp->key>MAX)
		MAX=key;
	if(head==NULL)
	{
		head=temp;
		temp->next = NULL;
		return head;
	}
	else
	{
		queue *p = head,*q;
		while(p!=NULL)
		{
			if(p->key == temp->key)
			{
				temp->next = p->next;
				p->next = temp;
				return head;
			}
			else
			{
				q = p;
				p = p->next;
			}
		}
		q->next = temp;
		temp->next  = NULL;
		return head;
	}
}
queue *delete(queue *head)
{
	if(head==NULL)
	{
		printf("EMPTY\n");
		return NULL;
	}
	else if(head->key == MAX)
	{
		queue *p=head;
		head = head->next;
		free(p);
		return head;
	}
	else
	{
		queue *p=head,*q;
		while(p!=NULL)
		{
			if(p->key == MAX)
			{
				q->next = p->next;
				free(p);
				return head;
			}
			else
			{
				q = p;
				p = p->next;
			}
		}
		printf("\nNOT FOUND");
	}
}
void display(queue *head)
{
	queue *p = head;
	printf("The elements are\n");
	while(p!=NULL)
	{
		printf("%d\n",p->item);
		p = p->next;
	}
}
int main()
{
	MAX = 0;
	queue *head = NULL;
	head = insert(head,1);
	head = insert(head,2);
	head = insert(head,3);
	head = insert(head,2);
	display(head);
	head = delete(head);
	display(head);
	return 0;
}	
			
