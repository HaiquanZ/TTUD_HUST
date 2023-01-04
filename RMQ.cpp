#include <bits/stdc++.h>
using namespace std;

int main(){
	//Input
	int n,a[10001],m;
	int ans = 0;
	cin >> n;
	for (int i=0;i<n;i++)
		cin >> a[i];
	cin >> m;
	//Solve
	for (int i=1;i<=m;i++){
		int start_pos, end_pos;
		cin >> start_pos >> end_pos;
		int min;
		min = a[start_pos];
		for (int j=start_pos + 1;j<=end_pos;j++)
			if (min > a[j]) min = a[j];
		ans += min;
	}
	cout << ans;
	return 0;
}
