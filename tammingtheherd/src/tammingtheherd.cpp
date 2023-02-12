//============================================================================
// Name        : tammingtheherd.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int m[101], n;
int dp[101][101][101];
int sic(int s, int t, int x){
	if (x== 0){
		return m[s] != t;
	} else {
		return m[s] != 0;
	}
}
int d(int s, int t, int x){
	//fout << t << " " << s << endl;
	if (s == n-1 && x > 1){
		return (1<<29);
	}
	if (s == n-1 && x == 1){
		return m[s] != 0;
	}
	if (s == n-1 && x == 0){
		return m[s] != t;
	}
	if (dp[s][t][x] > 0){
		return dp[s][t][x];
	}
	if (x == 0){
		int tot = 0;
		int org = t;
		for (int i = s; i < n;i++){
			if (m[i] != t){
				tot++;
			}
			t++;
		}
		dp[s][org][x] = tot;
		return tot;
	}
	int ma = (1<<30);
	ma = min(ma, (m[s]!= 0)+d(s+1, 1, x-1));
	//fout << (m[t]!= 0)+d(s+1, 1, x-1) << " 0 " << ma << endl;
	ma = min(ma, (m[s]!= t)+d(s+1, t+1, x));
	//fout << (m[t]!= t)+d(s+1, t+1, x) << " 1 " << ma<< endl;
	dp[s][t][x] = ma;
	return ma;
}
int main() {
	ifstream fin("taming.in");
	ofstream fout("taming.out");
	fin >> n;
	for (int i = 0; i <= n;i++){
		for (int l = 0; l <=n; l++){
			for (int j = 0; j <= n;j++){
				dp[i][l][j] = 0;
			}
		}
	}
	for (int i = 0; i < n;i++){
		fin >> m[i];
	}
	for (int i = 1; i <= n;i++){
		fout << d(1, 1, i-1)+(m[0]!= 0) << "\n";
	}
	return 0;
}
