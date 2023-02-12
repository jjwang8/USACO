//============================================================================
// Name        : finedining.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
int n,m,k;
vector<vector<pair<int, int> > > a (60000);
int h[60000];
priority_queue<pair<int, pair<int, bool> > > q;
int p[60000][2];
int main() {
	ifstream fin("dining.out");
	ofstream fout("dining.in");
	fin >> n;
	fin >> m;
	fin >> k;
	for (int i = 0; i < m;i++){
		int temp[3];
		for (int l = 0;l < 3;l++){
			fin >> temp[l];
		}
		a[temp[0]].push_back(make_pair(temp[1],temp[2]));
		a[temp[1]].push_back(make_pair(temp[0],temp[2]));
	}
	for (int i = 0; i < k;i++){
		int temp[2];
		fin >> temp[0];
		fin >> temp[1];
		h[temp[0]] = temp[1];
	}
	for (int i = 0; i <= n; i++){
		p[i][0] = (1<<30);
	}
	q.push(make_pair(0, make_pair(n, 0)));
	//fout << q.size() << endl;
	//p[n][0] = 0, p[n][1] = 0;
	while (!q.empty()){
		//fout << q.size() << endl;
		//fout << q.top().first << " " << q.top().second.first << " " << q.top().second.second << endl;
		pair<int, pair<int, int> > cur;
		cur = q.top();
		q.pop();
		if (p[cur.second.first][0] < -cur.first){
			continue;
		}
		p[cur.second.first][0] = -cur.first;
		p[cur.second.first][1] = cur.second.second;
		for (int i = 0; i < a[cur.second.first].size();i++){
			//fout << -(-q.top().first+a[cur.second.first][i].second) << endl;
			//fout << -(-cur.first+a[cur.second.first][i].second - h[a[cur.second.first][i].first]) << endl;
			if (h[a[cur.second.first][i].first] > 0 && cur.second.second == 0){
				q.push(make_pair(-(-cur.first+a[cur.second.first][i].second - h[a[cur.second.first][i].first]), make_pair(a[cur.second.first][i].first, 1)));
				//fout << "aaa" << endl;
				continue;
			}
			//fout << -(-cur.first+a[cur.second.first][i].second) << endl;
			q.push(make_pair(-(-cur.first+a[cur.second.first][i].second), make_pair(a[cur.second.first][i].first, cur.second.second)));
		}
		//fout << "aaa" << endl;
		//q.pop();
		//fout << cur.first << " " << cur.second.first << " " << cur.second.second << endl;
	}
	for (int i = 1; i < n;i++){
		fout << p[i][1] << endl;
	}
	return 0;
}
