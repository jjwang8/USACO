//============================================================================
// Name        : DirectoryTravel.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int> > a(100005);
string aa[100005] = {};
int si[100005] = {};
int fsi(int x){
	for (int i = 0; i < a[x].size();i++){
		si[x] += fsi(a[x][i])+1;
	}
	si[x] += aa[x].length();

	return si[x];
}
void ffc(int x, int par){
	si[x] += si[par]-si[x]-1+2-aa[x].size();
	if (par != 0){
		si[x]++;
	}
	for (int i = 0; i < a[x].size();i++){
		ffc(a[x][i], x);
	}
}
int main() {
	cin >> n;
	for (int i = 0;i < n;i++){
		cin >> aa[i];
		int temp;
		cin >> temp;
		for (int l = 0; l < temp;l++){
			int temp1;
			cin >> temp1;
			a[i].push_back(temp1-1);
		}
	}
	fsi(0);
	for (int i = 0; i < a[0].size();i++){
		ffc(a[0][i], 0);
	}
	int mi = (1<<30);
	cout << si[0] << endl;
	for (int i = 0; i < n;i++){
		cout << si[i]-a[i].size()-aa[i].size() << endl;
		if (mi > si[i]-a[i].size()-aa[i].size()){
			mi = si[i]-a[i].size()-aa[i].size();
			cout << i << endl;
		}
	}
	cout << mi << endl;
	return 0;
}
