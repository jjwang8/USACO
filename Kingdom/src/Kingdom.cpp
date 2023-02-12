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
int n,m,k;
vector<vector<int> > a(100005);
int mov[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int v[100005] = {};
int dp[100005][2][2] = {{}};
int sp(int loc, bool col, int pcol){
	if (dp[loc][col][pcol] > 0){
		return dp[loc][col][pcol];
	}
	int tot = 1;
	int opp = 1;
	//cout << loc <<  " " << col << " " << pcol << endl;
	if (a[loc].size() == 1){
		if (col != pcol){
			//cout << loc << endl;
			return 0;
		}
		return 1;
	}
	v[loc] = 1;
	for (unsigned int i = 0; i < a[loc].size();i++){
		int temp = 0;
		if (v[a[loc][i]]){
			continue;
		}
		if (col == pcol){
			int res = sp(a[loc][i], 0, col);
			if (res != 0){
				temp += res;
			}
			//cout << res  << "aaa" << temp  << " " << loc << endl;
			res = sp(a[loc][i], 1, col);
			if (res != 0){
				temp += res;
			}
			//cout << res  << "aaa" << temp  << " " << loc << endl;
		} else {
			int res = sp(a[loc][i], 0, col);
			if (res != 0){
				temp += res;

			}
			if (0 != col){
				opp *= res;
			}
			//cout << res  << "aaa" << temp  << " " << loc << endl;
			res = sp(a[loc][i], 1, col);
			if (res != 0){
				temp += res;
			}
			if (1 != col){
				opp *= res;
			}
			//cout << res  << "aaa" << temp  << " " << loc << endl;
		}
		tot *= temp;
	}
	if (col != pcol){
		tot -= opp;
	}
	v[loc] = 0;
	dp[loc][col][pcol] = tot;
	return tot;
}
int main() {
	cin >> n;
	for(int i = 0; i < n-1;i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		a[temp[0]].push_back(temp[1]);
		a[temp[1]].push_back(temp[0]);
	}
	cout << sp(1,0,1)*2%1000000009;
	return 0;
}
