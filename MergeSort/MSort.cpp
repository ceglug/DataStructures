#include<iostream>
using namespace std;
void merge(int *a,int p,int q,int r)
{
	int i,j,k;
	int c[50];
	i = p;
	k = p;
	j = q+1;
	while(i<=q && j<=r)
	{
		if(a[i]<a[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++];
	}
	while(i<=q)
	{
		c[k++]=a[i++];
	}
	while(j<=r)
	{
		c[k++] =a[j++];
	}
	for(i=p;i<k;i++)
		a[i] = c[i];
}

void msort(int *a,int p,int r)
{
	int q;
	if(p<r)
	{
		q = (p+r)/2;
		msort(a,p,q);
		msort(a,q+1,r);
		merge(a,p,q,r);
	}
	return ;
}
int main()
{
	int a[10];
	char b[10];
	for(int i=0;i<10;i++)
		cin>>a[i];
	msort(a,0,9);
	for(int i=0;i<10;i++)
		cout<<a[i]<<"";
	cout<<endl;
	return 0;
}
