//============================================================================
// Name        : ClosingFarm.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
int n,m,g,gn;
vector<vector<int> > a(100000);
vector<int> b;
vector<bool> c;
vector<int> d(100000);
unordered_map<string, bool> ch;
bool de(int x){
	bool inn = 0;
	int temp = 0;
	for (int i = 0;i < a[x].size();i++){
		string temp2;
		if (d[a[x][i]] != 0){
			d[x] = d[a[x][i]];
			//cout << inn << endl;
		}
		temp2 = (char)temp;
		temp2= temp2+(char)d[a[x][i]];
		//cout << temp2;
		cout << d[a[x][i]] <<  " " << x << " " << inn  << " " << temp  << " " << ch[temp2] << " " << ch[temp2] << endl;
		if (d[a[x][i]] != 0 && inn && d[a[x][i]] != temp && (ch[temp2] == 0)){
			ch[temp2] = 1;
			temp2 = (char)d[a[x][i]];
			temp2= temp2+(char)temp;
			ch[temp2] = 1;
			g--;
		}
		if (d[a[x][i]] != 0){
			temp = d[a[x][i]];
			inn = 1;
		}
	}
	if (inn == 0){
		g++;
		d[x] = ++gn;
	}
	//cout << g << " " << x << endl;
	if (g == 1){
		return 1;
	} else {
		return 0;
	}
}
int main() {
	cin >> n;
	cin >> m;
	for (int i =0;i < m;i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		a[temp[0]].push_back(temp[1]);
		a[temp[1]].push_back(temp[0]);
	}
	for (int i =0;i < n;i++){
		int temp;
		cin >> temp;
		b.push_back(temp);
	}
	for (int i = b.size()-1; i >= 0;i--){
		c.push_back(de(b[i]));
	}
	for (int i = c.size()-1;i >= 0;i--){
		if (c[i]){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

