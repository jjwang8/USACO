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
vector<int> a;
vector<pair<int, int > > b;
int n, q;
int dif[5005][5005] = {{}};
int dp[5005][5005] = {{}};

int main() {
	ifstream fin("threesum.in");
	ofstream fout("threesum.out");
	fin >> n;
	fin >> q;
	for (int i =0; i < n;i++){
		int temp;
		fin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < q;i++){
		pair<int, int> temp;
		fin >> temp.first;
		fin >> temp.second;
		temp.first--, temp.second--;
		b.push_back(temp);
	}
	for (int i = 0; i < n;i++){
		int loc[2*1000000+1] = {};
		for (int l =i;l < n;l++){
			if (abs(i-l) < 2){
				if (abs(i-l) == 0){
					continue;
				}
				loc[a[l]+1000000]++;
				continue;
			}
			dif[i][l] = loc[-(a[i]+a[l])+1000000];
			loc[a[l]+1000000]++;
			//cout << i << " " << l << " " << dif[i][l] << endl;
		}
	}
	//cout << "aaa" << endl;
	for (int i = 0; i < n;i++){
		for (int l = i;l >= 0;l--){
			pair<int, int> temp;
			temp.first = min(i,l), temp.second = max(i,l);
			if (temp.second-temp.first < 2){
				dp[temp.first][temp.second] = 0;
				continue;
			}
			if (temp.second-temp.first == 2){
				dp[temp.first][temp.second] = dif[temp.first][temp.second];
				continue;
			}
			dp[temp.first][temp.second] = dif[temp.first][temp.second]+dp[temp.first+1][temp.second]+dp[temp.first][temp.second-1]-dp[temp.first+1][temp.second-1];
		}
	}
	for (int i = 0;i < q;i++){
		fout << dp[b[i].first][b[i].second] << endl;
	}
	return 0;
}
