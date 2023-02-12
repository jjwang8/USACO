//============================================================================
// Name        : MooTube.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,q;
vector<vector<pair<int, int> > > a(100050);
vector<pair<int, int> > b;
queue<vector<int> > c;
int main() {
	ifstream fin("");
	ofstream fout("");
	cin >> n;
	cin >> q;
	for (int i = 0; i < n-1;i++){
		int temp[3];
		for (int l = 0; l < 3;l++){
			cin >> temp[l];
		}
		a[temp[0]].push_back(make_pair(temp[1], temp[2]));
		a[temp[1]].push_back(make_pair(temp[0], temp[2]));
	}
	for (int i = 0;i < q;i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		b.push_back(make_pair(temp[0],temp[1]));
	}
	sort(b.begin(),b.end());
	reverse(b.begin(), b.end());
	//for (int i =0;i<q;i++){
	//	cout << b[i].first << " " << b[i].second << endl;
	//}
	return 0;
}
