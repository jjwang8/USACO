//============================================================================
// Name        : Cowpoetry.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, m, k;
vector<pair<int, int> > w(6000);
char r[100020];
long long us[30][5050];
int dp[5050];
long long bi = 1000000007;
long long ans = 1;
int ge(int x){
	dp[0] = 1;
	if (dp[x] > 0){
		return dp[x];
	}
	for (int i =0;i < x+1;i++){
		if (dp[i] >= 1){
			for (int l = 0;l < n;l++){
				dp[i+w[l].first] = (dp[i]+ dp[i+w[l].first])%bi;
			}
		}
	}
	return dp[x];
}
int main() {
	cin >> n;
	cin >> m;
	cin >> k;
	for (int i = 0;i < n;i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		w[i] = make_pair(temp[0], temp[1]);
	}
	for (int i = 0;i < m;i++){
		cin >> r[i];
		r[i] = r[i]-'A';
	}
	ge(k);
	//cout << "aaa" << endl;
	for (int i =0;i < m;i++){
		if (us[r[i]][1] > 0){
			int con = 1;
			int tot = 0;
			while (us[r[i]][con] > 0){
				tot = (tot+us[r[i]][con]*ans)%bi;
				us[r[i]][con] = (tot+us[r[i]][con]*ans)%bi;
				con++;
			}
			ans = (ans+tot)%bi;
			//ans = (unsigned long long)(ans*us[r[i]])%bi;
		} else {
			int tot = 0;
			for (int l =0;l < m;l++){
				tot = (ge(k-w[l].first)+tot)%bi;
				us[r[i]][w[l].second] = (us[r[i]][w[l].second]+(ge(k-w[l].first)+tot)%bi)%bi;
				//cout << us[r[i]][w[l].second] << endl;
				cout << tot << endl;
			}
			cout << tot << endl;
			ans = (unsigned long long)(ans*tot)%bi;
			//us[r[i]] = tot;
		}
	}
	cout <<  ans;
	return 0;
}
