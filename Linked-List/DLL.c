#include<stdio.h>
#include<stdlib.h>
typedef struct doubly
{
	int item;
	struct doubly *left;
	struct doubly *right;
}list;
list *create(int val)
{
	list *new = (list *)malloc(sizeof(list)*1);
	new->item = val;
	new->left = NULL;
	new->right = NULL;
	return new;
}
list *insert(list *head,int val)
{
	if(head==NULL)
	{
		return create(val);
	}
	else
	{
		list *new = (list *)malloc(sizeof(list)*1);
		new->item = val;
		new->left = NULL;
		new->right = head;
		head = new;
		return head;
	}
}
list *insert_e(list *head,int val)
{
	if(head==NULL)
	{
		return create(val);
	}
	else
	{
		list *l = head;
		list *new = (list *)malloc(sizeof(list)*1);
		new->item = val;
		new->right = NULL;
		while(l->right!=NULL)
		{
			l=l->right;
		}
		l->right = new;
		new->left = l;
		return head;
	}
}
list * delete(list *head)
{
	list *l = head;
	if(head == NULL)
	{
		printf("Underflow\n");
		return head;
	}
	else
	{
		head = head->right;
		free(l);
		return head;		
	}
}
list * delete_e(list *head)
{
	list *l = head,*p;
	if(head == NULL)
	{
		printf("Underflow\n");
		return head;
	}
	else if(head->right == NULL)
	{
		head = head->right;
		free(l);
		return head;		
	}
	else
	{
		while((l->right)->right!=NULL)
		{
			l = l->right;
		}
		p = l->right;
		l->right= NULL;
		free(p);
		return head;
	}		
}
list *delete_v(list *head,int val)
{
	list *l = head,*p;
	if(l == NULL)
	{
		printf("Underflow\n");
		return head;
	}
	else if(l->right == NULL)
	{
		if(l->item == val)
		{
			return delete(head);
		}
		else
		{
			printf("Not found\n");
			return head;
		}
	}
	else
	{
		while(l!=NULL)
		{
			
			if(l->item == val)
			{
				if(l->left == NULL)
				{
					head = l->right;
					free(l);
					return head;
				}
				else if(l->right == NULL)
				{
					l->left = NULL;
					p->right = NULL;
					free(l);
					return head;
				}	
				else
				{	
					l->left = l->right;
					p->right = l->left;
					free(l);
					return head;
				}
			}
			else
			{
				p=l;
				l = l->right;	
				l->left = l;
			}
		}
		printf("Not found\n");
		return head;
	}		
}
void find(list *head,int val)
{
	int found = 0;
	list *l=head;
	while(l!=NULL)
	{
		if(l->item==val)
		{
			found = 1;
			break;
		}
		else
			l = l->right;
	}
	if(found)
		printf("Found\n");
	else
		printf("Not found\n");
}
void display(list *head)
{	
	list *l = head;
	if(l == NULL)
		printf("Empty");
	else
	{
		while(l!=NULL)
		{
			printf("%d ",l->item);
			l = l->right;
		}
	}
	printf("\n");
}	
int main()
{
	list *head = NULL;
	char ch,j;
	int v,n,i;
	
		printf("1.Insert n elements\n");
		printf("2.Insert n elements at end\n");
		printf("3.Delete element\n");
		printf("4.Delete element at end\n");
		printf("5.Delete particular element\n");
		printf("6.Display\n");
		printf("7.Exit\n");
	while(1)
	{
		printf("Enter choice");
		scanf("%c",&ch);
		switch(ch)
		{
			case '1': 
				printf("Enter value of n\n");
				scanf("%d",&n);
				printf("Enter new element\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&v);
					head=insert(head,v);
				}
				break;
			case '2':
				printf("Enter value of n\n");
				scanf("%d",&n);
				printf("Enter new element\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&v);
					head=insert_e(head,v);
				}
				break;
			case '3':
				head=delete(head);
				break;
			case '4':
				head=delete_e(head);
				break;
			case '5':
				printf("Enter element to be deleted\n");
				scanf("%d",&v);
				head=delete_v(head,v);
				break;
			case '6':
				display(head);
				break;
			case '7':
				exit(1);
				break;
			default:
				printf("Error\n");
				scanf("%c",&j);
		}
		scanf("%c",&j);
	}
	return 0;
}		
