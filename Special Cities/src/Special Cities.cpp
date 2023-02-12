//============================================================================
// Name        : Special.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<string> a;
vector<string> b;
int n;
int main() {
	ifstream fin("citystate.in");
	ofstream fout("citystate.out");
	fin >> n;
	for (int i = 0; i < n;i++){
		string temp[2];
		fin >> temp[0];
		fin >> temp[1];
		a.push_back(temp[0].substr(0,2)+temp[1]);
		b.push_back(temp[1]+temp[0].substr(0,2));
	}
	sort(a.begin().a.end());
	sort(b.begin().b.end());
	return 0;
}
