#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
int mark[10], x[10];

int check(int i, int k){
	if (mark[i]) return 0;
	return 1;
}

void solution(){
	int N;
	N = x[4]*1000 + (x[1] - x[7] + x[5])*100 + (x[2] + x[6])*10 + 2*x[3] - 62;
	if (N == n) cnt++;
}

void Try(int k){
	for (int i=1;i<=9;i++)
		if (check(i,k)){
			x[k] = i;
			mark[i] = 1;
			if (k == 7) solution();
			else Try(k+1);
			mark[i] = 0;
		}
}

int main(){
	cin >> n;
	//solve
	for (int i=0;i<10;i++)
		mark[i] = 0;
	Try(1);
	cout << cnt;
	return 0;
}
