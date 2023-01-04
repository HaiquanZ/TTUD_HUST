#include <bits/stdc++.h>
using namespace std;
#define N 1000000007

int mark[1000][1000] = {0};

int C(int k, int n){
    if (k == 0 || k == n) mark[k][n] = 1;
    else{
    	if (mark[k][n] == 0)
    		mark[k][n] = (C(k-1,n-1)%N + C(k,n-1)%N)%N;
	}
    return mark[k][n];
}

int main(){
    int k,n;
    cin >> k >> n;
    cout << C(k,n);
    return 0;
}
