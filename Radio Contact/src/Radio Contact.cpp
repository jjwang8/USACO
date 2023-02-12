//============================================================================
// Name        : Radio.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int a[2],n,m,b[2];
string ap,bp;
int dis[1000][1000];
int dp[1001][1001];
int cal(int x, int y){
	if (x==n && y==m){
		return 0;
	}
	if (x == n || y == m){
		return (1<<30);
	}
	if (dp[x+1][y+1] > 0){
		return dp[x+1][y+1];
	}
	if (x == -1 || y == -1){

	}
	dp[x+1][y+1] = min(cal(x+1, y),min(cal(x,y+1),cal(x+1,y+1)))+dis[x][y];
	cout << x << " " << y << " " << dp[x][y]<< endl;
	return dp[x+1][y+1];
}
int main() {
	cin >> n;
	cin >> m;
	cin >> a[0];
	cin >> a[1];
	cin >> b[0];
	cin >> b[1];
	cin >> ap;
	cin >> bp;
	int tempa[2] = a;
	for (int i = 0; i <= n;i++){
		if (ap[i] == 'N'){
			a[1]++;
		} else if(ap[i] == 'E'){
			a[0]++;
		} else if (ap[i] == 'S'){
			a[1]--;
		} else if (ap[i] == 'W'){
			a[0]--;
		}
		int tempb[2];
		tempb[0] = b[0];
		tempb[1] = b[1];
		for (int l = 0;l <= m;l++){
			if (l == m){
				dis[i][l] = (tempa[0]-tempb[0])*(tempa[0]-tempb[0])+(tempa[1]-tempb[1])*(tempa[1]-tempb[1]);
			}
			if (bp[l] == 'N'){
				tempb[1]++;
			} else if(bp[l] == 'E'){
				tempb[0]++;
			} else if (bp[l] == 'S'){
				tempb[1]--;
			} else if (bp[l] == 'W'){
				tempb[0]--;
			}
			//cout << i << l << (a[0]-tempb[0])*(a[0]-tempb[0])+(a[1]-tempb[1])*(a[1]-tempb[1]) << endl;
			dis[i][l] = (a[0]-tempb[0])*(a[0]-tempb[0])+(a[1]-tempb[1])*(a[1]-tempb[1]);
			dp[i][l] = 0;
		}
	}
	cout << cal(-1,-1) << endl;
	return 0;
}
