#include <bits/stdc++.h>
using namespace std;

map<int, bool> mark;

int main(){
	int n,L,m;
	cin >> n >> L >> m;
	int tmp,maxId;
	maxId = 0;
	//input data and pre_process
	for (int i=1;i<=n;i++){
		cin >> tmp;
		mark[tmp] = true;
		if (tmp > maxId) maxId = tmp;
	}
//	if (n+m > maxId) maxId = m+n;
	int check = 0;
	int i = 0;
	while (check != m){
		i++;
		if (i > maxId) maxId = i;
		if (mark[i]) continue;
		else{
			check++;
			mark[i] = true;	
		}
	}
//	char *its;
	
	for (i=1;i<=maxId;i++)
		if (mark[i]){
//			its = itoa(i);
			string str;
			stringstream ss;
			ss<<i;
			ss>>str;
			tmp = L - str.length();
			for (int j=1;j<=tmp;j++)
				cout << "0";
			cout << i << endl;
			
		}
	return 0;
}
