#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
#include <algorithm>
using namespace std;
int n, m;
vector<pair<int, int> > a;
vector<int> b;
vector<int> c;
int tot = 0;
int sm = -1,smn = 0;
int bal(int x, bool t){
	if (b.size() == 0){
		b.push_back(x);
		return 0;
	}
	if (t){
		int low = 0, h = c.size()-1;
		while (low <= h){
			int mid = (low+h)/2;
			if (x < c[mid]){
				h = mid-1;
			} else if (x > c[mid]){
				low = mid+1;
			} else {
			}
		}
		int left = ++h, right = c.size()-low;
		b.insert(b.begin()+low,x);
		return c.size()-1-low;
	} else {
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
		return b.size()-1-low;
	}
}
int main() {
	ifstream fin("");
	ofstream fout("");
	cin >> n;
	for (int i = 0;i < n;i++){
		int temp[2];
		cin >> temp[0];
		temp[1] = i;
		a.push_back(make_pair(temp[0],temp[1]));
	}
	sort(a.begin(),a.end());
	for (int i = 0; i < n;i++){
		if (a[i].first > n-1){
			a[i].first = n-1;
		}
		if (sm == a[i].first){
			smn++;
			tot+= bal(a[i].second, 1);
		} else{
			c = b;
			sm == a[i].first;
			smn =0;
			tot += bal(a[i].second, 0);
		}
	}
	for (int i = n-2; i < n;i++){

	}
	cout << tot << endl;
	return 0;
}
