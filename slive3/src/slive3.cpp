//============================================================================
// Name        : slive3.cpp
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
int n;
int mas = 0;
int mast = 0;
int mat = 0;
int matt = 0;
int a[250][250];
int r[250][250];
vector<vector<int> > r2;
void print(){
	for (int i = 0; i < n;i++){
		for (int l = 0; l < n;l++){
			cout << r2[i][l];
		}
		cout << endl;
	}
}
int get(int x, int y, int w) {
	if ((x < 0 || x >= n || y < 0 || y >= n)) {
		return -1;
	} else {
		if (w == 0) {
			if (a[x][y] != -1) {
				return a[x][y];
			}
		} else if (w == 1) {
			if (r[x][y] != -1) {
				return r[x][y];
			}
		} else if (w == 2) {
			if (r2[x][y] != -1) {
				return r2[x][y];
			}
		}
	}
	return -2;
}
void cs(int v, int x, int y) {
	r[x][y] = 1;
	mast++;
	int m[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
	for (int i = 0; i < 4; i++) {
		if (get(x + m[i][0], y + m[i][1], 0) == v
				&& get(x + m[i][0], y + m[i][1], 1) == 0) {
			cs(v, x + m[i][0], y + m[i][1]);
		}
	}
}
void ts(int v, int v2, int x, int y) {
	r2[x][y] = 1;
	matt++;

	int m[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
	for (int i = 0; i < 4; i++) {
		if (v2 == -1) {
			if (get(x + m[i][0], y + m[i][1], 0) != -1) {
				ts(v, get(x + m[i][0], y + m[i][1], 0), x + m[i][0],
						y + m[i][1]);
				r2.assign(r2.size(),vector<int> (n,0));
				if (matt > mat){
					mat = matt;
				}
				matt = 0;
			}
		} else {
			if ((get(x + m[i][0], y + m[i][1], 0) == v2
					|| get(x + m[i][0], y + m[i][1], 0) == v) && get(x + m[i][0], y + m[i][1], 2) == 0) {
				ts(v, v2, x + m[i][0], y + m[i][1]);
			}
		}
	}
}
int main() {
	ifstream fin("multimoo.in");
	ofstream fout("multimoo.out");
	fin >> n;

	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			a[i][l] = -1;
			r[i][l] = 0;
		}
		vector<int> t(n, 0);
		r2.push_back(t);
	}
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			fin >> a[i][l];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			if (r[i][l] == 0) {
				cs(a[i][l], i, l);
				if (mast > mas) {
					mas = mast;
				}
				mast = 0;
				ts(a[i][l],-1,i,l);
			}
		}
	}
	//cout << "aaa" << endl;
	fout << mas << endl;
	fout << mat << endl;
	return 0;
}
