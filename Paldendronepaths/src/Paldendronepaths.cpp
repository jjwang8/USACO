//============================================================================
// Name        : Paldendronepaths.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#define m 1000000007
using namespace std;
unsigned long long n, c;
char a[600][600];
unsigned long long dp[600][600][600];
unsigned long long d(unsigned long long s, unsigned long long r1, unsigned long long r2){
	if (dp[s][r1][r2] > 0){
		return dp[s][r1][r2];
	}
	unsigned long long x1 = r1;
	unsigned long long y1 = s-r1;
	unsigned long long x2 = r2;
	unsigned long long y2 = (n-(s-((n-1)-r2))-1);
	if (s == n-1){
		if (x1 != x2 || y1 != y2){
			return 0;
		}
		//cout << ++c << endl;
		return 1;
	}
	if (x1 > x2 || y1 > y2){
		return 0;
	}
	//cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << s << endl;
	//cout << a[x1][y1] << " " << a[x2][y2] << endl;
	unsigned long long tot = 0;
	if (a[x1+1][y1] == a[x2-1][y2]){
		tot = (tot+d(s+1, x1+1, x2-1))%m;
	}
	if (a[x1+1][y1] == a[x2][y2-1]){
		tot = (tot+d(s+1, x1+1, x2))%m;
	}
	if (a[x1][y1+1] == a[x2-1][y2]){
		tot = (tot+d(s+1, x1, x2-1))%m;
	}
	if (a[x1][y1+1] == a[x2][y2-1]){
		tot = (tot+d(s+1, x1, x2))%m;
	}
	dp[s][r1][r2] = tot;
	return tot;
}
int main() {
	ifstream fin("palpath.in");
	ofstream fout("palpath.out");
	fin >> n;
	for (unsigned long long i = 0; i < n;i++){
		for (unsigned long long l = 0;l < n;l++){
			fin >> a[i][l];
		}
	}
	if (a[0][0] != a[n-1][n-1]){
		cout << "0" << endl;
		return 0;
	}
	cout << d(0, 0, n-1) << endl;
	return 0;
}
