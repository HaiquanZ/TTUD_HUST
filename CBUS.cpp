#include <bits/stdc++.h>
using namespace std;
int n,K,c[23][23],cmin,ans[23];
int T = 0;
int x[23] = {0};
int mark[23] = {0};
int load = 0;
int res = INT_MAX;

int check(int i,int k){
	if (mark[i]) return 0;
	if (i<=n && load>=K) return 0;
	if (i > n && (mark[i-n] == 0)) return 0;
	if (load == 0 && i > n) return 0;
	return 1;
}

void solution(){
	T += c[x[2*n]][0];
	if (T < res){
		res = T;
//		for (int i=1;i<=2*n;i++)
//			ans[i] = x[i];
	}
	T -= c[x[2*n]][0];
	
}

void Try(int k){
	for (int i=1;i<=2*n;i++){
		if(check(i,k)){
			mark[i] = 1;
			x[k] = i;
			if (i<=n) load++;
			else load--;
			T += c[x[k-1]][i];
			if (k==2*n) solution();
			else{
				if (T+cmin*(2*n-k+2) < res) 
					Try(k+1);
			}
			T -= c[x[k-1]][i];
			mark[i] = 0;
			if (i<=n) load--;
			else load++;
		}
	}
}

void checkRoad(){
	for (int i=1;i<=2*n;i++)
		cout << ans[i] << " ";
}

int main(){
	//Input
	cin >> n >> K;
	int cmin = INT_MAX;
	for (int i=0;i<=2*n;i++)
		for (int j=0;j<=2*n;j++){
			cin >> c[i][j];
			if (c[i][j] < cmin && i != j) cmin = c[i][j];
		}
//	cout << cmin << endl;
	//Solve
	x[0] = 0;
	Try(1);
	cout << res << endl;
//	checkRoad();
	return 0;
}
