#include <stdio.h>
#include<conio.h>

#define QUEUE_SIZE 3

typedef struct {
int q[QUEUE_SIZE];
int first,last;
int count;
} queue;


void init_queue(queue *q)
{
q->first = 0;
q->last  = -1;
q->count = 0;
}

void enqueue(queue *q,int x)
{

q->last = (q->last + 1) % QUEUE_SIZE;
if(q->last==q->first&&q->count!=0)
   printf("Max capacity reached");
else {
q->q[ q->last ] = x;
q->count = q->count + 1;
}
}

int dequeue(queue *q)
{
if(q->count==0)
            return -1;
int x = q->q[ q->first ];
q->first = (q->first + 1) % QUEUE_SIZE;
q->count = q->count - 1;
return x;
}

int main()
{
queue q;
int x;
init_queue(&q);
enqueue(&q,1);
enqueue(&q,2);
enqueue(&q,3);
enqueue(&q,4);
while (q.count)
printf("%d\n",dequeue(&q)); 
getch();
return 0;
}
