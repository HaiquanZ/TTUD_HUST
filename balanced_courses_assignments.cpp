#include <bits/stdc++.h>
using namespace std;

int n,m, a[12][32] = {0}, con[32][32] ={0};
int load[12] = {0},x[32] = {0};

int check(int i,int k){
	
	return 1;
}

void Try(int k){
	for (int i=1;i<=n;i++){
		if(check(i,k)){
			load[k]++;
			x[i] = 1;
			if (k==m) solution();
			else Try(k+1);
		}
	}
}

int main(){
	//Input
	cin >> m >> n;
	int tmp1,tmp2,tmp3;
	for (int i=1;i<=m;i++){
		cin >> tmp;
		for (int j=1;j<=tmp;j++){
			cin >> tmp2;
			a[i][tmp2] = 1;
		}
	}
	cin >> tmp1;
	for (int i=1;i<=tmp1;i++){
		cin >> tmp2 >> tmp3;
		con[tmp2][tmp3] = 1;
		con[tmp3][tmp2] = 1;
	}
	//Solve
	Try(1);
	cout << res;
	return 0;
}
