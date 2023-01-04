#include <bits/stdc++.h>
using namespace std;

int n,x[100001];

void solution(){
	for (int i=1;i<=n;i++)
		cout << x[i];
	cout << endl;
}

int check(int i,int k){
	if (x[k-1] == 1 && i == 1) return 0;
	return 1;
}

void Try(int k){
	for (int i=0;i<=1;i++){
		if (check(i,k)){
			x[k] = i;
			if (k == n) solution();
			else Try(k+1);
		}
	}
}

int main(){
	x[0]=0;
	cin >> n;
	Try(1);
	return 0;
}
