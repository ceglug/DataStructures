#include<iostream>
using namespace std;

typedef struct n
{
	int data;
	struct n *next;
}node;

node *head=NULL;

//To insert at the beginning of the list
void insertatbegin(int newdata)
{
	node *new_node=new node;
	node *copy_of_head;
	copy_of_head=head;
	new_node->data=newdata;
	if(head==NULL)
	{
		head=new_node;
		new_node->next=NULL;
		
	}
	else
	{
		new_node->next=copy_of_head;
		head=new_node;
	}
}

//To insert at the end of the list
void insertatend(int newdata)
{
	node *new_node=new node;
	node *copy_of_head;
	copy_of_head=head;
	new_node->data=newdata;
	new_node->next=NULL;
	if(copy_of_head==NULL)
	{
		head=new_node;	
	}
	else
	{
		while(copy_of_head->next!=NULL)
		{
			copy_of_head=copy_of_head->next;
		}	
		copy_of_head->next=new_node;		
	}
}

//To delete at the beginning of the list
void deleteatbegin()
{
	node *copy_of_head;
	copy_of_head=head;
	if(copy_of_head==NULL)
		cout<<"Not possible"<<endl;
	else if(copy_of_head->next==NULL)
	{
		head=NULL;
		delete copy_of_head;
	}
	else
	{
		head=copy_of_head->next;
		delete copy_of_head;
	}
}

//To delete at the end of the list
void deleteatend()
{
	node *copy_of_head,*prev;
	copy_of_head=head;
	if(copy_of_head==NULL)
		cout<<"Not possible"<<endl;
	else if(copy_of_head->next==NULL)
	{
		head=NULL;
		delete copy_of_head;
	}
	else
	{
		while(copy_of_head->next!=NULL)
		{
			prev=copy_of_head;
			copy_of_head=copy_of_head->next;
		}
		prev->next=NULL;
		delete copy_of_head;
	}
	
}

//To display the contents of the list
void display()
{
	node *copy_of_head;
	copy_of_head=head;
	while(copy_of_head!=NULL)
	{
		cout<<copy_of_head->data<<" ";
		copy_of_head=copy_of_head->next;
	}
	cout<<endl;
}


int main()
{
	int a;
	char ch;
	while(1)
	{
		cout<<"1.Insert at begin"<<endl;
		cout<<"2.Insert at end"<<endl;
		cout<<"3.Delete at begin"<<endl;
		cout<<"4.Delete at end"<<endl;
		cout<<"5.Display"<<endl;
		cout<<"6.Exit"<<endl;
		cout<<"Enter choice :";
		cin>>ch;
		switch(ch)
		{
			case '1':
				cout<<"Enter element";
				cin>>a;
				insertatbegin(a);
				break;
			case '2':
				cout<<"Enter element";
				cin>>a;
				insertatend(a);
				break;
			case '3':
				deleteatbegin();
				break;
			case '4':
				deleteatend();
				break;
			case '5':
				display();
				break;
			case '6':
				exit(1);
				break;
			default:
				cout<<"Error"<<endl;
		}
	}
	return 0;
}

