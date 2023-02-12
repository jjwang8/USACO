#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
#include <algorithm>
#include <stack>
#include <time.h>
#include <stdlib.h>
using namespace std;
struct ob{
	int t;
	int d;
	int v;
};
vector<ob> a;
int n;
int dp[2005][105] = {};
int mal;
int sp(int ti, int loc){
	if (dp[ti][loc] > 0){
		return dp[ti][loc];
	}
	int ma = 0;
	for (int i = loc;i < n;i++){
		if (ti+a[i].t >= a[i].d){
			continue;
		}
		//cout << sp(a[i].t+ti, i+1)+a[i].v << endl;
		int temp = sp(a[i].t+ti, i+1)+a[i].v;
		if (temp > ma){
			mal = i;
		}
		ma = max(temp, ma);
	}
	dp[ti][loc] = ma;
	return ma;
}

int main() {
	srand (time(NULL));
	//n = 100;
	cin >> n;
	for (int i = 0; i < n;i++){
		ob temp;
		//temp.t = rand()%21;
		//temp.d = rand()%2001;
		//temp.v = rand()%21;
		cin >> temp.t;
		cin >> temp.d;
		cin >> temp.v;
		a.push_back(temp);
	}
	cout << sp(0,0) << endl;
	cout << n << endl;
	int ti = 0;
	//int tot;
	vector<int> temp;
	//temp.push_back(mal);
	for (int l = 0; l < 100; l++){
		temp.push_back(mal);
		cout << mal << endl;
		int tma = 0, tloc = 0;
		for (int i = 0; i < n;i++){
			if (tma < dp[a[mal].t+ti][i]){
				tma = dp[a[mal].t+ti][i];
				tloc = i;
			}
		}
		ti = a[tloc].t+ti;
		mal = tloc;
	}
	return 0;
}
