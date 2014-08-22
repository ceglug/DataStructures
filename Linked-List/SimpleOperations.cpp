#include<iostream>
using namespace std;

typedef struct n
{
	int data;
	struct n *next;
}node;

node *head=NULL;

//To insert at the beginning of the list
void insertatbegin(int ndata)
{
	node *p=new node;
	node *r;
	r=head;
	p->data=ndata;
	if(head==NULL)
	{
		head=p;
		p->next=NULL;
		
	}
	else
	{
		p->next=r;
		head=p;
	}
}

//To insert at the end of the list
void insertatend(int ndata)
{
	node *p=new node;
	node *r;
	r=head;
	p->data=ndata;
	p->next=NULL;
	if(r==NULL)
	{
		head=p;	
	}
	else
	{
		while(r->next!=NULL)
		{
			r=r->next;
		}	
		r->next=p;		
	}
}

//To delete at the beginning of the list
void deleteatbegin()
{
	node *p;
	p=head;
	if(p==NULL)
		cout<<"Not possible";
	else if(p->next==NULL)
	{
		head=NULL;
		delete p;
	}
	else
	{
		head=p->next;
		delete p;
	}
}

//To delete at the end of the list
void deleteatend()
{
	node *p,*l;
	p=head;
	if(p==NULL)
		cout<<"Not possible";
	else if(p->next==NULL)
	{
		head=NULL;
		delete p;
	}
	else
	{
		while(p->next!=NULL)
		{
			l=p;
			p=p->next;
		}
		l->next=NULL;
		delete p;
	}
	
}

//To display the contents of the list
void display()
{
	node *r;
	r=head;
	while(r!=NULL)
	{
		cout<<r->data<<" ";
		r=r->next;
	}
	cout<<endl;
}


int main()
{
	int a,i;
	char ch;
	while(1)
	{
		cout<<"1.Insert at begin"<<endl;
		cout<<"2.Insert at end"<<endl;
		cout<<"3.Delete at begin"<<endl;
		cout<<"4.Delete at end"<<endl;
		cout<<"5.Display"<<endl;
		cout<<"6.Exit"<<endl;
		cout<<"Enter choice :"<<endl;
		cin>>ch;
		switch(ch)
		{
			case '1':
				cout<<"Enter element"<<endl;
				cin>>a;
				insertatbegin(a);
				break;
			case '2':
				cout<<"Enter element"<<endl;
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
				break;
			default:
				cout<<"Error"<<endl;
		}
	}
	return 0;
}

