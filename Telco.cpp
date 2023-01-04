#include <bits/stdc++.h>
#include <string>
using namespace std;

map<string, int> count_phone_call;
map<string, long long> count_time_call;
string type;
int number_total_calls = 0;
int check = 1;
bool check_phone(string phone){
	if (phone.length() != 10) return false;
	for (char c : phone ){
		if (c < '0' || c > '9') return false;
	}
	return true;
}
long long convertTime(string time){
	long long hh = 60*60*((time[0] - 48)*10 + time[1] - 48);
	long long mm = 60*((time[3] - '0')*10 + time[4] - '0');
	long long ss = ((time[6] - '0')*10 + time[7] - '0');
	return hh+mm+ss;
}
long long count_time(string sTime, string eTime){
	long long start = convertTime(sTime);
	long long end = convertTime(eTime);
	return end - start;
}

int main(){
//	system("clear");
//	ios_base::sync_with_stdio(0);
//	cin.tie(NULL);
	
	do{
		cin >> type;
		if (type == "#") break;
		string p1, p2, date, sTime, eTime;
		cin >> p1 >> p2 >> date >> sTime >> eTime;
		
		number_total_calls++;
		
		if (check_phone(p1) == false || check_phone(p2) == false) check = 0;
		
		count_phone_call[p1]++;
		count_time_call[p1] += count_time(sTime, eTime);
	
	}while(1);	
	
	do{
		cin >> type;
		if (type == "#") break;
		if (type == "?check_phone_number") cout << check << endl;
		if (type == "?number_calls_from"){
			string tmp;
			cin >> tmp;
			cout << count_phone_call[tmp] << endl;
		}
		if (type == "?number_total_calls") cout << number_total_calls << endl;
		if (type == "?count_time_calls_from"){
			string tmp;
			cin >> tmp;
			cout << count_time_call[tmp] << endl;
		}
	}while(1);
	return 0;
}

