//============================================================================
// Name        : AngryCows.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
int r[50005][2] = {{}};
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n;i++){
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	a.push_back(0);
	r[0][0] = 0;
	r[n-1][1] = 1;
	for (int i = 1; i < n;i++){
		r[i][0] = max(a[i]-a[i-1], r[i-1][0]+1);
	}
	for (int i = n-2; i >= 0;i--){
		r[i][1] = max(a[i+1]-a[i], r[i+1][1]+1);
	}
	int mi = (1<<30);
	for (int i = 0; i < n;i++){
		int ans = max(r[i][0],r[i+1][1]);
		if (ans < (float)(a[i+1]-a[i])/2.0){

		}
		mi = min(mi, max(r[i][0],r[i+1][1]));
	}
	mi = min(mi, r[0][1]);
	cout << mi << endl;
	return 0;
}
