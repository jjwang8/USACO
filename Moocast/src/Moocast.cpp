//============================================================================
// Name        : Moocast.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <queue>
#include <set>
using namespace std;
int n, a[2000][2], ma = 0, u[2000], tot;
int sq(int x){
	return x*x;
}
int main() {
	cin >> n;
	for (int i = 0;i < n;i++){
		cin >> a[i][0];
		cin >> a[i][1];
	}
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	while (!q.empty()){
		//cout << q.front().first << " " << q.front().second << " " << u[q.front().second] << endl;
		if (u[q.front().second] == 0 || u[q.front().second] > q.front().first){
			u[q.front().second] = q.front().first;
		}else if (u[q.front().second] <= q.front().first){
			q.pop();
			continue;
		}
		for (int i =0;i < n;i++){
			if (i == q.front().second){
				continue;
			}
			int dis = sq(a[q.front().second][0]-a[i][0])+sq(a[q.front().second][1]-a[i][1]);
			if (u[i] != 0 && u[i] <= dis){
				continue;
			}
			//cout << u[i] << " " << dis << endl;
			q.push(make_pair(dis, i));
		}
		q.pop();
	}
	for (int i = 0;i <n;i++){
		ma = max(ma, u[i]);
	}
	cout << ma << endl;
	return 0;
}
