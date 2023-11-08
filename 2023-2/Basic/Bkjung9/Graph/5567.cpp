#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define SWAP(type,x,y)do{type t=x;x=y;y=t;}while(0)
#define MAX(a,b) a<b?b:a
#define MIN(a,b) a<b?a:b
#define max 505
typedef struct graphNode {
	int dest;
	graphNode* next;
}GraphNode;

typedef struct graph {
	int size;
	GraphNode* adj;
}Graph;

int visited[max]; 
int n, m, u, v;
int cnt = 0;

int Queue[max];
int head = 0, tail = 0, Queue_size = 0;

void Init_Graph_list(Graph *gph, int size) {
	visited[1]=1;
    gph->size = size+1;
	gph->adj = (GraphNode*)malloc(sizeof(GraphNode) * (size+1));
	for (int i = 1; i <= size; i++) {
		gph->adj[i].next = NULL;
	}
}

int Add_Undirected_Node(Graph* gph, int src, int dst) {
	GraphNode* temp = (GraphNode*)malloc(sizeof(GraphNode));
	temp->dest = dst;
	temp->next = gph->adj[src].next;
	gph->adj[src].next = temp;
	return 1;
}

int Add_Directed_Node(Graph* gph, int src, int dst) {
	return Add_Undirected_Node(gph, src, dst) && Add_Undirected_Node(gph, dst, src);
}

void Print_Graph_Node(Graph* gph) {
	GraphNode* head;
	for (int i = 1; i <= gph->size; i++) {
		head = gph->adj[i].next;
		printf("Node : [ %d ]: ", i);
		while (head) {
			printf(" -> %d ", head->dest);
			head = head->next;
		}
		printf("\n");
	}
}

void Queue_Enque(int x) {
	Queue[tail] = x;
	tail = (tail + 1) % max;
	Queue_size++;
}

int Queue_Deque() {
	int returndata = Queue[head];
	head = (head + 1) % max;
	return returndata;
}

int Queue_Is_Empty() {
	if (head == tail) 
		return 0;
	else
		return 1;
}

void First_Friend_Check(Graph* gph) {
	GraphNode* head = gph->adj[1].next;
	while (head) {
		if (!visited[head->dest]) {
			Queue_Enque(head->dest);
			visited[head->dest] = 1;
			cnt++;
		}
		head = head->next;
	}
}

void Final_Friend_Check(Graph* gph) {
	GraphNode* head;
	while (Queue_Is_Empty()) {
		head = gph->adj[Queue_Deque()].next;
		while (head) {
			if (!visited[head->dest]) {
				visited[head->dest] = 1;
				cnt++;
			}
			head = head->next;
		}
	}
}

int main() {
	Graph graph;
	scanf("%d", &n);
	scanf("%d", &m);
	Init_Graph_list(&graph, n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		Add_Directed_Node(&graph, u, v);
	}
	First_Friend_Check(&graph);
	Final_Friend_Check(&graph);
	//Print_Graph_Node(&graph);
	//for (int i = 1; i <= n; i++) {
	//	printf(" [ %d ] : %d\n", i, visited[i]);
	//}
	printf("%d\n", cnt);

	return 0;
}
