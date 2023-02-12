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
vector<vector<int> > a;
string s;
int n,m,k;
int dp[100005][30] = {{}};
int ps[100005][30];
int dpm[100005] = {};
void fw(){
	vector<vector<int> > temp;
	for (int i = 0; i < m;i++){
		vector<int> temp1;
		for (int l = 0; l < m;l++){
			temp1.push_back(a[i][l]);
		}
		temp.push_back(temp1);
	}
	for (int i = 0; i < m;i++){
		for (int l = 0; l < m;l++){
			for (int j = 0; j < m;j++){
				temp[l][j] = min(temp[l][j], temp[l][i] + temp[i][j]);
			}
		}
	}
	for (int i = 0; i < m;i++){
		for (int l = 0; l < m;l++){
			a[i][l] = temp[i][l];
		}
	}
}
void psum(int st, int en, int let){
	ps[st][let] = a[s[0]-'a'][let];
	//cout << ps[st][let] << " ";
	for (int i = st+1; i < en;i++){
		ps[i][let] = ps[i-1][let]+(a[s[i]-'a'][let]);
		//cout << ps[i][let] << " ";
	}
	//cout << endl;
}
int main() {
	ifstream fin("cowmbat.in");
	ofstream fout("cowmbat.out");
	cin >> n;
	cin >> m;
	cin >> k;
	cin >> s;
	for (int i = 0; i < m;i++){
		vector<int> temp(m+1);
		for (int l = 0;l < m;l++){
			cin >> temp[l];
		}
		a.push_back(temp);
	}
	fw();
	for (int i = 0; i < m;i++){
		psum(0,n,i);
	}
	for (int i = 0; i < n;i++){
		for (int l = 0;l < m;l++){
			dp[i][l] = (1<<30);
			dp[0][l] = a[s[0]-'a'][l];
			dpm[0] = min(dp[0][l],dpm[0]);
		//	cout << dp[0][l] << endl;
		}
		dpm[i] = (1<<30);
	}
	//for (int i = 0; i < m;i++){
	//	for (int l = 0;l < m;l++){
	//		cout << a[i][l] << " ";
	//	}
	//	cout << endl;
	//}
	for (int i = 1;i < n;i++){
		for (int l = 0; l < m;l++){
			dp[i][l] = min(dp[i][l], dp[i-1][l]+a[s[i]-'a'][l]);
			if (i >= k-1 && i-k < 0){
				dp[i][l] = min(dp[i][l], ps[i][l]);
			} else if (i >= k-1){
				dp[i][l] = min(dp[i][l], ps[i][l]-ps[i-k][l]+dpm[i-k]);
			}
			dpm[i] = min(dpm[i], dp[i][l]);
			//cout << dp[i][l] << i << l << endl;
		}
	}
	//for (int i = 0; i < n;i++){
	//	cout << dpm[i] << " ";
	//}
	//cout << endl;
	cout << dpm[n-1];
	return 0;
}
