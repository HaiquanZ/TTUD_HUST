#include <bits/stdc++.h>
using namespace std;

int n,x[100001];

void solution(){
	for (int i=1;i<=n;i++)
		cout << x[i];
	cout << endl;
}

void Try(int k){
	for (int i=0;i<=1;i++){
		x[k] = i;
		if (k == n) solution();
		else Try(k+1);
	}
}

int main(){
	cin >> n;
	Try(1);
	return 0;
}
