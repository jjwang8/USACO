//============================================================================
// Name        : sleepycowsorting.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
int n, ss;
vector<int> a(100000);
queue<int> in;
int rep(int x, int st){
	int low = st, h = n-1;
	while (low <= h){
		int mid = (low+h)/2;
		if (x < a[mid]){
			h = mid-1;
		} else if (x > a[mid]){
			low = mid+1;
		} else {
		}
	}
	a.insert(a.begin()+low,x);
	a.erase(a.begin());
	ss--;
	return low-1;
}
int main() {
	ifstream fin("sleepy.in");
	ofstream fout("sleepy.out");
	cin >> n;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	int st = a[n-1];
	for (int i = n-1;i >= 0;i--){
		//cout << i << endl;
		if (a[i] <= st){
			ss = i;
			st = a[i];
		} else {
			break;
		}
	}
	//cout << ss << endl;
	while(ss > 0){
		in.push(rep(a[0],ss));
		//for (int l =0;l < n;l++){
		//	cout << a[l];
		//}
		//cout << endl;
		//cout << ss << endl;
	}
	cout << in.size() << endl;
	while(in.size()>0){
		//cout << "aaa" << endl;
		//cout << in.size() << endl;
		if (in.size() == 1){
			cout << in.front();
		}
		else {
			cout << in.front() << " ";
		}
		in.pop();
	}
	return 0;
}
