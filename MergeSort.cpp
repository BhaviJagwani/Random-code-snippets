#include <iostream>
#include <conio.h>

using namespace std;

void merge(int *a, int p, int q, int r)
{
 int copy[r-p+1];
 int i=p, j=q+1, k=0;
 while(i<=q&&j<=r)
       {
        if(a[i]<a[j]){
					copy[k++]=a[i++]; 
          }
				else copy[k++]=a[j++];
 }
 while(i<=q)
	 copy[k++]=a[i++];
 while(j<=r)
	 copy[k++]=a[j++];

for(int i=p,m=0;i<=r;i++,m++)
{
a[i]=copy[m];
}
 }
 
void mergeSort(int* a, int p, int r)
{ 
    if(r>p)
     {
       int q= (r+p)/2;
       mergeSort(a, p, q);
       mergeSort(a, q+1, r);
       merge(a, p, q, r);
           }
 }
  
int main()
{
    int n;
    int *array;
    
    cout<<"enter the number of elements in the array:";
    cin>>n;
    array=new int[n];
    cout<<"enter the elements of the array: ";
    for ( int i=0; i<n; i++)
     {
          cin>> array[i];
      }
      mergeSort(array, 0, n-1);
      cout<<endl;
      for ( int i=0; i<n; i++)
     {
          cout<< array[i]<<endl;
      }
      getch();
}
