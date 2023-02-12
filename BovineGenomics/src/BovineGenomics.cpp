//============================================================================
// Name        : BovineGenomics.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_map>
using namespace std;
int n,m;
string a[505] = {};
int mi = 0;
int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < n;i++){
		cin >> a[i];
	}
	for (int i = 1; i <= m;i++){

		for (int l = 0; l < m-(i-1);l++){
			bool temp = 1;
			unordered_map<string, bool> dic;
			dic[a[0].substr(0, i)] = 1;
			for (int j = 1; j < n;j++){
				cout << a[j].substr(l, i) << endl;
				if (dic[a[j].substr(l, i)]){
					temp = 0;
					break;
				}
				dic[a[j].substr(l, i)] = 1;

			}
			if (temp){
				mi = i;
				i = m+1;
				break;
			}
		}
	}
	cout << mi << endl;
	return 0;
}
