#include <iostream>

using namespace std;

/*
Queue
*/
//----------------------------------------
#define QUEUE_SIZE 5 

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

void enqueue(queue *qu, int x)
{

qu->last = (qu->last + 1) % QUEUE_SIZE;
if(qu->last==qu->first)
   if(qu->count!=0)
   		cout<<"Max capacity reached";
	else {
		qu->q[ qu->first ]=x;
	}
else {
qu->q[ qu->last ] = x;}
//cout<<"enqueued "<<x<<endl;
qu->count = qu->count + 1;
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

bool isEmpty(queue *q){
	if(q->count == 0)
		return true;
	return false;
}

int getHead(queue *qu){
	return qu->q[qu->first];
}
/*
Graph
*/
//----------------------------------------
class Node
{
public:
	int key;
	Node* next;

};

class Graph
{
private:
	int size;
	Node* vertices;

public:
	Graph(int sizeNew){
		size= sizeNew;
		vertices= new Node[sizeNew];
		for(int i=0; i<sizeNew; i++){
			vertices[i].next= NULL;
			vertices[i].key= i;
		}
	}

	void addEdge(int u, int v){
		//cout<<"adding edge"<<endl;	
		Node* node= new Node;
		node->key= v;
		node->next= NULL;
		Node* temp= &vertices[u];
		while(temp->next !=NULL)
			temp= temp->next;
		temp->next= node;
		//cout<<"edge added "<<u<<v<<endl;
	}

	void bfs(int root){
		int colour[size];		// 0-> white, 1-> gray, 2-> black
		int parent[size];
		for(int i=0; i<size; i++){
			colour[i]= 0;
			parent[i]= -1;
		}

		colour[root]= 1;
		parent[root]= -1;
		queue q;
		init_queue(&q);
		enqueue(&q, root);
		while(!isEmpty(&q)){
			int u= getHead(&q);
			Node* temp= &vertices[u];
			//cout<<"Head "<<u<<endl;
			while(temp->next!=NULL){
				temp= temp->next;
				int index= temp->key;
				if(colour[index] == 0){
					colour[index]=1;
					parent[index]= temp->key;
					enqueue(&q, index);
				}
			}
			dequeue(&q);
			colour[u]= 2;
			cout<<vertices[u].key<<" ";
		}

		cout<<endl;
	}

	void dfs(){
		int colour[size];
		int parent[size];
		int duration=0;
		int discover[size];
		int finish[size];

		for(int i=0; i<size; i++){
			colour[i]=0;
			parent[i]= -1;
		}

		for(int u=0; u<size; u++){
			if(colour[u]==0)
				dfs_visit(u, colour, parent, discover, finish, &duration);
		}

		cout<<endl<<"Finish times:"<<endl;
		for(int i=0; i<size; i++)
			cout<<finish[i]<<"  ";
	}

	void dfs_visit(int u, int* colour, int* parent, int* discover, int* finish, int* duration){
		colour[u]=1;
		*duration+=1;
		discover[u]= *discover;
		Node* node= &vertices[u];
		while(node->next!=NULL){
			node= node->next;
			if(colour[node->key]== 0){
				parent[node->key]= u;
				dfs_visit(node->key, colour, parent, discover, finish, duration);
			}
		}
		colour[u]=2;
		*duration+=1;
		finish[u]= *duration;
		cout<<"Finish:"<<u<<" ";
	}

};

//------------------------------------------

int main(){

/*Graph graph(4);
graph.addEdge(0,2);
graph.addEdge(2,0);
graph.addEdge(1,2);
graph.addEdge(0,1);
graph.addEdge(2,3);
cout<<"BFS: ";
graph.bfs(2);
cout<<endl;
cout<<"DFS: ";
graph.dfs();
cout<<endl;*/
Graph graph(6);
graph.addEdge(0,1);
graph.addEdge(0,3);
graph.addEdge(3,1);
graph.addEdge(4,3);
graph.addEdge(1,4);
graph.addEdge(2,4);
graph.addEdge(2,5);
cout<<"DFS: ";
graph.dfs();
cout<<endl;

return 0;
}
	