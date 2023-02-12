//============================================================================
// Name        : Bovine.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<vector<int> > a(100050);
bool v[100005] = {};
int dfs(int s){
	queue<pair<int, int> > q;
	q.push(make_pair(s,0));
	bool cyc = 0;
	int nod = 0;
	while(q.size() > 0){
		pair<int, int> cur = q.front();
		q.pop();
		if (v[cur.first] == 1){
			continue;
		}
		v[cur.first] = 1;
		nod++;
		bool v2[100000] = {};
		for (int i = 0; i < a[cur.first].size();i++){
			if (v2[a[cur.first][i]] == 1){
				cyc = 1;
			}
			v2[a[cur.first][i]] = 1;
			if (a[cur.first][i] == cur.second){
				continue;
			}
			if (v[a[cur.first][i]]){
				cyc = 1;
				continue;
			}
			q.push(make_pair(a[cur.first][i], cur.first));
		}
	}
	if (cyc){
		return 2;
	} else{
		if (nod == 1){
			return 1;
		}
		return nod;
	}
}
int main() {
	cin >> n;
	cin >> m;
	for (int i =0;i < m;i++){
		pair<int, int> temp;
		cin >> temp.first;
		cin >> temp.second;
		a[temp.first].push_back(temp.second);
		a[temp.second].push_back(temp.first);
	}
	unsigned long long tot = 1;
	for (int i = 1; i <= n;i++){
		if (v[i] == 0){
			int temp = dfs(i);
			tot = (tot*temp)%1000000007;
		}
	}
	cout << tot << endl;
	return 0;
}
