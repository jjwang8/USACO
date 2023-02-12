#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
int n,tot = 0, st = 0, en = 0, ctot = 0;
bool so = 0;
vector<int> a;
bool s[10005] = {};
int ks(int x){
	//cout << x << endl;
	s[0] = 1;
	bool v[10005] = {};
	int r = min(st, n-a[x]);
	for (int i = 0; i <= r;i++){
		//cout << i+a[x] << " " << x << " " << r << endl;
		if (i+a[x] > n){
			if (ctot - i > n){
				so = 1;
				return 0;
			}
			continue;
		}
		if (s[i] && v[i] != 1){
			if (!s[i+a[x]]){
				v[i+a[x]] = 1;
			}
			s[i+a[x]] = 1;
			st = max(st, i+a[x]);
		}
	}
	return 0;
}
int main() {
	cin >> n;
	n = n*100;
	int temp;
	cin >> temp;
	tot += temp;
	en++;
	while(!(temp == 0 || tot > 2*n)){
		a.push_back(temp);
		cin >> temp;
		tot += temp;
		en++;
	}
	tot = 0;
	for (int i = 0; i <= n;i++){
		s[i] = 0;
	}
	for (int i = 0; i < en;i++){
		ctot += a[i];
		ks(i);
		if (so == 1){
			cout << i << endl;
			break;
		}
	}
	if (so != 1){
		cout << en-1;
	}
	return 0;
}
