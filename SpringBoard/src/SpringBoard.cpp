//============================================================================
// Name        : SpringBoard.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,p;
vector<pair<pair<int, int>, pair<int, int> > > a;
struct ent{
	int ch[2] = {-1, -1};
	int val[2] = {};
	int curv = 0;
	int pos = -1;
	int par = -1;
};
vector<ent> tre;
int sp(int x){
	if (tre.size() == 0){
		ent temp;
		temp.curv = a[x].first.first+a[x].first.second, temp.pos = a[x].second.second;
		tre.push_back(temp);
		return 0;
	}
	int ma = 0, en = 0;
	bool t = 1;
	while (t){
		if (tre[en].pos == a[x].first.second){

		} else if (tre[en].pos > a[x].first.second){
			if (tre[en].ch[0] == -1){
				ent temp;
				temp.curv = a[x].first.first+a[x].first.second
			}
			en = tre[en].ch[0];
		} else {
			en = tre[en].ch[1];
			ma = max(ma, max(tre[en].curv, tre[en].val[0]));
		}
	}
}
int main() {
	cin >> n;
	cin >> p;
	for (int i = 0; i < p;i++){
		pair<pair<int, int>, pair<int, int> >  temp;
		cin >> temp.first.first;
		cin >> temp.first.second;
		cin >> temp.second.first;
		cin >> temp.second.first;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < p;i++){

	}
	return 0;
}
