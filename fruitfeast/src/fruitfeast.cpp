//============================================================================
// Name        : fruitfeast.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
int t, a, b;
bool x[5005000];
bool n[5005000];
int main() {
	ifstream fin("feast.in");
	ofstream fout("feast.out");
	fin >> t;
	fin >> a;
	fin >> b;
	x[0] = 1;
	for (int i =0;i <= t; i++){
		if (x[i] == 1){
			if (i+a <= t){
				x[i+a] = 1;
			}
			if (i+b <= t){
				x[i+b] = 1;
			}
		}
	}
	//fout << " a" << endl;
	for (int i = t; i >= 1;i--){
		if (x[i] == 1){
			//fout << i << endl;
			//if (i/2 == 2){
			//	cout << i << endl;
			//}
			n[i/2] = 1;
		}
	}
	//fout << "a" << endl;
	for (int i =0;i <= t;i++){
		if (n[i] == 1){
			if (i+a <= t){
				n[i+a] = 1;
			}
			if (i+b <= t){
				n[i+b] = 1;
			}
		}
	}
	for (int i = t; i >= 1;i--){
		if (n[i] == 1 || x[i] == 1){
			fout << i << endl;
			break;
		}
	}
	return 0;
}
