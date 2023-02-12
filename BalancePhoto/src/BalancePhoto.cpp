//============================================================================
// Name        : BalancePhoto.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;
int n;
vector<pair<int, int> > a;
vector<int> b;
bool bal(int x){
	if (b.size() == 0){
		b.push_back(x);
		return 1;
	} else if (b.size() == 1 && x != b[0]){
		if (b[0] > x){
			b.insert(b.begin(), x);
		} else {
			b.insert(b.begin()+1, x);
		}
		return 0;
	}
	int low = 0, h = b.size()-1;
	while (low <= h){
		int mid = (low+h)/2;
		if (x < b[mid]){
			h = mid-1;
		} else if (x > b[mid]){
			low = mid+1;
		} else {
		}
	}
	int left = ++h, right = b.size()-low;
	b.insert(b.begin()+low,x);
	if (min(left, right)*2 < max(left, right)){
		return 0;
	} else {
		return 1;
	}
}
int main() {
	ifstream fin("bphoto.in");
	ofstream fout("bphoto.out");
	fin >> n;
	for (int i = 0;i < n;i++){
		int temp;
		fin >> temp;
		a.push_back(make_pair(temp, i));
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	//for (int i =0; i< n;i++){
	//	cout << a[i].first << " " << a[i].second << endl;
	//}
	int tot = 0;
	for (int i =0;i < n;i++){
		if (!bal(a[i].second)){
			tot++;
		}
	}
	cout << tot;
	return 0;
}
