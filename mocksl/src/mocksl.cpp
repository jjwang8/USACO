#include <iostream>
#include <fstream>
#include <set>
#include <queue>
using namespace std;
int n, m;
string a[1000];
string j[1000];
string e[1000];
pair<int, int> f;
pair<int, int> b;
pair<int, int> temp;
queue<pair<int, int> > w;
int o = 0;
char get(int x, int y,bool t) {
	if (x < 0 || y < 0 || x >= n || y >= n) {
		return '1';
	} else {
		if (t == true){
			return j[x][y];
		} else {
			return e[x][y];
		}
	}
}
void print(){
	for (int i = 0; i < n;i++){
		cout << e[i] << endl;
	}
}
void p(char r) {
	w.push(f);
	j[f.first][f.second] = r;
	int s = w.size();
	for (int i = 0; i < s; i++) {
		int t[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
		j[w.front().first][w.front().second] = r;
		for (int l = 0; l < 4; l++) {
			if (get(w.front().first + t[l][0], w.front().second + t[l][1],true)
					== '0') {
				j[w.front().first + t[l][0]][w.front().second + t[l][1]] = r;
				temp.first = w.front().first + t[l][0], temp.second =
						w.front().second + t[l][1];
				w.push(temp);
			}
		}
		w.pop();
	}
	if (w.size() != 0){
	p(++r);
	}
}
void k(char r) {
	w.push(b);
	e[b.first][b.second] = r;
	int s = w.size();
	for (int i = 0; i < s; i++) {
		int t[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
		e[w.front().first][w.front().second] = r;
		print();
		for (int l = 0; l < 4; l++) {
			if (get(w.front().first + t[l][0], w.front().second + t[l][1],false)
					== '0') {
				e[w.front().first + t[l][0]][w.front().second + t[l][1]] = r;
				temp.first = w.front().first + t[l][0], temp.second =
						w.front().second + t[l][1];
				w.push(temp);

				cout << w.size() << endl;
			}
		}
		w.pop();
	}
	if (w.size() != 0){
		k(r+1);
	}
}
int main() {
	ifstream fin("std.in");
	ofstream fout("std.out");
	fin >> n;
	fin >> m;
	for (int i = 0; i < n; i++) {
		fin >> a[i];
		j[i] = a[i];
		e[i] = a[i];
		for (int l = 0; l < n; l++) {
			if (a[i][l] == 'B') {
				b.first = i;
				b.second = l;
			} else if (a[i][l] == 'F') {
				f.first = i;
				f.second = l;
			}
		}
	}
	cout << "aaa" << endl;
	k(1);
	p(1);
	for (int i = 0; i < m; i++) {
		int s, d;
		fin >> s;
		fin >> d;
		if (j[s - 1][d - 1] > e[s - 1][d - 1]) {
			fout << "BESSIE" << endl;
		} else if (j[s - 1][d - 1] < e[s - 1][d - 1]) {
			fout << "FJ" << endl;
		} else if (j[s - 1][d - 1] == e[s - 1][d - 1]) {
			fout << "TIE" << endl;
		}
	}
	return 0;
}
