//============================================================================
// Name        : Promgram1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n, b1[4], b2[4], t[4], tot = 0, mx = 0, my = 0;
bool a[10000][10000];
int main() {
	ifstream fin("billboard.in");
	ofstream fout("billboard.out");
	for (int i = 0; i < 4; i++) {
		fin >> b1[i];
		if (mx > b1[i] && (i == 0 || i == 2)) {
			mx = b1[i];
		} else if (my > b1[i] && (i == 1 || i == 3)) {
			my = b1[i];
		}
	}
	for (int i = 0; i < 4; i++) {
		fin >> b2[i];
		if (mx > b2[i] && (i == 0 || i == 2)) {
			mx = b2[i];
		} else if (my > b2[i] && (i == 1 || i == 3)) {
			my = b2[i];
		}
	}
	for (int i = 0; i < 4; i++) {
		fin >> t[i];
		if (mx > t[i] && (i == 0 || i == 2)) {
			mx = t[i];
		} else if (my > t[i] && (i == 1 || i == 3)) {
			my = t[i];
		}
	}
	int b1a = (b1[3] - b1[1]) * (b1[2] - b1[0]);
	int b2a = (b2[3] - b2[1]) * (b2[2] - b2[0]);
	int ta = (t[3] - t[1]) * (t[2] - t[0]);
	cout << mx << " " << my << endl;
	for (int i = 0;i < 4;i++){
		if (i == 0 || i == 2){
			b1[i] += abs(mx);
		} else if (i == 1|| i == 3){
			b1[i] += abs(my);
		}
	}
	for (int i = 0;i < 4;i++){
			if (i == 0 || i == 2){
				b2[i] += abs(mx);
			} else if (i == 1|| i == 3){
				b2[i] += abs(my);
			}
		}
	for (int i = 0;i < 4;i++){
			if (i == 0 || i == 2){
				t[i] += abs(mx);
			} else if (i == 1|| i == 3){
				t[i] += abs(my);
			}
		}
	for (int i = b1[1]; i < b1[3]; i++) {
		for (int l = b1[0]; l < b1[2]; l++) {
			a[i][l] = true;
		}
	}
	for (int i = b2[1]; i < b2[3]; i++) {
		for (int l = b2[0]; l < b2[2]; l++) {
			a[i][l] = true;
		}
	}
	for (int i = t[1]; i < t[3]; i++) {
		for (int l = t[0]; l < t[2]; l++) {
			if (a[i][l] == true) {
				tot++;
			}
		}
	}
	fout << (b1a + b2a) - tot;
	return 0;
}
