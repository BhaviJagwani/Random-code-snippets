#include<iostream>

using namespace std;

typedef int stackElementType;

class Stack{
public:
Stack(int size);
~Stack();
bool push(stackElementType elmnt);
stackElementType getTop();
stackElementType pop();
bool isEmpty();
bool isFull();

private:
stackElementType *contents;
int top;
int maxSize;
};

Stack::Stack(int size)
{
contents= new stackElementType [size];
top=-1;
maxSize= size;
}

Stack::~Stack()
{
delete [] contents;
contents= NULL;
maxSize=0;
top=-1;
}

bool Stack::push(stackElementType elmnt)
{
if(isFull())
	return false;
contents[++top]= elmnt;
return true;
}

stackElementType Stack::pop()
{
if(isEmpty())
	return -1;
return contents[top--];
}

bool Stack::isEmpty()
{
if(top==-1)
	return true;
return false;
}

bool Stack::isFull()
{
if(top==maxSize-1)
	return true;
return false;
}

stackElementType Stack::getTop()
{
if(top!=-1)
return contents[top];
return -1;
}
