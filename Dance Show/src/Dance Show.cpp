//============================================================================
// Name        : Dance.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int n, tm;
vector<int> a;
int f(int s) {
	vector<int> temp(s, 0);
	for (int i = 0; i < s; i++) {
		temp[i] = a[i];
	}
	for (int i = s; i < a.size(); i++) {
		int mi = temp[0],al;
		for (int l = 0; l < s;l++){
			if (mi > temp[l]){
				mi = temp[l];
				al = l;
			}
		}
		temp[al] = temp[al]+a[i];
	}
	return max_element(temp.begin(),temp.end());
}
int main() {
	ifstream fin("cowdance.in");
	ofstream fout("cowdance.out");
	fin >> n;
	fin >> tm;
	for (int i = 0; i < n; i++) {
		int temp;
		fin >> temp;
		a.push_back(temp);
	}
	int m = f((n+1)/2);
	while (m != tm){

	}
	return 0;
}
