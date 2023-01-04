#include <bits/stdc++.h>
using namespace std;
int n,c;
int x[100000000];
bool check(int D){
	int current = x[1];
	int num = 1;
	for (int i=2;i<=n;i++)
		if (current + D <= x[i]){
			current = x[i];
			num++;
		}
	
	return (num >= c);
}

int find(int min,int max){
	int l = min;
	int r = max;
	while (l < r){
		int mid = (l+r+1) >> 1;
		if (check(mid) == true) l = mid;
		else r = mid - 1;
	}
	
	return l;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> c;
		for (int i=1;i<=n;i++)
			cin >> x[i];
	
		sort(x+1,x+n+1);
	
		cout << find(1,(x[n]-x[1])) << ' ';
	}
	return 0;
}
