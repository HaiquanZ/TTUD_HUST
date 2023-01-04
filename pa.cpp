#include <bits/stdc++.h>
using namespace std;

char str[1001];

int solve(){
	stack<char> S;
	for (int i=0;i<strlen(str);i++){
		if (str[i] == '[' ||
			str[i] == '{' ||
			str[i] == '(' )
			S.push(str[i]);
		else{
			if (S.empty()) return 0;
			else{
				char tmp;
				tmp = S.top();
				S.pop();
				if (str[i] == ']' && tmp != '[') return 0;
				if (str[i] == ')' && tmp != '(') return 0;
				if (str[i] == '}' && tmp != '{') return 0;
			}
		}
	}
	if (S.empty()) return 1;
	else return 0;
}

int main(){
	cin >> str;
	cout << solve();
	return 0;
}
