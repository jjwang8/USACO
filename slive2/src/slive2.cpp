//============================================================================
// Name        : slive2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int n,t;
vector<int> a;
int main() {
	ifstream fin("lemonade.in");
	ofstream fout("lemonade.out");
	fin >> n;
	for (int i = 0; i < n;i++){
		int temp;
		fin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(),a.end());
	for (int i = n-1,l = 0; i >= 0;i--,l++){
		if (a[i] >= l){
			t++;
		} else {
			break;
		}
	}
	fout << t;
	return 0;
}
