#include<iostream>

using namespace std;

class Heap{

private:
int* heap;
int size;

public:
Heap(){
heap= new int[50];
size=0;
}

~Heap(){
}

void insert(int element){
heap[size]= element;
size++;
heapifyUp(size-1);
}

int removeMax(){
int max=heap[0];
heap[0]= heap[size-1];
//swap(heap[0], heap[size-1]);
size--;
heapifyDown(0);
return max;
}

int getParent(int index){
return (int)((index-1)/2);
}

int getLeft(int index){
if((2*index+1)>=size)
	return -1;
return 2*index+1;
}

int getRight(int index){
if((2*index+2)>=size)
	return -1;
return 2*index+2;
}


void heapifyUp(int index){

int parent= getParent(index);
if(heap[index]> heap[parent])
	{
	swap(heap[index], heap[parent]);
	heapifyUp(parent);
	return;
	}
else return;
}

void heapifyDown(int index){
int left= getLeft(index);
int right= getRight(index);	
if(left == -1)	//since heap is a complete binary tree absence of the left node indicates a leaf node, hence it can't go below that point
	return;
if(right == -1)
	{
	if(heap[left]>heap[index])
		swap(heap[index], heap[left]);
	return;
	}

int child= heap[left]>=heap[right]?left:right;

if(heap[child]>= heap[index])
	{
	swap(heap[index], heap[child]);
	heapifyDown(child);
	}
else return;
}

void print(){
cout<<"Heap: ";
for(int i=0; i<size; i++){
	cout<<heap[i]<<endl;
}
cout<<endl;
}

void heapSort(){
cout<<"sorted elements:"<<endl;
for(int i=0; i<5; i++)
	cout<<removeMax()<<endl;
}
};


void swap(int &n, int &m){
int temp=n;
n=m;
m=temp;
}

int main()
{	
Heap myHeap;	
myHeap.insert(5);
myHeap.insert(8);
myHeap.insert(12);
myHeap.insert(10);
myHeap.insert(15);	
//cout<<"The elements are:"<<endl;
//myHeap.print();	
myHeap.heapSort();
return 0;
} 
