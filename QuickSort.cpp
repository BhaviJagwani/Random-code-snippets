#include<iostream>
//#include<conio.h>

using namespace std;

int partition( int *a, int p, int r)
{
int x= a[p];
int i=p-1, j=r+1;
while(true)
	{
	do {j--;}
	while(a[j]>x);
	do {i++;}
	while(a[i]<x);
	if(i<j)
		{
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		}
	else return j;
	}
}

void QuickSort(int *a, int p, int r)
{
int q;
if(p<r)
	{
	q=partition(a, p, r);
	QuickSort(a, p, q);
	QuickSort(a, q+1,r);
	}
}

int main()
{
int *array, n=0;
cout<<"enter the number of elements to sort: ";
cin>>n;
array= new int[n];
cout<<"enter the elements of the array: ";
for(int i=0; i<n;i++)
	{
	cin>>array[i];
	}
QuickSort(array, 0, n-1);
for (int i=0; i<n; i++)
     {
          cout<< array[i]<<endl;
      }
return 0;
}
