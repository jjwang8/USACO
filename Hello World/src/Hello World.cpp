//============================================================================
// Name        : test2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
int n,m;
int c[100001];
vector<vector<int> > p(100001);
//unordered_map<char,int> f;
//queue<int, unordered_map<int, int> > q;
int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < n;i++){
		cin >> c[i];
	}
	for (int i = 0; i < n-1;i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		p[temp[0]].push_back(temp[1]);
		p[temp[1]].push_back(temp[2]);
	}
	return 0;
}
