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
#include <cmath>
using namespace std;
int n, tot = 0, c = 0, ma = 1;
int a[1000000];
int d [1000000];
int main() {
	ifstream fin("sort.in");
	ofstream fout("sort.out");
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}
	int l = n - 1;
	for (int i = 0; i < n-1;i++){
		d[i] = a[i+1]-a[i];
	}
	for (int i = 0; i < n;i++){
		if (d[i] < 0){
			int temp = d[i];
			for (int l = i; l >= 0;l--){
				if (temp >= 0){
					if (abs(l-i) > ma){
						ma = abs(l-i);
					}
					break;
				}
				temp += d[l-1];
			}
		}
	}
	fout << ma+1;
	return 0;
}
