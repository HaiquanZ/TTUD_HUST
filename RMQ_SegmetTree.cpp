#include <bits/stdc++.h>
using namespace std;

#define N 100001
int arr[N];
int tree[N * 4];
int n;

//build segment tree 
void buildTree(int id, int left, int right){
	if (left == right){
	    tree[id] = arr[left];
	    return;
	}
	
	int  mid;
	mid = (right + left) / 2;
	buildTree(id * 2, left, mid);
	buildTree(id * 2 + 1, mid + 1, right);
	
	tree[id] = (tree[id * 2] < tree[id * 2 + 1]) ? tree[id * 2] : tree[id * 2 + 1];
}

int getVal(int id, int left, int right, int u, int v){
	if (u > right || v < left) return INT_MAX;
	
	if (left == right) return tree[id];
	
	int mid;
	mid = (left + right) / 2;
	return min(getVal(id * 2, left, mid, u, v), getVal(id * 2 + 1, mid + 1, right, u, v));
	
}

int main(){
	//Input
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> arr[i];
	buildTree(1,1,n);
	//Check Segment Tree
// 	for(int i=1;i <= 32; i++)
// 		cout << tree[i] << ' ';
		
	//Solve
	int t;
	int u,v;
	unsigned long int sum = 0;
	cin >> t;
	while(t--){
		cin >> u >> v;
		sum += getVal(1,1,n,u+1,v+1);
	}
	cout << sum;
	return 0;
}
