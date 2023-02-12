//============================================================================
// Name        : 248.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int n,a[250],dp[300][300];
int f(int x, int y){
	//cout << x << y << endl;
	if (y-x == 1){
		return a[x];
	}
	if (dp[x][y] > 0){
		return dp[x][y];
	}
	int ma = 0;
	for (int i = x; i < y;i++){
		if (i-x == 0){
			continue;
		}
		int v1 = f(x,i);
		int v2 = f(i,y);
		dp[x][i] = v1;
		dp[i][y] = v2;
		//cout << v1 << v2;
		if (v1 == v2){
			ma = max(ma, v1+1);
		} else {
			ma = max(ma, max(v1, v2));
		}
		//cout << ma << x << y << endl;
	}
	return ma;
}
int main() {
	ifstream fin("");
	ofstream fout("");
	cin >> n;
	for (int i =0;i < n;i++){
		//cout << i << endl;
		cin >> a[i];
	}
	//for (int i =0;i < n;i++){
	//	cout << a[i] << endl;
	//}
	cout << f(0,n) << endl;
	return 0;
}
