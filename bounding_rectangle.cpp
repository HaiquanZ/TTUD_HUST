#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int x, y, min_x, max_x, min_y, max_y;
	min_x = 101;
	min_y = 101;
	max_x = 0;
	max_y = 0;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> x >> y;
		if (min_x > x) min_x = x;
		if (min_y > y) min_y = y;
		if (max_x < x) max_x = x;
		if (max_y < y) max_y = y;
		cin >> x >> y;
		if (min_x > x) min_x = x;
		if (min_y > y) min_y = y;
		if (max_x < x) max_x = x;
		if (max_y < y) max_y = y;
	}
	cout << (max_x - min_x) * (max_y - min_y);
	return 0;
}
