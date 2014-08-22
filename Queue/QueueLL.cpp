#include<iostream>
using namespace std;
typedef struct l
{
	int data;
	struct l *next;
}node;
node * push(node *head, int ndata)
{
	node *element = new node;
	node *marker;
	marker = head;
	element->data = ndata;
	element->next = NULL;
	if (marker == NULL)
	{
		head = element;
	}
	else
	{
		while (marker->next != NULL)
		{
			marker = marker->next;
		}
		marker->next = element;
	}
	return head;
}
node * pop(node *head)
{
	node *marker;
	marker = head;
	if (marker == NULL)
		cout << "Not possible";
	else if (marker->next == NULL)
	{
		head = NULL;
		delete marker;
	}
	else
	{
		head = marker->next;
		delete marker;
	}
	return head;
}
void display(node *head)
{
	node *marker;
	marker = head;
	while (marker != NULL)
	{
		cout <<marker->data<<" ";
		marker = marker->next;
	}
	cout << endl;
}
int main()
{
	node *head = NULL;
	int data;
	while (1)
	{
		char choice;
		cout << "1.Push" << endl;
		cout << "2.Pop" << endl;
		cout << "3.Display" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter choice :";
		cin >> choice;
		switch (choice)
		{
		case '1':
			cout<<"Enter element";
			cin >> data;
			head = push(head, data);
			break;
		case '2':
			head = pop(head);
			break;
		case '3':
			display(head);
			break;
		case '4':
			exit(1);
			break;
		default:
			cout << "Error" << endl;
		}
	}
	return 0;
}

