//============================================================================
// Name        : Gold320.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
using namespace std;
int n;
vector<vector<int> > p(100001);
bool res[100001];
bool fin(int x, int org, int y){
	bool temp = 0;
	if (x == 0){
		if (p[y].size() == 1){
			return 1;
		}
		for (int i = 0; i < p[y].size();i++){
			bool = fin(org,org,p[y][i]);
		}
	}
	fin(x-1, y);
}
int main() {
	ifstream fin("");
	ofstream fout("");
	cin >> n;
	for (int i = 0; i < n-1;i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		p[temp[0]].push_back(temp[1]);
		p[temp[1]].push_back(temp[0]);
	}
	for (int i = 1; i <= (n-1)/2;i++){
		if (i == 1){
			res[i] = 1;
			continue;
		}
		if ((n-1)/i*i != n-1){
			res[i] = 0;
			continue;
		}
		res[i] = fin(i, i);

	}
	return 0;
}
