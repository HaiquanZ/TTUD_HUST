#include <bits/stdc++.h>
using namespace std;

typedef struct position{
	int row;
	int col;
	int cnt;
}pos;

int main(){
	int n,m,r,c,a[901][901];
	//Input
	cin >> n >> m >> r >> c;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin >> a[i][j];
	//Solve
	int check=0;
	pos tmp;
	tmp.cnt = 0;
	tmp.row = r;
	tmp.col = c;
	queue<pos> Q;
	Q.push(tmp);
	
	while(!Q.empty()){
		tmp = Q.front();
		Q.pop();
		a[tmp.row][tmp.col] = 1;
// 		cout << tmp.row << " " << tmp.col << endl;
		if (tmp.row == 1 || tmp.row == n || tmp.col == 1 || tmp.col == m){
		    check = 1;
			break;

		}else{
			pos tmp2;
			//turn left
			if (!a[tmp.row][tmp.col + 1]){
				tmp2 = tmp;
				tmp2.col ++;
				tmp2.cnt ++;
				Q.push(tmp2);
				a[tmp.row][tmp.col + 1] = 1;
			}
			//turn right
			if (!a[tmp.row][tmp.col - 1]){
				tmp2 = tmp;
				tmp2.col --;
				tmp2.cnt ++;
				Q.push(tmp2);
				a[tmp.row][tmp.col - 1] = 1;
			}
			//top
			if (!a[tmp.row - 1][tmp.col]){
				tmp2 = tmp;
				tmp2.row --;
				tmp2.cnt ++;
				Q.push(tmp2);
				a[tmp.row - 1][tmp.col] = 1;
			}
			//bottom
			if (!a[tmp.row + 1][tmp.col]){
				tmp2 = tmp;
				tmp2.row ++;
				tmp2.cnt ++;
				Q.push(tmp2);
				a[tmp.row + 1][tmp.col] = 1;
			}
		}
	}
	
	if(check) cout << tmp.cnt+1;
	else cout << "-1";
	
	
	return 0;
}
