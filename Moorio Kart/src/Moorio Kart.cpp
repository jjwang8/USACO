//============================================================================
// Name        : Moorio.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
int n,m,x,y;
vector<vector<pair<int, int> > > a(1505);
int v[1505] = {};
unsigned long long fv[1505][2] = {};
vector<pair<int, int> > fn;
vector<vector<int> > fcom;
unsigned long long ps[1505];
int sp(int num, int loc, int bef){
	v[loc] = num;
	int tot = 0;
	if (a[loc].size() == 1){
		return 1;
	}
	for (int i = 0;i < a[loc].size();i++){
		if (a[loc][i].first == bef){
			continue;
		}
		int temp = sp(num,a[loc][i].first, loc);
		fn.push_back(make_pair(a[loc][i].second, temp));
		tot += temp;

	}
	return tot+1;
}
void pa(int bef, int loc, int num, int len, int chb){
	for (int i = 0; i < a[loc].size();i++){
		if (a[loc][i] == bef){
			continue;
		}
		if (len+a[loc][i].second < y){
			fcom[num][len+a[loc][i].second]++;
		}
		sp[num]++;
		pa(loc, a[loc][i].first, num, len+a[loc][i].second, chb);
	}
}
int main() {
	cin >> n;
	cin >> m;
	cin >> x;
	cin >> y;
	for (int i = 0; i < m;i++){
		int temp[3];
		cin >> temp[0];
		cin >> temp[1];
		cin >> temp[2];
		a[temp[0]].push_back(make_pair(temp[1],temp[2]));
		a[temp[1]].push_back(make_pair(temp[0],temp[2]));
	}
	int cur = 0;
	for (int i = 1; i <= n;i++){
		if (v[i] == 0){
			int tot = sp(cur, i, 0);
			for (int i = 0; i < fn.size();i++){
				fv[cur][0] += fn[i].first*fn[i].second*(tot-fn[i].second);
				fv[cur][1] = tot;
			}
			cur++;
			vector<int> temp(y+5);
			fcom.push_back(temp);
			pa(0,i,v[i],0,i);
		} else {
			pa(0,i,v[i],0,i);
		}
	}
	unsigned long long olv[2505][2] = {};
	for (int i = 1; i <= y;i++){
		olv[i][0] = olv[i-1][0]+fcom[0][i]*i;
		olv[i][1] = fcom[0][i];
	}
	unsigned long long org[2] = {};
	org[0] = fv[0][0],org[1] = pa[0];
	for (int i = 1; i < cur;i++){
		org[0] = fv[i][0]*org[1]+org[0]*ps[cur]+ps[cur]*org[1]*x;
		org[1] = org[1]*ps[cur];
		int temp[2505][2] = {};
		for (int l = y; l >= 0;i--){
			temp[l][0] =
		}
	}
	return 0;
}
