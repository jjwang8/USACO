//============================================================================
// Name        : program2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,pos[100],cl[100];
int back(int po){
	for (int i = 0; i < n;i++){
		if (pos[i] == po){
			return i;
		}
	}
}
int main() {
	ifstream fin("shuffle.in");
	ofstream fout("shuffle.out");
	fin >> n;
	for (int i = 0;i < n;i++){
		fin >> pos[i];
	}
	for (int i = 0;i < n;i++){
		fin >> cl[i];
	}
	for (int i = 0;i < 3;i++){
		int temp[100];
		for (int l = 0;l < n;l++){
			temp[back(l+1)] = cl[l];
		}
		for (int l = 0;l < n;l++){
			cl[l] = temp[l];
		}
	}
	for (int i = 0;i < n;i++){
		fout << cl[i] << endl;
	}
	return 0;
}
