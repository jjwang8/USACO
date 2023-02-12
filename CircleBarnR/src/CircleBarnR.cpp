//============================================================================
// Name        : CircleBarnR.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int a[105] = {};
int n,k;
int dp(int pos, int am, int st){
	if (am == 0){
		int tot = 0;
		for (int i = pos+1; i != st;i++){
			if (i == n){
				i = 0;
				if (i == st){
					break;
				}
			}
			if (pos > i){
				tot += a[i]*(n-1-pos+(i+1));
			} else {
				tot += a[i]*(i-pos);
			}
		}
		return tot;
	}
	int mi = (1<<30);
	int tot = 0;
	for (int i = pos+1; i != st;i++){
		if (i == n){
			i = 0;
			if (i == st){
				break;
			}
		}
		cout << i << " " << am-1 << " " << st << " " << dp(i, am-1, st) << endl;
		mi = min(dp(i, am-1, st)+tot, mi);
		if (pos > i){
			tot += a[i]*(n-1-pos+(i+1));
		} else {
			tot += a[i]*(i-pos);
		}
	}
	return mi;
}
int main() {
	cin >> n;
	cin >> k;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	int mi = (1<<30);
	for (int i = 0; i < n;i++){
		mi = min(mi, dp(i, k-1, i));
		cout << dp(i, k-1, i) << endl;
	}
	cout << mi << endl;
	return 0;
}
