//============================================================================
// Name        : 500milewalk.cpp
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
int n,k,ans;
int d[7501];
priority_queue<pair<long long, pair<int,int> > > mi;
int main() {
	ifstream fin("walk.in");
	ofstream fout("walk.out");
	cin >> n;
	cin >> k;
	for (int i = 1; i <= n;i++){
		for (int l = 1;l <= n;l++){
			if (i == l || i > l){
				continue;
			} else {
				mi.push(make_pair((-(2019201913LL*i+2019201949LL*l)%2019201997LL),make_pair(i,l)));
				//mi.push(make_pair(4,make_pair(i,l)));
			}
		}
	}
	int tk = k;
	int tot = n;
	while(!mi.empty()){
		cout << mi.top().first << " " << mi.top().second.first << " " << mi.top().second.second << endl;
		if (tot == tk){
			ans = -mi.top().first;
		}
		if (d[mi.top().second.first] != 1 && d[mi.top().second.second] != 1){
			if (tk == 0){
				ans = -mi.top().first;
				break;
			}
			tk--;
			tot = tot-2;
		} else {
			tot--;
		}
		d[mi.top().second.first] = 1;
		d[mi.top().second.second] = 1;
		mi.pop();
	}
	cout << ans;
	return 0;
}
