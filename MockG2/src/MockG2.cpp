//============================================================================
// Name        : MockG2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int n,rb[2];
vector<vector<int> > a(1000);
int v[1000][1000];
int act[1000][2];
int rv[1000];
int rbtot[2];
int cal(int node1, int node2,bool color1,bool color2){
	//cout << color1 << " " << color2 << endl;
	if (color1 == color2){
		return rb[color2]+v[node1][node2];
	} else {
		return rb[color2];
	}
}
int f(bool start){
	priority_queue<pair<pair<int, int> ,pair<int,int> > > q;
	q.push(make_pair(make_pair(-rb[start],-rb[start]),make_pair(start,1)));
	pair<pair<int,int>, pair<int,int> > cur;
	act[1][0] = rb[start];
	act[1][1] = start;
	while(q.size() > 0){
		//cout << q.size() << endl;

		cur = q.top();
		q.pop();
		if (act[cur.second.second][0] <= cur.first.first && cur.second.second != 1){
			continue;
		}
		//cout << cur.second.first << " " << "aaa "<< endl;
		rv[cur.second.second] = cur.first.second;
		act[cur.second.second][0] = cur.first.first;
		act[cur.second.second][1] = cur.second.first;
		for (int i = 0; i < a[cur.second.second].size();i++){
			//cout << a[cur.second.second][i] << endl;
			if (act[a[cur.second.second][i]][0] > cal(cur.second.second,a[cur.second.second][i],cur.second.first,0)) {
				q.push(make_pair(make_pair(-(cur.first.first+cal(cur.second.second,a[cur.second.second][i],cur.second.first,0)),cal(cur.second.second,a[cur.second.second][i],cur.second.first,0)),make_pair(0,a[cur.second.second][i])));
			}
			if (act[a[cur.second.second][i]][0] > cal(cur.second.second,a[cur.second.second][i],cur.second.first,1)) {
				q.push(make_pair(make_pair(-(cur.first.first+cal(cur.second.second,a[cur.second.second][i],cur.second.first,1)),cal(cur.second.second,a[cur.second.second][i],cur.second.first,1)),make_pair(1,a[cur.second.second][i])));
			}
		}
	}
	int tot = 0;
	for (int i = 1; i <= n;i++){
		//cout << act[i][0] << endl;
		tot += rv[i];
	}
	return tot;
}
void clear(){
	for (int i = 0; i < 1000;i++){
		act[i][0] = (1<<30);
		act[i][1] = -1;
		rv[i] = 0;
	}
}
int main() {
	cin >> n;
	cin >> rb[0];
	cin >> rb[1];
	for (int i = 0; i < n-1;i++){
		int temp[3];
		cin >> temp[0];
		cin >> temp[1];
		cin >> temp[2];
		a[temp[0]].push_back(temp[1]);
		a[temp[1]].push_back(temp[0]);
		v[temp[0]][temp[1]] = temp[2];
		v[temp[1]][temp[0]] = temp[2];

	}
	//cout << "aaa" << endl;
	for (int i = 0; i < 1000;i++){
		act[i][0] = (1<<29);
		act[i][1] = -1;
	}
	int t1 = f(0);
	clear();
	int t2 = f(1);
	cout << min(t2,t1) << endl;
	return 0;
}
