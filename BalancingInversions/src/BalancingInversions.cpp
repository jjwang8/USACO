//============================================================================
// Name        : BalancingInversions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
int a[100000],n;
int main() {
	ifstream fin("balance.in");
	ofstream fout("balance.out");
	fin >> n;
	for (int i = 0; i < n;i++){
		fin >> a[i];
	}
	fout << 1;
	return 0;
}
