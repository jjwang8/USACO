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
int n,m;
vector<pair<int, pair<int, int> > > a;
vector<vector<int> > cyc(100000);
int tre[100000] = {};
int cnum = 1;
int binsea(int tar, int tnu){
	int lef = 0;
	int rit = cyc[tnu].size();
	while (lef <= rit) {
		int mid = lef + (rit - lef) / 2;
	        if (cyc[tnu][mid] == tar)
	            return mid;
	        if (cyc[tnu][m] < tar)
	            lef = mid + 1;
	        else
	            rit = mid - 1;
	    }
	    return -1;
}
bool fin(int x, int y){
	if (x > 0 && y > 0){
		if (binsea(x,y) == -1){
			return 0;
		} else {
			return 1;
		}
	}
	if (x == 0 || y == 0){
		return 0;
	}
	return 0;
}
int main() {
	cin >> n;
	cin >> m;
	for (int i =0; i < m;i++){
		pair<int, pair<int, int> > temp;
		cin >> temp.first;
		cin >> temp.second.first;
		cin >> temp.second.second;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	int cur[5] = {};
	for (int i = 0; i < a.size();i++){
		if (cur[0] != a[i].first){

			cur[0] = a[i].first;
		}

		if (fin(tre[a[i].second.first], tre[a[i].second.second]) ){

		}
	}
	return 0;
}
