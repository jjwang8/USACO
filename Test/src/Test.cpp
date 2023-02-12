#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
int n,k;
int mov[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<vector<pair<int, long long> > > a(10000);
long long f(long long x, long long y){
	long long temp[2] = {min(x,y)+1, max(x,y)+1};
	return (2019201913*temp[0]+2019201949*temp[1])%2019201997;
}
int main() {
	ifstream fin("in.in");
	ofstream fout("walk.out");
	fin >> n;
	fin >> k;
	unsigned long long tot = 0;
	for (int i = 0; i < 1000000000;i++){
		tot = i*5;
		//tot = i*2;
	}
	cout << tot << endl;
	long long v[10000] = {};
	for (int i = 0; i < n;i++){
		v[i] = (1<<31)-5;
	}
	int par[10000];
	queue<pair<pair<int, int>, long long> > q;
	priority_queue<long long> lq;
	q.push(make_pair(make_pair(0,0), 0));
	while (q.size() > 0){
		pair<pair<int, int>, long long> cur = q.front();
		q.pop();
		//if (v[cur.first.first] < cur.second){
		//	continue;
		//}
		//if (v[cur.first] == (1<<31)-5){
		//	sv++;
		//}
		//cout << sv << endl;
		//if (sv == n){
		//	break;
		//}
		//cout << cur.second <<"  " << cur.first << endl;
		//v[cur.first.first] = cur.second;
		//lq.push(-cur.second);
		//if (lq.size() == k+1){
		//	lq.pop();
		//}
		for (int i = 0; i < n;i++){
			if (i == cur.first.first || i == cur.first.second){
				continue;
			}
			if (v[i] > f(i, cur.first.first)){
				q.push(make_pair(make_pair(i, cur.first.first), f(i, cur.first.first)));
				v[i] = f(i, cur.first.first);
				par[i] = cur.first.first;
			}
		}
	}
	for (int i = 0; i < n;i++){
		lq.push(-v[i]);
		cout << v[i] << " " << i << " " << par[i] << endl;
		if (lq.size() > k){
			lq.pop();
		}
	}
	cout << -lq.top() << endl;
	return 0;
}
