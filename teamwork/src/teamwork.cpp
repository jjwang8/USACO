//============================================================================
// Name        : teamwork.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
int n, k, a[11000];
int dp[10001][10001];
int d(int s, int e){
	if (e-s == 0){
		return a[s];
	}
	if (dp[s][e] > 0){
		return dp[s][e];
	}
	if (e-s <= k-1){
		int ma = 0;
		for (int i = 0; i <= e-s; i++){
			ma = max(a[s+i], ma);
		}
		dp[s][e] = ma*(e-s+1);
		return ma*(e-s+1);
	}
	int ma = 0;
	for (int i = 0;i < k;i++){
		int res = d(s, s+i)+d(s+i+1, e);
		//cout << res << " " << s << " " << i << endl;
		ma = max(ma, res);
	}
	dp[s][e] = ma;
	return ma;
}
int main() {
	cin >> n;
	cin >> k;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	cout << d(0, n-1) << endl;
	return 0;
}
