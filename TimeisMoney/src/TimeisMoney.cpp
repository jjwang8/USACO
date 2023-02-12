#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
#include <algorithm>
using namespace std;
int v[100001], n, m, c;
vector<pair<int, int> > a;
int dp[1005][1005] = {{}};
int ma = 0;
int mav = 0;
int main() {
	ifstream fin("time.in");
	ofstream fout("time.out");
	fin >> n;
	fin >> m;
	fin >> c;
	for (int i = 1; i <= n;i++){
		int temp;
		fin >> temp;
		v[i] = temp;
	}
	for(int i = 0; i < m;i++){
		pair<int, int> temp;
		fin >> temp.first;
		fin >> temp.second;
		a.push_back(temp);
		//a.push_back(make_pair(temp.second, temp.first));
		//cout << a[i].first << a[i].second << endl;
	}
	dp[0][1] = 0;
	for (int i = 1; i < 1005;i++){
		for (int l = 0; l < a.size();l++){
			//cout << dp[i-1][a[l].first] << " " << i-1 << " " <<  a[l].first << endl;
			if (dp[i-1][a[l].first] == 0 && (i != 1 || a[l].first != 1)){
				continue;
			}
			//cout << "aaa" << endl;
			dp[i][a[l].second] = max(dp[i][a[l].second], dp[i-1][a[l].first]+v[a[l].second]);
			//cout << dp[i][a[l].second] << " " << dp[i][a[l].second]-c*i*i << " " << mav-c*ma*ma << " " << a[l].second << endl;
			if (dp[i][a[l].second]-c*i*i > mav-c*ma*ma && a[l].second == 1){
				ma = i;
				mav = dp[i][a[l].second];
			}
		}
		//cout << dp[i][1] << " " << dp[i][2] << " " << dp[i][3]  << " " << i << endl;
	}
	fout << dp[ma][1]-c*ma*ma << endl;
	//cout << ma << endl;
	return 0;
}
