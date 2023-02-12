//============================================================================
// Name        : barnpaunsigned long long.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
#include <vector>
#include <fstream>
using namespace std;
unsigned long long con = 1000000007;
unsigned long long n,k, c[100010];
unsigned long long f[100100];
vector<vector<unsigned long long> > a(101000);
unsigned long long st = 0;
unsigned long long dp[100100][3];
unsigned long long d(unsigned long long x, unsigned long long t){
	//fout << x << endl;
	if (dp[x][t] > 0){
		return dp[x][t];
	}
	if (a[x].size() == 1 && x != st){
		//fout << "aaa" << endl;
		return 1;
	}
	unsigned long long ans = 1;
	f[x] = t;
	for (unsigned long long i = 0; i < a[x].size();i++){
		unsigned long long tot = 0;
		if (c[a[x][i]] == t){
			f[x] = 0;
			return 0;
		}
		if (f[a[x][i]] != 0){
				continue;
			}
		for (unsigned long long l = 0;l < 3;l++){
			if (l+1 == t){
				continue;
			}

			if (c[a[x][i]] != l+1 && c[a[x][i]] != 0){
				continue;
			}
			tot = (tot+d(a[x][i], l+1))%con;
			//fout << a[x][i] << " " << tot << endl;
		}
		ans = (ans*tot)%con;
	}
	f[x] = 0;
	dp[x][t] = ans;
	return ans;
}
int main() {
	ifstream fin("barnpainting.in");
	ofstream fout("barnpainting.out");
	fin >> n;
	fin >> k;
	for (unsigned long long i = 0; i < n-1;i++){
		unsigned long long temp[2];
		fin >> temp[0];
		fin >> temp[1];
		a[temp[0]].push_back(temp[1]);
		a[temp[1]].push_back(temp[0]);
	}

	for (unsigned long long i = 0;i < k;i++){
		unsigned long long temp[2];
		fin >> temp[0];
		fin >> temp[1];
		st = temp[0];
		c[temp[0]] = temp[1];
	}
	fout << d(st, c[st])<< endl;
	return 0;
}
