//============================================================================
// Name        : shortcut.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n,m,t;
int c[20000];
vector<vector<pair<int, int> > > p(50500);
int b[10010][2];
void d(int x){
	priority_queue<pair<int, int> > q;
	vector<int> ma(10010, (1<<30));
	q.push(make_pair(0, x));
	while (!q.empty()){
		if (q.top().second == 0){
			b[q.top().second][0] = -q.top().first;
		}
		if (ma[q.top().second] <= -q.top().first){
			q.pop();
			continue;
		}
		ma[q.top().second] = -q.top().first;
		for (int i = 0;i < p[q.top().second].size();i++){
			if (ma[p[q.top().second][i].first] <= -q.top().first+p[q.top().second][i].second){
				continue;
			}
			q.push(make_pair(p[q.top().second][i].first, -q.top().first+p[q.top().second][i].second));
		}
		q.pop();
	}
}
int main() {
	cin >> n;
	cin >> m;
	cin >> t;
	for (int i = 0;i < n;i++){
		cin >> c[i];
	}
	for (int i =0;i<m;i++){
		int temp[3];
		for (int l =0;l<3;l++){
			cin >> temp[l];
		}
		p[temp[0]-1].push_back(make_pair(temp[1]-1, temp[2]));
		p[temp[1]-1].push_back(make_pair(temp[0]-1, temp[2]));
	}
	for (int i = 0;i < n; i++){
		sort(p[i].begin(), p[i].end());
		reverse(p[i].begin(), p[i].end());
	}
	for (int i = 0;i < n;i++){
		d(i);
	}

	for (int i = 0;i < n;i++){

	}
	return 0;
}
