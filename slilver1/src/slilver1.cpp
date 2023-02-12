//============================================================================
// Name        : slilver1.cpp
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
int n,tot= 0,c= 0;
int a[1000000];
int main() {
	ifstream fin("sort.in");
	ofstream fout("sort.out");
	fin >> n;
	for (int i = 0; i < n;i++){
		fin >> a[i];
	}
	bool s = false;
	while (!s){
		s = true;
		tot++;
		for (int i = 0; i <= n-2-c;i++){
			if (a[i+1] < a[i]){
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				s = false;
			}
		}
		c++;
	}
	fout << tot;
	return 0;
}
