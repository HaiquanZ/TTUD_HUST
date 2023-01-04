#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[1000001];
	int n,M,cnt;
	cin >> n >> M;
	for (int i=0;i<n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	cnt=0;
	int i,j;
	i=0;j=n-1;
	while(i<j){
		if (arr[i]+arr[j]==M){
			cnt++;i++;j--;
		}
		if (arr[i]+arr[j]<M) i++;
		if (arr[i]+arr[j]>M) j--;
	}
	cout << cnt;
}
