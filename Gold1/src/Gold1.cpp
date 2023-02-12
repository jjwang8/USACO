//============================================================================
// Name        : Gold1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int n,m,k;
vector<vector<pair<int,int> > > a(100000);
vector<int> hay(50020);
int lis[50020];
bool sl[50020];
int dis[50020];
void pa(){
	queue<pair<int,int> > wh;
	wh.push(make_pair(n,0));
	while(!wh.empty()){
		pair<int,int> cur;
		cur = wh.front();
		wh.pop();
		if (dis[cur.first] <= cur.second){
			continue;
		}
		dis[cur.first] = cur.second;
			for (int i = 0; i < a[cur.first].size();i++){
				if (dis[a[cur.first][i].first] > a[cur.first][i].second+cur.second){
					wh.push(make_pair(a[cur.first][i].first, a[cur.first][i].second+cur.second));
				}
			}
		}
}
void wr(){
	queue<pair<int,pair<int,pair<int,int> > > > wh;
	for (int i = 0; i < k;i++){
		wh.push(make_pair(lis[i],make_pair(0,make_pair(hay[lis[i]], lis[i]))));
	}
	while(!wh.empty()){
		pair<int,pair<int,pair<int,int> > > cur;
		cur = wh.front();
		wh.pop();
		if (sl[cur.first] == true){
			continue;
		}
		sl[cur.first] = true;
		for (int i = 0; i < a[cur.first].size();i++){
			if (sl[a[cur.first][i].first] == false && (cur.second.first+a[cur.first][i].second)+dis[cur.second.second.second] <= cur.second.second.first+dis[a[cur.first][i].first]){
				wh.push(make_pair(a[cur.first][i].first, make_pair(a[cur.first][i].second+cur.second.first,make_pair(cur.second.second.first,cur.second.second.second))));
			}
		}
	}
}
int main() {
	ifstream fin("dining.in");
	ofstream fout("dining.out");
	fin >> n;
	fin >> m;
	fin >> k;
	for (int i = 0; i < m;i++){
		int temp[3];
		for (int l = 0; l < 3;l++){
			fin >> temp[l];
		}
		a[temp[0]].push_back(make_pair(temp[1],temp[2]));
		a[temp[1]].push_back(make_pair(temp[0],temp[2]));
	}
	//cout << "aaa" << endl;
	for(int i = 0; i < k;i++){
		int temp[2];
		fin >> temp[0];
		fin >> temp[1];
		hay[temp[0]] = temp[1];
		lis[i] = temp[0];
	}
	//cout << "aaa" << endl;
	for (int i = 0;i < 50010;i++){
		sl[i] = 0;
		dis[i] = (1<<29);
	}
	//cout << "aaa" << endl;
	pa();
	wr();
	//for (int i = 1; i <= n;i++){
	//	cout << dis[i] << endl;
	//}
	for (int i = 1; i < n;i++){
		fout << sl[i] << endl;
	}
	return 0;
}
