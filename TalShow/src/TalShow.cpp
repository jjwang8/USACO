#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
double w, tot = 0;
double a[50000000][3];
vector<int> dp(300000);
void cre(int s, int x, int p){
	if (dp[s] != 0 && dp[s] > p){

	}else {
		dp[s] = p;
	}
	for (int i =x;i < n;i++){
		//cout << p << " " << a[i][1] << endl;
		cre(s+a[i][0], i+1, p+a[i][1]);
	}
}
int main(){
	cin >> n;
	cin >> w;
	for(int i =0;i < n;i++){
		cin >> a[i][0];
		cin >> a[i][1];
		tot += a[i][0];
	}
	//for (int i = 0;i < n;i++){
		//cout << a[i][0] << " " << a[i][1] << endl;
	//}
	cre(0,0,0);
	//for (int i =0;i < 100;i++){
	//	cout << dp[i] << endl;
	//}
	double ma = -1;
	for (int i = w;i < tot;i++){
		if (dp[i] == 0){
			continue;
		}
		double temp = (double(dp[i])/double(i));
		ma = max(ma, temp);
		//cout << temp << " " << dp[i] << " " << i << endl;
	}
	cout << floor(ma*1000) << endl;
	return 0;
}
