#include <bits/stdc++.h>
using namespace std;

int arr[10][10],col[10][10] = {0},row[10][10] = {0},square[4][4][10] = {0};
int cnt;
int check(int v, int r, int c){
	if (row[r][v] == 1) return 0;
	if (col[c][v] == 1) return 0;
	if (square[r/3][c/3][v] == 1) return 0;
	return 1;
}

//void solution(){
//	for (int i=1;i<=9;i++){
//		for (int j=1;j<=9;j++)
//			cout << arr[i][j] << ' ';
//		cout << endl;
//	}
//}

void Try(int r,int c){
	if (arr[r][c] != 0){
		if (r == 8 && c == 8) cnt++;
			else{
				if (c==8) Try(r+1,0);
				else Try(r,c+1);
			}
	}else{
		for (int v = 1;v<=9;v++){
			if (check(v,r,c)){
				arr[r][c] = v;
				row[r][v] = 1;
				col[c][v] = 1;
				square[r/3][c/3][v] = 1;
				if (r == 8 && c == 8) cnt++;
				else{
					if (c==8) Try(r+1,0);
					else Try(r,c+1);
				}
				arr[r][c] = 0;
				row[r][v] = 0;
				col[c][v] = 0;
				square[r/3][c/3][v] = 0;
			}
		}
	}
}

int main(){
	//Input data
	for (int i=0;i<9;i++)
		for (int j=0;j<9;j++){
			cin >> arr[i][j];
			if (arr[i][j] != 0){
				row[i][arr[i][j]] = 1;
				col[j][arr[i][j]] = 1;
				square[i/3][j/3][arr[i][j]] = 1;
			}	
		}
	//Solve
	cnt = 0;
	Try(0,0);
	cout << cnt;
	return 0;
}
