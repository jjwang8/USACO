//============================================================================
// Name        : Gold3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int a[10010],n,k;
int dp[10010];
int ma(int s,int e){
	return *max_element(a+s,a+e);
}
int f(int s){
	int tot = 0;
	if (s == n-1){
		return a[n-1];
	}
	if (dp[s] > 0){
		return dp[s];
	}
	for (int i = 1; i <= k;i++){
		if (n-(s+i) < 0){
			continue;
		}
		int temp = (ma(s,s+i)*i+f(s+i));
		if (tot < temp){
			tot = temp;
			//cout << i << endl;
		}
	}
	dp[s] = tot;
	return tot;
}
int main() {
	ifstream fin("teamwork.in");
	ofstream fout("teamwork.out");
	fin >> n;
	fin >> k;
	for (int i = 0; i < n;i++){
		fin >> a[i];
	}
	fout << f(0) << endl;
	return 0;
}
