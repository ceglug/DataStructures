#include<iostream>
#include<cstring>
using namespace std;
void heapcheck(int *a,int i,int last)
{
	int small=0,left=2*i,right=(2*i)+1;
	if(left<=last && a[left]<a[i])
		small = left;
	else
		small = i;
	if(right<=last && a[right]<a[small])
		small = right;
	if(small!=i)
	{
		int t  = a[small];
		a[small] = a[i];
		a[i] = t;
		heapcheck(a,small,last);
	}
	return;
}
void build(int *arr,int last)
{
	for(int i=last/2;i>0;i--)
	{
		heapcheck(arr,i,last);
	}
}
int main()
{
	int a[11],i;
	memset(a,-1,10);
	for(i=1;i<11;i++)
		cin>>a[i];
	build(a,10);
	for(i=1;i<11;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
