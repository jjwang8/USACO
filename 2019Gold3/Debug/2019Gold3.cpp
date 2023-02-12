//============================================================================
// Name        : 2019Gold3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <queue>
#include <iostream>
using namespace std;
int n, m,k;
string s;
int c[27][27];
int dp1[100001];
int d(int st, int e){
	int li[27];
	for (int i = 0; i < m;i++){
		li[i] = 0;
	}
	int mi = (1<<30);
	for (int i = st;i < e;i++){
		for (int l = 0; l < m;l++){
			int temp = (int)(s[i]-'a');
			//cout << temp << " " << l << " " << c[temp][l] << endl;
			li[l] += c[temp][l];
			if (i == e-1){
				mi = min(li[l], mi);
			}
		}
	}
	//for (int i = 0; i < m;i++){
		//cout << li[i] << endl;
	//}
	return mi;
}
int ch(int s){
	if (dp1[s] > 0){
		return dp1[s];
	}
	if (n-s+1 < k){
		return (1<<30);
	}
	int mi = d(s,n);
	for (int i = s+k; i <= n;i++){
		//cout << d(s, s+i) << " " << ch(s+i) << " " << i << " " << s<< endl;
		mi = min(mi, d(s, i)+ch(i));
	}
	dp1[s] = mi;
	return mi;
}
void fmi(int f, int s){
	vector<int> u(27);
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, f));
	while(q.size() > 0){
		pair<int, int> cur;
		cur = q.top();
		cur.first = -cur.first;
		q.pop();
		if (cur.second == s){
			c[f][cur.second] = cur.first;
			break;
		}
		if (u[cur.second] == 1 || c[f][cur.second] < cur.first){
			continue;
		}
		//cout << cur.second << endl;
		u[cur.second] = 1;
		//cout << cur.second << endl;
		c[f][cur.second] = cur.first;
		for (int i = 0;i < m;i++){
			if (u[i] == 1 || cur.second == i || c[f][i] < cur.first+c[cur.second][i]){
				continue;
			}
			q.push(make_pair(-(cur.first+c[cur.second][i]), i));
		}
	}
}

int main() {
	ifstream fin("cowmbat.in");
	ofstream fout("cowmbat.out");
	fin >> n;
	fin >> m;
	fin >> k;
	fin >> s;
	for (int i = 0; i < m;i++){
		for (int l = 0; l < m;l++){
			//cout << i << " " << l << endl;
			fin >> c[i][l];
			//cout << c[i][l] << endl;
		}
	}

	for (int i = 0; i < m;i++){
		for (int l = 0; l < m;l++){
			if (i == l){
				continue;
			}
			//cout << i << " " << l << endl;
			//cout << c[i][l] << endl;
			fmi(i,l);
		}
	}
	//cout << temp << endl;
	//for (int i = 0; i < m;i++){
	//	for (int l = 0; l < m;l++){
	//		cout << c[i][l] << " ";
	//	}
	//	cout << endl;
	//}
	fout << ch(0) << endl;
	//cout << d(0,2)+d(2,n);
	return 0;
}
