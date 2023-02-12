//============================================================================
// Name        : Gold120.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
#include <algorithm>
using namespace std;
int n, m, c;
int s[100010];
vector<vector<pair<int, int> > > mem(100001);
vector<vector<pair<int, int> > > mem2(100001);
int mi[100001];
int main() {
	ifstream fin("");
	ofstream fout("");
	cin >> n;
	cin >> m;
	cin >> c;
	for (int i = 1; i <= n;i++){
		cin >> s[i];
		mi[i] = s[i];
	}

	for (int i = 0; i < c;i++){
		int temp[3];
		cin >> temp[0];
		cin >> temp[1];
		cin >> temp[2];
		mem[temp[0]].push_back(make_pair(temp[1], temp[2]));
		mem2[temp[1]].push_back(make_pair(temp[0], temp[2]));

	}
	cout << "aaa" << endl;
	queue<int> q;
	q.push(1);
	while (q.size() > 0){
		cout << q.front();
		//cout << "aaa" << endl;
		int cur;
		cur = q.front();
		for (int i = 0; i < mem[cur].size();i++){
			int f = mi[mem[cur][i].first];
			mi[mem[cur][i].first] = max(mi[cur]+mem[cur][i].second, max(s[mem[cur][i].first], mi[mem[cur][i].first]));
			if (f != mi[mem[cur][i].first]){
				q.push(mem[cur][i].first);
			}
		}
		for (int i = 0; i < mem2[cur].size();i++){
			int f = mi[mem2[cur][i].first];
			if (mi[cur]-mem2[cur][i].second < 1 || mi[cur]-mem2[cur][i].second < s[mem2[cur][i].first] || mi[cur]-mem2[cur][i].second < mi[mem2[cur][i].first]){
				mi[mem2[cur][i].first] = max(s[mem2[cur][i].first], mi[mem2[cur][i].first]);
				mi[cur] += mi[mem2[cur][i].first]-(mi[cur]-mem2[cur][i].second);
				q.push(cur);
				continue;
			}
			mi[mem2[cur][i].first] = max(mi[cur]-mem2[cur][i].second, max(s[mem2[cur][i].first], mi[mem2[cur][i].first]));
			if (f != mi[mem2[cur][i].first]){
				q.push(mem2[cur][i].first);
			}
		}
	}
	for (int i = 1; i <= n;i++){
		cout << mi[i] << endl;
	}
	return 0;
}
