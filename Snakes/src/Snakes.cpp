//============================================================================
// Name        : Snakes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
int n,k,a[401],q[401][401];
int dp(int l, int sw, bool g, int ma, int en){
	if (g == 0 && q[l][sw] != -1){
		return q[l][sw];
	}
	if (l == n-1){
		if (sw > 1){
			return 0;
		} else {
			if (g ==1){
				if (a[l] > ma){
					return (a[l]-ma)*(l-en);
				} else {
					return ma-a[l];
				}
			} else {
				return 0;
			}
		}
	}
	if (sw == 0){
		if (a[l] > ma){
			return dp(l+1,0,1,a[l],en)+(a[l]-ma)*(l-en);
		} else {
			return ma-a[l]+dp(l+1,0,1,ma,en);
		}
	}
	if (g == 1){
		if (a[l] > ma){
			q[l+1][sw-1] = dp(l+1,sw-1,0,a[l+1],l+1);
			return min(dp(l+1,sw,1,a[l],en),q[l+1][sw-1])+((a[l]-ma)*(l-en));
		} else {
			q[l+1][sw-1] = dp(l+1,sw-1,0,a[l+1],l+1);
			return min(dp(l+1,sw,1,ma,en),q[l+1][sw-1])+ma-a[l];
		}
	} else {
		q[l+1][sw-1] = dp(l+1,sw-1,0,a[l+1],l+1);
		return min(dp(l+1,sw,1,a[l],l),q[l+1][sw-1]);
	}
}
int main() {
	ifstream fin("snakes.in");
	ofstream fout("snakes.out");
	fin >> n;
	fin >> k;
	for (int i = 0; i < n;i++){
		fin >> a[i];
	}
	for (int i = 0; i < 401;i++){
		for (int l = 0; l < 401;l++){
			q[i][l] = -1;
		}
	}
	fout << dp(0,k,1,a[0],0);
	return 0;
}
