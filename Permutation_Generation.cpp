#include <bits/stdc++.h>
using namespace std;

int mark[10001],n,x[10001];

void solution(){
	for (int i=1;i<=n;i++)
		cout << x[i] << ' ';
	cout << endl;
}

void Try(int k){
	for (int i=1;i<=n;i++){
		if (mark[i]){
			x[k] = i;
			mark[i] = 0;
			if (k==n) solution();
			else Try(k+1);
			mark[i] = 1;
		}
	}
}

int main(){
	cin >> n;
	for (int i=1;i<=n;i++)
		mark[i] = 1;
	Try(1);
	return 0;
}
