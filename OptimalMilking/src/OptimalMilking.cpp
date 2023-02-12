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
int n,d;
int a[40005] = {};
int dp[205][4] = {};
int tdp[205][205];
int f(int s, int t, int sec){
	cout << s << " " << t << " " << sec << endl;
	cout << sec*floor(sqrt(n))+floor(sqrt(n))-1 << " " << sec*floor(sqrt(n))+floor(sqrt(n))-2 << endl;
	if (tdp[sec][s] > 0){
		return tdp[sec][s];
	}
	if (s == sec*floor(sqrt(n))){
		if (t < 2){
			int temp = f(s+1, t, sec);
			return temp;
		} else {
			int temp = f(s+2, t, sec)+a[s];
			return temp;
		}
	}
	if (s >= sec*floor(sqrt(n))+floor(sqrt(n))-1){
		if (t == 1 || t == 3){
			tdp[sec][s] = a[s];
			return a[s];
		} else {
			tdp[sec][s] = 0;
			return 0;
		}
	}
	if (s == sec*floor(sqrt(n))+floor(sqrt(n))-2){
		if (t == 1 || t == 3){
			tdp[sec][s+1] = a[s+1];
			tdp[sec][s] = a[s+1];
			return 0;
		} else {
			tdp[sec][s+1] = 0;
			tdp[sec][s] = a[s];
			return a[s];
		}
	}
	tdp[sec][s] = max(f(s+2,t, sec)+a[s], f(s+1, t, sec));
	return tdp[sec][s];
}
vector<vector<int> > sdp;
int cal(int s, bool t, int nu){
	if (sdp[nu][s] > 0){
		return sdp[nu][s];
	}
	if (s == floor(sqrt(n))+1){
		if (t){
			return max(dp[s][2], dp[s][3]);
		}
		return max(dp[s][0], dp[s][1]);
	}
	sdp[nu][s] = max(max(cal(s+1, 0, nu),cal(s+1,1, nu))+dp[s][t*2], cal(s+1,0, nu)+dp[s][1+t*2]);
	return sdp[nu][s];
}
int main() {
	cin >> n;
	cin >> d;
	for (int i =0; i < n;i++){
		cin >> a[i];
	}
	for (int i = 0; i <= floor(sqrt(n))+1;i++){
		for (int l = 0; l < 4;l++){
			for (int j = 0; j < sqrt(n)+1;j++){
				tdp[i][j] = 0;
			}
			dp[i][l] = f(i*floor(sqrt(n)),l, i);
		}
	}
	cout << "aaa" << endl;
	signed long long tot = 0;
	for (int i = 0; i < d; i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		a[temp[0]] = temp[1];
		for (int l = 0; l < 4;l++){
			for (int j = 0; j < floor(sqrt(n));j++){
				tdp[(int)(temp[0]/floor(sqrt(n)))][j] = 0;
			}
			f(floor(temp[0]/floor(sqrt(n)))*floor(sqrt(n)), l, temp[0]/floor(sqrt(n)));
		}
		vector<int> t(floor(sqrt(n))+1);
		sdp.push_back(t);
		tot += max(cal(0,0,i), cal(0,1,i));
	}
	cout << tot << endl;
	return 0;
}
