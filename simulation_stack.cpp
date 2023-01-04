#include <bits/stdc++.h>
using namespace std;

int main(){
	stack<int> St;
	string tmp;
	int a;
	while(1){
		cin >> tmp;
		if (tmp == "#") break;
		if (tmp == "PUSH"){
			cin >> a;
			St.push(a);
		}
		if (tmp == "POP"){
			if (St.empty()) cout << "NULL" << endl;
			else{
				cout << St.top() << endl;
				St.pop();
			}
		}
	}
	return 0;
}
