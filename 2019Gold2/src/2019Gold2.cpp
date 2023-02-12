//============================================================================
// Name        : 2019Gold2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
int n, m, c[100002];
vector<vector<int> > a(100001);
int main() {
	ifstream fin("pump.in");
	ofstream fout("pump.out");
	for (int i = 1; i <= n;i++){
		cin >> c[i];
	}
	for (int i = 0; i < n-1;i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		a[temp[0]].push_back(temp[1]);
		a[temp[1]].push_back(temp[2]);
	}

	return 0;
}
