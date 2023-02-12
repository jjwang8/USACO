//============================================================================
// Name        : MockGold3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <set>
using namespace std;
int n;
string map[11];
char cm[11][11];
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
bool oof(int x,int y){
	if (x < 0 || y < 0){
		return true;
	}
	if (x >= n || y >= n){
		return true;
	}
	return false;
}
int main() {
	cin >> n;
	for (int i = 0; i < n;i++){
		cin >> map[i];
	}
	for (int i = 0; i < n;i++){
		for (int l = 0; l< n;l++){
			cm[i][l] = '0';
		}
	}
	queue<pair<pair<int,int>, int> > q;
	q.push(make_pair(make_pair(0,0),(int)'1'));
	while(!q.empty()){
		//cout << q.size() << endl;
		pair<pair<int,int>, int> cur;
		cur = q.front();
		q.pop();
		if ((int)cm[cur.first.first][cur.first.second] > (int)cur.second || cm[cur.first.first][cur.first.second] == '0'){
			cm[cur.first.first][cur.first.second] = (char)cur.second;
			for (int i = 0; i < 4;i++){
				if (oof(cur.first.first+dir[i][0],cur.first.second+dir[i][1]) || map[cur.first.first+dir[i][0]][cur.first.second+dir[i][1]] == '#'){
					continue;
				} else if (map[cur.first.first+dir[i][0]][cur.first.second+dir[i][1]] >= '1' && map[cur.first.first+dir[i][0]][cur.first.second+dir[i][1]] <= '9'){
					if ((cur.second-'1'+1)%(map[cur.first.first+dir[i][0]][cur.first.second+dir[i][1]]-'0') == 0){
						q.push(make_pair(make_pair(cur.first.first+dir[i][0],cur.first.second+dir[i][1]), cur.second+3));
					} else {
						q.push(make_pair(make_pair(cur.first.first+dir[i][0],cur.first.second+dir[i][1]), cur.second+1));
					}
				}else {
					q.push(make_pair(make_pair(cur.first.first+dir[i][0],cur.first.second+dir[i][1]), cur.second+1));
				}
			}
		}
	}
	//for (int i = 0; i < n;i++){
	//	for (int l = 0; l < n;l++){
	//		cout << cm[i][l];
	//	}
	//	cout << endl;
	//}
	cout << cm[n-1][n-1]-'1' << endl;
	return 0;
}
