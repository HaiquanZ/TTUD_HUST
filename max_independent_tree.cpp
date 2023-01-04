#include <bits/stdc++.h>
using namespace std;
//build adj-list
typedef struct Node{
	int value;
	struct Node* next;
}Node;

Node* makeNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

typedef struct Graph{
	int vertices;
	Node** list;
}Graph;

Graph* makeGraph(int v){
	Graph* g = (Graph*)malloc(sizeof(Graph));
	g->vertices = v;
	g->list = (Node**)malloc(v*sizeof(Node*));
	for (int i=0;i<v;i++)
		g->list[i] = NULL;
	
	return g;
}
Graph* g;
int w[100001], D[100001][2];
int n, mark[100001];

void postOrderUpdate(int r, int par){
	mark[r] = 1;
	Node* tmp;
	tmp = g->list[r];
	while(tmp){
		if (!mark[tmp->value]) postOrderUpdate(tmp->value, r);
		tmp = tmp->next;
	}
	if (par){
		D[par][1] = D[par][1] + D[r][0];
		D[par][0] = D[par][0] + max(D[r][0],D[r][1]);
	}
}

int DPonTree(){
	//root of tree is vertex 1
	postOrderUpdate(1,0);
	return max(D[1][0],D[1][1]);
}

int main(){
	//input data
	cin >> n;
	g = makeGraph(n+1);
	for (int i=1;i<=n;i++){
		cin >> w[i];
		D[i][0] = 0;
		D[i][1] = w[i];
		mark[i] = 0;
	}
	
	for (int i=1;i<n;i++){
		int a,b;
		cin >> a >> b;
		//insert b to adj-list of a
		Node* newNode; 
		newNode = makeNode(b);
		newNode->next = g->list[a];
		g->list[a] = newNode;
		//insert a to adj-list of b
		newNode = makeNode(a);
		newNode->next = g->list[b];
		g->list[b] = newNode;
	}
	//solve
	cout << DPonTree();
//	postOrderUpdate(1,0);
//	cout << D[1][0] << " - " << D[1][1];
//	for (int i=1;i<=9;i++){
//		cout << i << ": ";
//		Node* tmp = g->list[i];
//		while(tmp){
//			cout << tmp->value << " ";
//			tmp = tmp->next;
//		}
//		cout << endl;
//	}
	
	return 0;
}
