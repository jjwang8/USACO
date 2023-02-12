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
int n,tot = 0, st = 0, k;
int mov[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<pair<int, int> > a;
int dp[100005][100] = {{}};
bool val(int x, int y){
	return !((x < 0 || y > n) || (x > n || y < 0));
}
int sp(int st, int en){
	cout << st << " " << en << endl;
	if (st < 0){
		return -(1<<29);
	}
	if (st == 0){
		if (en == 1){
			return 0;
		} else if (en == 0){
			return a[st].second-a[st].first+1;
		} else {
			return -(1<<29);
		}
	}
	if (dp[st][en] > 0){
		return dp[st][en];
	}
	int cur[3] = {};
	if (en == st){
		cur[0] = a[st].second-a[st].first+1;
	}
	int i;
	for (i = st; i >= 0;i--){
		if (a[i].second <= a[st].first){
			i++;
			break;
		}
	}
	if (i == -1){
		 i = 0;
	}
	if (en >= st-i-1){
		cur[1] = (a[st].second-a[st].first+1)-(a[i].second-a[st].first+1);
	}
	if (i != 0 && en >= st-i){
		cur[2] = a[st].second-a[st].first+1;
	}
	if (i == 0){
		cur[2] = -(1<<30);
	}
	dp[st][en] = max(cur[0], max(cur[1]+sp(i,en-(st-i-1)), cur[2]+sp(i,en-(st-i))-(a[i].second-a[i].first+1)));
	return dp[st][en];
}

int main() {
	cin >> n;
	cin >> k;
	for (int i = 0;i < n;i++){
		pair<int, int> temp;
		cin >> temp.first;
		cin >> temp.second;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	for(int i = 0;i < n;i++){
		for (int l = 0; l <= k && l <= i;l++){
			if (dp[i][l] == 0){
				dp[i][l] = sp(i,l);
			}
			dp[i][l] = sp(i,l);
		}
	}
	for (int i = 0; i < k;i++){
		dp[n][i] = dp[n-1][i]
	}
	cout << sp(n-1, k);
	return 0;
}
