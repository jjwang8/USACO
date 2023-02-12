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
int n,q, num = -1, ro;
vector<pair<pair<int, pair<int, int> >, pair<int, int> > > a(300000);
vector<int> li;
pair<int, pair<int, int> > st(int x, int y){
	if (x >= n || y <= 0 || x > y || y >= n){
		return make_pair((1<<29), make_pair(0, -1));
	}
	if (x == y){
		int cur = ++num;
		a[cur] = make_pair(make_pair(-1, make_pair(-1,-1)), make_pair(li[x], li[x]));
		return make_pair(li[x], make_pair(li[x], cur));
	}
	pair<int, pair<int, int> > temp[2];
	temp[0] = st(x,(y+x)/2);
	temp[1] = st((y+x)/2+1, y);
	int cur = ++num;
	a[cur] = make_pair(make_pair(-1, make_pair(temp[0].second.second, temp[1].second.second)), make_pair(min(temp[0].first, temp[1].first), temp[0].second.first+temp[1].second.first));
	return make_pair(min(temp[0].first, temp[1].first), make_pair(temp[0].second.first+temp[1].second.first, cur));
}
void up(int x, int y){

}
int qr(int x, int y, int loc, pair<int, int> cur, bool w){
	if (cur.first >= x && cur.second <= y){
		if (w){
			return a[loc].second.second;
		} else {
			return a[loc].second.first;
		}
	}
	if (cur.first >= n || cur.second <= 0 || cur.first > cur.second || cur.second >= n){
		if (w){
			return (1<<29);
		} else {
			return 0;
		}
	}
	if (cur.first == cur.second){
		return li[cur.first];
	}
	if (cur.first < x || cur.second > y){
		if (w){
			return min(qr(x,y,a[loc].first.second.first, make_pair(cur.first, (cur.second+cur.first)/2), w), qr(x,y,a[loc].first.second.second, make_pair((cur.second+cur.first)/2+1, cur.second), w));
		} else {
			return qr(x,y,a[loc].first.second.first, make_pair(cur.first, (cur.second+cur.first)/2), w) + qr(x,y,a[loc].first.second.second, make_pair((cur.second+cur.first)/2+1, cur.second), w);
		}
	}
}
int main() {
	ifstream fin("in.in");
	fin >> n;
	fin >> q;
	for (int i = 0; i < n;i++){
		int temp;
		cin >> temp;
		li.push_back(temp);
	}
	ro = st(0, n-1).second.second;
	for (int i = 0; i < q;i++){

	}
	return 0;
}
