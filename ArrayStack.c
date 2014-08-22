#include<stdio.h>
#define size 10

int tos=0;
int stack[size];

int push(int n)
{
  if(!isFull(stack))
  {
		stack[tos]=n;
		tos=tos+1;
		return 1;
	}
 	else
 	{
 		return 0;
 	}
}
	 
int isFull(int a[])
{
	if(tos>=10)
 	      return 1;
	else 
	      return 0;
}

int pop(int *n)
{
	if(!isEmpty(stack))
	{
 	    *n=stack[tos];
 	    tos=tos-1;
	    return 1;
	}
	else
	{
	   return 0;
	}
}
	 
int isEmpty(int a[])
{
	if(tos<0)
	   return 1;
	else
	   return 0;
}

int peep(int *n)
{
	if(!isEmpty(stack))
	{
 	   *n=a[tos];
	    return 1;
	}
	else
	   return 0;
}
	 
int main()
{
	  int r,v,c;
  	push(3);
  	peep(&v);
   	printf("The top element is %d\n",v);
  	push(4);
  	push(5);
  	peep(&v);
		pop(*r);
  	peep(stack,&v);
	  printf("The top element is %d\n",v);
  	return 0;
 }

