//============================================================================
// Name        : Delegation.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int> > a(100005);
int sp(int val, int x, int par){
	if (a[x].size() == 1){
		return x-1;
	}
	int tot = 0;
	int con = 0;
	for (int i = 0; i < a[val].size();i++){
		if (a[val][i] == par){
			continue;
		}
		int temp = sp(a[val][i], x, val);
		tot += temp;
		if (temp != 0){
			con++;
		}
		if (temp == -1){
			return -1;
		}
	}
	if (a[x].size() == 2){
		if (tot == 0){
			return x-1;
		}
		return tot-1;
	}
	if (tot == x-1 && con <= 2){
		return 0;
	} else if (tot < x-1 && con <= 1){
		if (tot == 0 && con == 0){
			return x-1;
		}
		return tot-1;
	}
	return -1;
}
int main() {
	cin >> n;
	for (int i = 0; i < n-1;i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		a[temp[0]].push_back(temp[1]);
		a[temp[1]].push_back(temp[0]);
	}
	int ans[100005] = {};
	for (int i = 1; i < n;i++){
		ans[i] = 0;
		if (n%i == 0){
			if (sp(1,i, 1) == 0){
				ans[i] = 1;
			}
		}
	}
	for (int i = 1; i < n;i++){
		cout << (int)ans[i] << endl;
	}
	return 0;
}
