//============================================================================
// Name        : CowArt.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int n, hum, cow;
string a[100], b[100], c[100];
typedef struct {
	int x;
	int y;
} xy;
queue<xy> cur;
int o[4] = { -1, 0, 1, 0 };
int p[4] = { 0, 1, 0, -1 };
char get(bool t,int x, int y){
	if (x < 0 || x >= n || y < 0 || y >= n){
		return '_';
	} else {
		if (t){
			return b[x][y];
		} else {
			return c[x][y];
		}
	}
}
void re(bool t, int x, int y, char let) {
	xy temp;
	if (cur.size() == 0){
		temp.x = x,temp.y = y;
		cur.push(temp);
		if (t){
			b[x][y] = 'X';
		} else {
			c[x][y] = 'X';
		}
	}
	for (int i = 0; i < cur.size(); i++) {
		for (int l = 0; l < 4; l++) {
			if (t && get(t,cur.front().x + o[l],cur.front().y + p[l]) == let) {
				b[cur.front().x + o[l]][cur.front().y + p[l]] = 'X';
				temp.x = cur.front().x + o[l], temp.y = cur.front().y + p[l];
				cur.push(temp);
			} else if (!t
					&& get(t,cur.front().x + o[l],cur.front().y + p[l]) == let) {
				c[cur.front().x + o[l]][cur.front().y + p[l]] = 'X';
				temp.x = cur.front().x + o[l], temp.y = cur.front().y + p[l];
				cur.push(temp);
			}
		}
		cur.pop();
	}
	if (cur.size() != 0){
		re(t, x, y, let);
	}
}
int main() {
	ifstream fin("cowart.in");
	ofstream fout("cowart.out");
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> a[i];
		b[i] = a[i];
		string temp = "";
		for (int l = 0; l < n; l++) {
			if (a[i][l] == 'G' || a[i][l] == 'R') {
				temp = temp + "T";
			} else {
				temp = temp + a[i][l];
			}
		}
		c[i] = temp;
	}
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			if (b[i][l] != 'X') {
				re(1, i, l, b[i][l]);
				hum++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			if (c[i][l] != 'X') {
				re(0, i, l, c[i][l]);
				cow++;
			}
		}
	}
	fout << hum << " " << cow;
	return 0;
}
