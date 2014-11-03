#include<iostream>
using namespace std;
int Partition(int *a,int p,int r)
{
	int x = a[r];
	int i = p-1;
	for(int j=p;j<=r-1;j++)
	{
		if(a[j]<=x)
		{
			i++;
			int t = a[i];
			a[i]= a[j];
			a[j] = t;
		}
	}
	int q = a[i+1];
	a[i+1] = a[r];
	a[r] = q;
	return i+1;
}
void qsort(int *a,int p,int r)
{
	int q;
	if(p<r)
	{
		q = Partition(a,p,r);
		qsort(a,p,q-1);
		qsort(a,q+1,r);
	}
	return;
}
int main()
{
	int a[10];
	char b[10];
	for(int i =0;i<10;i++)
		cin>>a[i];
	qsort(a,0,9);
	for(int i =0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
