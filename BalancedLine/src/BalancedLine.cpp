//============================================================================
// Name        : BalancedLine.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> a;
int n,q;
int ranlk[100000][100] = {};
int ranlk2[100000][100] = {};
void ranqryint(){
	for (int i = 0; i < n;i++){
		ranlk[i][0] = i;
	}
	for (int l = 1; (1<<l) <= n;l++){
		for (int i = 0; (i+(1<<l)-1) < n;i++){
			if (a[ranlk[i][l-1]] < a[ranlk[i+(1<<(l-1))][l-1]]){
				ranlk[i][l] = ranlk[i][l-1];
			} else {
				ranlk[i][l] = ranlk[i+(1<<(l-1))][l-1];
			}
		}
	}
}
void ranqryint2(){
	for (int i = 0; i < n;i++){
		ranlk2[i][0] = i;
	}
	for (int l = 1; (1<<l) <= n;l++){
		for (int i = 0; (i+(1<<l)-1) < n;i++){
			if (a[ranlk2[i][l-1]] > a[ranlk2[i+(1<<(l-1))][l-1]]){
				ranlk2[i][l] = ranlk2[i][l-1];
			} else {
				ranlk2[i][l] = ranlk2[i+(1<<(l-1))][l-1];
			}
		}
	}
}
int ranqry(int lef, int rit, bool mm){
	int si = (int)log2(rit-lef+1);
	if (mm){
		if (a[ranlk[lef][si]] <= a[ranlk[rit-(1<<si)+1][si]]){
			return a[ranlk[lef][si]];
		} else {
			return a[ranlk[rit-(1<<si)+1][si]];
		}
	} else {
		if (a[ranlk2[lef][si]] >= a[ranlk2[rit-(1<<si)+1][si]]){
			return a[ranlk2[lef][si]];
		} else {
			return a[ranlk2[rit-(1<<si)+1][si]];
		}
	}
}
int main() {
	cin >> n;
	cin >> q;
	for (int i = 0; i < n;i++){
		int temp;
		cin >>  temp;
		a.push_back(temp);
	}
	ranqryint();
	ranqryint2();
	for (int i = 0;i < q;i++){
		int temp[3];
		cin >> temp[0];
		cin >> temp[1];
		cout << ranqry(temp[0]-1,temp[1]-1,0)-ranqry(temp[0]-1,temp[1]-1,1) << endl;
	}
	return 0;
}
