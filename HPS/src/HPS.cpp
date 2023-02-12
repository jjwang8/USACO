//============================================================================
// Name        : HPS.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int n;
int k;
char a[100005] = {};
int dp[100005][21][3] = {{{}}};
char dic[3] = {'H', 'P', 'S'};
bool che(char x, char y){
	if (x == 'H' && y == 'S'){
		return 1;
	} else if (x == 'S' && y == 'P'){
		return 1;
	} else if (x == 'P' && y == 'H'){
		return 1;
	} else {
		return 0;
	}
}
int f(int x, int am, int l){
	if (x == n){
		return 0;
	}
	if (dp[x][am][l] > 0){
		return dp[x][am][l];
	}
	if (am == 0){
		cout << x << " " << am << " " << l << endl;
		dp[x][am][l] = f(x+1, am, l)+che(dic[l], a[x]);
		return dp[x][am][l];
	}
	int cha = max(max(f(x+1, am-1, 0)+che('H', a[x]), f(x+1, am-1, 1)+che('P', a[x])), f(x+1, am-1, 2)+che('S', a[x]));
	//cout << x << am << l << " " << max(cha, f(x+1, am, l)+che(dic[l], a[x])) << endl;
	dp[x][am][l] = max(cha, f(x+1, am, l)+che(dic[l], a[x]));
	return dp[x][am][l];
}
int main() {
	cin >> n;
	cin >> k;

	for (int i = 0; i < n;i++){
		cin >> a[i];
	}
	//cout << f(0, k, 0) << f(0,k,1) << f(0,k,2) << endl;
	cout << max(f(0, k, 0), max(f(0,k,1), f(0,k,2))) << endl;
	return 0;
}
