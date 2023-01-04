#include <bits/stdc++.h>
using namespace std;

int main(){
	//input data
	int n;
	int arr[1000001];
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> arr[i];
	//solve
	int count = 0;
	for (int i=2;i<n;i++)
		if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) count++;
	cout << count;
	return 0;
}
