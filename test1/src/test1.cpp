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
int sp(int st, int en){
	if (dp[st][en] > 0){
		return dp[st][en];
	}
	dp[st][en] = dif[st][en]+sp(st+1, en)+sp(st, en-1)-sp(st+1,en-1);
	return dp[st][en];
}
int main() {
	int checker = 0;
	int counter = 1;
	int num1 = 1;
	int num2 = 7;
	int r = 0;
	int i = 0;
	for (i = 0; i*num2 <= num1; i++);
	cout << i-1 << endl;
	r = num1 - (i-1)*num2;
	//cout << r << endl;
	int c= 0;
	while (r != 0 && c < 20){
		num1 = r*10;
		num2;
		//cout << num1 << " " << num2 << endl;
		for (i = 0; i*num2 <= num1; i++);
		r = num1 - (i-1)*num2;
		cout << i-1 << endl;
		c++;
	}
	return 0;
}
