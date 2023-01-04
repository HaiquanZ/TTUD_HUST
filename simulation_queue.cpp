#include <bits/stdc++.h>
using namespace std;

int main(){
	queue<int> Q;
	string tmp;
	int a;
	while(1){
		cin >> tmp;
		if (tmp == "#") break;
		if (tmp == "PUSH"){
			cin >> a;
			Q.push(a);
		}
		if (tmp == "POP"){
			if (Q.empty()) cout << "NULL" << endl;
			else{
				cout << Q.front() << endl;
				Q.pop();
			}
		}
	}
	return 0;
}
