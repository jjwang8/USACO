//============================================================================
// Name        : 2019Gold1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <queue>
#include <iostream>
using namespace std;
int n,m;
vector< vector <pair<int, pair<double, double> > > > a(1001);
priority_queue<pair<pair<double, int> , pair<double, double> > > q;
double v[1001];
int main() {
	ifstream fin("pump.in");
	ofstream fout("pump.out");
	fin >> n;
	fin >> m;
	for (int i = 0; i < m;i++){
		int temp[4];
		for (int l = 0;l < 4;l++){
			fin >> temp[l];
		}
		a[temp[0]].push_back(make_pair(temp[1], make_pair(temp[2], temp[3])));
		a[temp[1]].push_back(make_pair(temp[0], make_pair(temp[2], temp[3])));
	}
	for (int i = 0; i <= n;i++){
		v[i] = -(1<<30);
	}
	q.push(make_pair(make_pair((1<<30), 1), make_pair(0, (1<<30))));
	while (q.size() > 0){
		double cur[4];
		int cur1 = q.top().first.second;
		cur[0] = q.top().first.first;
		//cur[1] = q.top().first.second;
		cur[2] = q.top().second.first;
		cur[3] = q.top().second.second;
		q.pop();
		//cout << "aaa" << endl;
		if (v[cur1] > cur[0]){
			//cout << v[cur1];
			continue;
		}
		v[cur1] = cur[0];
		//cout << a[cur[1]].size() << endl;
		for (double i = 0; i < a[cur1].size();i++){
			double temp = min(cur[3], a[cur1][i].second.second)/(cur[2]+a[cur1][i].second.first)*1000000;
			//cout << cur[3] << " " << a[cur1][i].second.second) << " "
			//cout << temp << endl;
			//cout << temp << " " << cur1 << " " << a[cur1][i].first << " " << min(cur[3], a[cur1][i].second.second) << " " << (cur[2]+a[cur1][i].second.first) << endl;
			if (v[a[cur1][i].first] < temp){
				q.push(make_pair(make_pair(temp, a[cur1][i].first), make_pair(cur[2]+a[cur1][i].second.first, min(cur[3], a[cur1][i].second.second))));
			}
		}

	}
	fout << (int)v[n] << endl;
	return 0;
}
