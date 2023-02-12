//============================================================================
// Name        : peomgram3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,a[101][2],c[3] = {7,7,7},pos[3] = {0,0,0},pre[3] = {0,0,0},tot = 0;
void m(){
	int ma = 0;
	for (int i = 0; i < 3;i++){
		if (ma < c[i]){
			ma = c[i];
		}
	}
	for (int i = 0;i < 3;i++){
		if (c[i] == ma){
			pos[i] = i+1;
		}
	}
}
int main() {
	ifstream fin("measurement.in");
	ofstream fout("measurement.out");
	fin >> n;
	for (int i = 0;i < 100;i++){
		a[i][0] = 0;
		a[i][1] = 0;
	}
	for (int i = 0;i < n;i++){
		int temp;
		string temp2;
		fin >> temp;
		fin >> temp2;
		if (temp2 == "Bessie"){
			a[temp][0] = 1;
			fin >> a[temp][1];
		} else if (temp2 == "Elsie"){
			a[temp][0] = 2;
			fin >> a[temp][1];
		} else {
			a[temp][0] = 3;
			fin >> a[temp][1];
		}
	}
	for (int i = 0;i < 101;i++){
		if (a[i][0] != 0){
			c[a[i][0]-1] += a[i][1];
			m();
			for (int l = 0;l< 3;l++){
				if (pre[l] != pos[l]){
					tot++;
					break;
				}
			}
			for (int l = 0;l < 3;l++){
				pre[l] = pos[l];
				pos[l] = 0;
			}
		}
	}
	fout << tot;
	return 0;
}
