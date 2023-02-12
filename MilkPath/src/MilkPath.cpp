#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;
int n,m;
int cow[100000];
vector<vector<int> > a(100000);
vector<unordered_map<int, int> > milk(100000);
vector<int> path;
vector<vector<int> > lp(100000);
int loc[100000];
int pas[100000];
void sp(int st){
	cout << st << endl;
	pas[st] = 1;
	path.push_back(st);
	if (loc[st] == 0){
		loc[st] = path.size();
	}
	milk[st][cow[st]] = milk[st][cow[st]]+1;
	for (int i = 0; i < a[st].size();i++){
		milk[a[st][i]] = milk[st];
		if (pas[a[st][i]] == 1){
			continue;
		}
		sp(a[st][i]);
	}
}
void plp(){
	for (int i = 0; i < n;i++){
		for (int l = 0; (1<<l) <= n; l++){
			lp[i].push_back(0);
		}
		lp[i].push_back(i);
	}
	for (int l = 1;(1<<l) <= n;l++){
		for (int i = 0; (i+(1<<l)-1) < n;i++){
			if (path[lp[i][l-1]] < path[lp[i+(1<<(l-1))][l-1]]){
				lp[i][l] = lp[i][l-1];
			} else {
				lp[i][l] = lp[i+(1<<(l-1))][l-1];
			}
		}
	}
}
int lca(int l, int r){
	int j = log2(r-l+1);
	if (path[lp[l][j]] <= path[lp[r-(1<<j)+1][j]]){
		return path[lp[l][j]];
	} else {
		return path[lp[r-(1<<j)+1][j]];
	}
}
int main() {
	cin >> n;
	cin >> m;
	for (int i = 0;i < n;i++){
		int temp;
		cin >> temp;
		cow[i] = temp;
	}
	for (int i = 0; i < n-1;i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		a[temp[0]].push_back(temp[1]);
		a[temp[1]].push_back(temp[0]);
	}
	int st;
	for (int i = 0;i < n;i++){
		if (a[i].size() == 1){
			st = i;
		}
	}
	sp(st);
	//cout << "aaa" << endl;
	plp();
	for (int i = 0; i < m;i++){
		int temp[3];
		cin >> temp[0];
		cin >> temp[1];
		cin >> temp[2];
		cout << (milk[temp[0]][temp[2]]-milk[lca(loc[temp[0]],loc[temp[1]])][temp[2]]+milk[temp[1]][temp[2]]-milk[lca(loc[temp[0]],loc[temp[1]])][temp[2]] > 0);
	}
	return 0;
}
