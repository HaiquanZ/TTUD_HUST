#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
	string str;
	struct Node* next;
}Node;

int count_tran = 0;
int total_money = 0;
int total_acc = 0;
map<string, int> count_money_acc;
map<string, int> mark_string;
char acc[100][22];

void list_sorted(){
	//sort
	char tmp[20];
	for(int i=1;i<=total_acc;i++){
    	for(int j=1;j<=total_acc;j++){
      		if(strcmp(acc[j-1], acc[j])>0){
        		strcpy(tmp, acc[j-1]);
        		strcpy(acc[j-1], acc[j]);
        		strcpy(acc[j], tmp);
      		}
    	}
  	}
	//printf result
	for (int i=0;i<=total_acc;i++)
		cout << acc[i] << " "; 
	cout << endl;
		
}
int check_cycle(int k){
	if (k > total_acc+1) return 0;
	return 1;
	// buiding
}

int main(){
	string type;
	//input data
	do{
		cin >> type;
		if (type == "#") break;
		else{
			string acc1, acc2, time, atm;
			int money;
			cin  >> acc2 >> money >> time >> atm;
			acc1 = type;
			//?number_transactions
			count_tran++;
			//?total_money_transaction
			total_money += money;
			//?total_money_from_account
			count_money_acc[acc1] += money;
			if (mark_string[acc1] == 0){
				mark_string[acc1] = 1;
				int n = acc1.length();
				strcpy(acc[total_acc],acc1.c_str());
				total_acc++;
			}
			if (mark_string[acc2] == 0){
				mark_string[acc2] = 1;
				int n = acc1.length();
				strcpy(acc[total_acc],acc2.c_str());
				total_acc++;
			}
			//?cycle
				
		}
		
	
	}while(1);	
	//process query
	do{
		cin >> type;
		if (type == "#") break;
		if (type == "?number_transactions") cout << count_tran << endl;
		if (type == "?total_money_transaction") cout << total_money << endl;
		if (type == "?list_sorted_accounts") list_sorted();
		if (type == "?total_money_transaction_from"){
			string tmp;
			cin >> tmp;
			cout << count_money_acc[tmp] << endl;
		}
		if (type == "?inspect_cycle"){
			int k;
			string acc_start;
			cin >> acc_start >> k;
			check_cycle(k);
			cout << endl;
		}
	}while(1);
	return 0;
}
