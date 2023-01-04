#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,L;
	string arr[100001];
	cin >> n >> L;
	//input and solve
	for (int i=1;i<=n;i++){
		cin >> arr[i];
	}
	int tmp;
	for (int i=1;i<=n;i++){
		tmp = L - arr[i].length();
		for (int j=1;j<=tmp;j++)
			cout << "0";
		cout << arr[i] << endl;
	}
	return 0;
}
