#include <bits/stdc++.h>
using namespace std;
#define N 1000000007

unsigned long int Exp(unsigned long int a, unsigned long int b){
	if (a > N) a = a % N;
	if (b == 1) return a;
	if (b % 2 != 0) return (a*(Exp(a,b-1) % N)) % N;
	unsigned long int res;
	res = Exp(a,b/2) % N;
	return (res*res) % N;
}

int main(){
	unsigned long int a,b;
	cin >> a >> b;
	cout << Exp(a,b);
	return 0;
}
