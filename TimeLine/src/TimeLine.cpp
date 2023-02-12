//============================================================================
// Name        : TimeLine.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,c;
int v[100005] = {};
int con[100005] = {};
int ans[100005] = {};
bool vis[100005] = {};
vector<vector<pair<int, int> > > a(100005);
int main() {
	cin >> n;
	cin >> m;
	cin >> c;
	for (int i = 0; i < n;i++){
		cin >> v[i+1];
		ans[i+1] = v[i+1];
	}
	for (int i = 0; i < c;i++){
		int temp[3];
		cin >> temp[0];
		cin >> temp[1];
		cin >> temp[2];
		a[temp[0]].push_back(make_pair(temp[1], temp[2]));
		con[temp[0]]++, con[temp[1]]++;
	}
	queue<pair<int, int> > q;
	for (int i = 1; i <= n;i++){
		if (con[i] == 1 && a[i].size() == 1){
			q.push(make_pair(i, 0));
		}
	}
	while (q.size() > 0){
		pair<int, int> cur = q.front();
		q.pop();
		if (vis[cur.first] == 1 && ans[cur.first] >= cur.second){
			continue;
		}
		vis[cur.first] =1;
		for (int i = 0; i < a[cur.first].size();i++){
			if (vis[a[cur.first][i].first] && ans[a[cur.first][i].first] >= ans[cur.first]+a[cur.first][i].second){
				continue;
			}
			q.push(make_pair(a[cur.first][i].first, max(ans[a[cur.first][i].first], ans[cur.first]+a[cur.first][i].second)));
			ans[a[cur.first][i].first] = max(ans[a[cur.first][i].first], ans[cur.first]+a[cur.first][i].second);

		}
	}
	for (int i = 0; i < n;i++){
		cout << ans[i+1] << endl;
	}
	return 0;
}
