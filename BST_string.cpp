#include <bits/stdc++.h>
using namespace std;
//build BST
typedef struct Node{
	string str;
	struct Node* left;
	struct Node* right;
//	int index;
}Node;

Node* makeNode(string& data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->str = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void addNode(Node* &r, string& data){
//	Node* newNode = makeNode(data);
	if (r){
		if (r->str == data)
			return;
		if (r->str < data)
			addNode(r->left, data);
		if (r->str > data)
			addNode(r->right, data);
	}else{
		r = makeNode(data);
	}
}

void deleteTree(Node* r){
	if (r){
		deleteTree(r->left);
		deleteTree(r->right);
		delete(r);
	}
}

int findNode(Node* r, string& data){
	if (r){
		if (r->str == data) return 1;
		if (r->str < data) return findNode(r->left, data);
		if (r->str > data) return findNode(r->right, data);
	}
	return 0;
}

void checkBST(Node* r){
	if (r){
		cout << r->str << endl;
		//printf("r->str\n");
		checkBST(r->left);
		checkBST(r->right);
	}
}

Node* root;// root of binary search tree

int main(){
	root = NULL;
	string tmp;
	//input
	while(1){
		cin >> tmp;
		if (tmp == "*") break;
		addNode(root, tmp);
	}
	//checkBST
//	checkBST(root);
	//query
	while(1){
		string data;
		cin >> tmp;
		if (tmp == "***") break;
		if (tmp == "find"){
			cin >> data;
			cout << findNode(root, data) << endl;
		}
		if (tmp == "insert"){
			cin >> data;
			if(findNode(root, data)) cout << "0\n";
			else{
				addNode(root, data);
				cout << "1\n";
			}
		}
	}
	deleteTree(root);
	return 0;
}
