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
int n, m, u;
vector<pair<int, int> > a;
vector<vector<pair<int, int> > > bl(600);
vector<int> org;
int ind[300005] = {};
vector<vector<int> > q;
vector<vector<int> > oq;
vector<vector<int> > sv(605);
int binsea(int tar){
	int lef = 0;
	int rit = a.size();
	while (lef <= rit) {
		int mid = lef + (rit - lef) / 2;
			if (a[mid].first == tar)
				for (int i = mid; i >= 0;i--){
					if (a[i].first != tar){
						return i-1;
					}
				}
				return mid;
			if (a[mid].first < tar)
				lef = mid + 1;
			else
				rit = mid - 1;
	}
	return min(lef, rit);
}
int binsea2(int tar, int sec){
	int lef = 0;
	int rit = bl[sec].size();
	while (lef <= rit) {
		int mid = lef + (rit - lef) / 2;
			if (bl[sec][mid].first == tar)
				for (int i = mid; i >= 0;i--){
					if (bl[sec][i].first != tar){
						return i-1;
					}
				}
				return mid;
			if (bl[sec][mid].first < tar)
				lef = mid + 1;
			else
				rit = mid - 1;
	}
	return minlef, rit);
}
int main() {
	ifstream fin("in.in");
	ofstream fout("out.out");
	fin >> n;
	fin >> m;
	fin >> u;
	for (int i = 0; i < n;i++){
		int temp;
		fin >> temp;
		a.push_back(make_pair(temp,i));
		org.push_back(temp);
		bl[i/floor(sqrt(n))].push_back(make_pair(temp, i));
	}
	for (int i = 0; i < floor(sqrt(n))+1; i++){
		sort(bl[i].begin(), bl[i].end());
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size();i++){
		ind[a[i].second] = i;
	}
	for (int i =0; i < m;i++){
		vector<int> temp(4);
		fin >> temp[1];
		fin >> temp[2];
		fin >> temp[0];
		fin >> temp[3];
		temp[1]--;
		temp[2]--;
		q.push_back(temp);
		oq.push_back(temp);
	}
	sort(q.begin(), q.end());
	for (int i = 0; i < floor(n/floor(sqrt(n)))+1;i++){
		int cur = m-1;
		cout << n/floor(sqrt(n)) << endl;
		while(cur != -1 && q[cur][0] > bl[i].back().first){
			sv[i].push_back(bl[i].size());
			cur--;
		}
		if (cur == -1){
			continue;
		}
		int ctot = 0;
		for (int l = bl[i].size()-1; l >= 0;l--){
			if (q[cur][0] <= bl[i][l].first){
				ctot++;
			} else {
				while(q[cur][0] > bl[i][l].first){
					if (cur == 0){
						sv[i].push_back(bl[i].size()-ctot);
						l = 0;
						break;
					}
					sv[i].push_back(bl[i].size()-ctot);
					cur--;
				}
			}
		}
	}
	for (int i = 0; i < m;i++){
		int tot = 0;
		for (int l = oq[i][1]/floor(sqrt(n))+1; l < oq[i][2]/floor(sqrt(n));l++){
			if (sv[l].size() < m-i){
				break;
			}
			tot += sv[l][m-i-1];
		}
		for (int l = binsea2(oq[i][0], oq[i][1]/floor(sqrt(n))); l >= 0;l--){
			if (bl[oq[i][1]/floor(sqrt(n))][l].second >= oq[i][1]){
				tot++;
			}
		}
		for (int l = binsea2(oq[i][0], oq[i][2]/floor(sqrt(n))); l >= 0;l--){
			if (bl[oq[i][2]/floor(sqrt(n))][l].second <= oq[i][2]){
				tot++;
			}
		}
		vector<pair<int, int> > temp;
		for (int l = 0;l < floor(sqrt(n)); l++){
			if (bl[oq[i][3]/floor(sqrt(n))][l].first >= tot/(oq[i][2]-oq[i][1]+1)){
				temp.push_back(make_pair(tot/(oq[i][2]-oq[i][1]+1), oq[i][3]));
			}
			if (bl[oq[i][3]/floor(sqrt(n))][l].second == oq[i][3]){
				continue;
				temp.push_back(make_pair(tot/(oq[i][2]-oq[i][1]+1), bl[oq[i][3]/floor(sqrt(n))][l].second));
			}
			temp.push_back(bl[oq[i][3]/floor(sqrt(n))][l]);
		}
		org[oq[i][3]] = tot/(oq[i][2]-oq[i][1]+1);
		bl[oq[i][3]/floor(sqrt(n))] = temp;
		sv[oq[i][3]/floor(sqrt(n))][]
	}
	for (int i = 0; i < n;i++){
		cout << org[i] << endl;
	}
	return 0;
}
