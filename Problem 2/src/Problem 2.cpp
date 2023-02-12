//============================================================================
// Name        : Problem.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
using namespace std;
int n;
int v[110000];
vector<vector<int> > p(110000);
int s(int t){
	priority_queue<pair<int,int> > d;
	d.push(make_pair(0,t));
	pair<int,int> cur;
	int b[101000];
	while(1){
		cur = d.top();
		d.pop();
		cur.first = -cur.first;
		b[cur.second] = cur.first;
		//cout << cur.first << " " << cur.second << endl;
		//cout << v[cur.second] << endl;
		if (v[cur.second] == 1){
			//cout << "aaa" << endl;
			return cur.first;
		}
		for (int i = 0; i < p[cur.second].size();i++){
			if (b[p[cur.second][i]] > cur.first+1 || b[p[cur.second][i]] == 0){
				b[p[cur.second][i]] = cur.first+1;
			}
			d.push(make_pair(-(cur.first+1), p[cur.second][i]));
		}
	}
	//return (1<<29);
}
int main() {
	cin >> n;
	for (int i = 0;i < n-1;i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		v[temp[0]]++;
		v[temp[1]]++;
		p[temp[0]].push_back(temp[1]);
		p[temp[1]].push_back(temp[0]);
		//cout << v[temp[0]] << " " << v[temp[1]] << endl;
	}
	int sum = 0;
	for (int i = 1; i < n;i++){
		//cout << sum << endl;
		sum += s(i);
	}
	cout << sum << endl;
	return 0;
}
