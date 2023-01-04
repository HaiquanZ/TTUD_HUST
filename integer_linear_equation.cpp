#include <bits/stdc++.h>
using namespace std;

int n,M,a[100001],cnt,T,R,x[100001];

int check(int i, int k){
	if (k < n) return 1;
	if (T + i*a[n] == M) return 1;
	else return 0;
}

void Try(int k){
	for (int i=1;i<=(M-T-R);i++){
		if (check(i,k)){
			x[k] = i;
			T += a[k]*i;
			R -= a[k+1];
			if (k == n) cnt++;
			else Try(k+1);
			T -= a[k]*i;
			R += a[k+1];
		}
	}
}

int main(){
	//Input
	cin >> n >> M;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	//Solve
	R = 0;
	for (int i=2;i<=n;i++)
		R += a[i];
	cnt = 0; T = 0;
	Try(1);
	cout << cnt;
	return 0;
}
