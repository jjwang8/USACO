#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
int n,q;
int pa[100005];
vector<vector<int> > oa(100005);
vector<vector<int> > a(100005);
vector<vector<int> > ea(100005);
vector<int> h;
vector<vector<int> > ha(100005);
vector<int> tour;
int ch[100005] = {};
int conv[100005] = {};

void red(){
	bool v[100005] = {};
	queue<pair<int, int> > q;
	q.push(make_pair(1,1));
	v[1] = 1;
	int curn = 1;
	conv[1] = 1;
	while (q.size() > 0){
		pair<int, int> cur = q.front();
		q.pop();
		v[cur.first] = 1;
		//cout << cur.first << endl;
		for (int i = 0; i < oa[cur.first].size();i++){
			if (v[oa[cur.first][i]]){
				continue;
			}
			//cout << cur.second << " " << curn+1 << endl;
			conv[curn+1] = oa[cur.first][i];
			a[cur.second].push_back(curn+1);
			q.push(make_pair(oa[cur.first][i], ++curn));
		}
	}
}
int intu(int x){
	tour.push_back(x);
	for (int i = 0; i < a[x].size();i++){
		ch[x] += intu(a[x][i]);
		tour.push_back(x);
	}
	return ch[x]+1;
}
void hl(){
	bool v[100005] = {};
	queue<pair<int, int> > q;
	q.push(make_pair(1,0));
	v[1] = 1;
	while (q.size() > 0){
		pair<int, int> cur = q.front();
		q.pop();
		v[cur.first] = 1;
		int ma[2] = {};
		if (cur.second > 0){
			ha[cur.second].push_back(cur.first);
		}
		if (a[cur.first].size() > 0 && cur.second == 0){
			cur.second = cur.first;
			h.push_back(cur.second);
			ha[cur.second].push_back(cur.first);
		}
		if (a[cur.first].size() > 0){
			ma[1] = ch[a[cur.first][0]];
			ma[0] = a[cur.first][0];
		}
		for (int i = 0; i < a[cur.first].size();i++){
			if (v[a[cur.first][i]]){
				continue;
			}
			if (ma[1] < ch[a[cur.first][i]]){
				ma[1] = ch[a[cur.first][i]];
				ma[0] = a[cur.first][i];
			}
		}
		for (int i = 0; i < a[cur.first].size();i++){
			if (v[a[cur.first][i]]){
				continue;
			}
			if (a[cur.first][i] == ma[0]){
				q.push(make_pair(a[cur.first][i], cur.second));
				continue;
			}
			ea[cur.second].push_back(a[cur.first][i]);
			ea[a[cur.first][i]].push_back(cur.second);
			q.push(make_pair(a[cur.first][i], 0));
		}
	}
}
struct sep{
	int par = -1;
	vector<int> ch;
	int val = 0;
};
vector<vector<sep> > gr(100005);
int curn = 0;
pair<int, int> seg(int x, int l, int r, int v){
	sep temp;
	gr[x].push_back(temp);
	int pos = gr[x].size()-1;
	if (l == r){
		return make_pair(pa[conv[ha[x][l]]], pos);
	}
	pair<int, int> cur = seg(x, l, (l+r)/2, ++curn);
	gr[x][pos].ch.push_back(cur.second), gr[x][pos].val = cur.first;
	gr[x][cur.second].par = pos;
	cur = seg(x, (l+r)/2+1, r, ++curn);
	gr[x][pos].ch.push_back(cur.second), gr[x][pos].val = gr[x][pos].val^cur.first;
	gr[x][cur.second].par = pos;
	return make_pair(gr[x][pos].val, pos);
}
int main() {
	ifstream fin("in.in");
	fin >> n;
	fin >> q;
	for (int i = 0; i < n;i++){
		fin >> pa[i];
	}
	for (int i = 0; i < n-1;i++){
		int temp[2];
		fin >> temp[0];
		fin >> temp[1];
		oa[temp[0]].push_back(temp[1]);
		oa[temp[1]].push_back(temp[0]);
	}
	red();
	ch[1] = intu(1)-1;
	hl();
	for (int i = 0; i < h.size();i++){
		seg(h[i], 0, ha[h[i]].size()-1, 0);
	}

	for (int i = 0; i < q;i++){

	}
	return 0;
}
