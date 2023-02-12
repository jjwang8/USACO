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
set<int> a;
set<int>::iterator it;
pair<set<int>::iterator,bool> ret;
//vector<vector<int> > lcmdp(10000, vector<int>(10000));
int sumdp[100000];
long long int lcm(long long int x, long long int y)
		{
			if(x==0)
				return y;
			if(y==0)
				return x;
			long long int r=0, a, b;
			a = (x > y) ? x : y; // a is greater number
			b = (x < y) ? x : y; // b is smaller number
			r = b;
			while(a % b != 0)
			{
				r = a % b;
				a = b;
				b = r;
			}
			return (x*y)/r;
}
int sums(int x){
	//cout << sumdp[x] << " " << x << endl;
	if (sumdp[x] > 0){
		return sumdp[x];
	}
	//cout << sumdp[x] << " " << x << endl;
	for (int i = 2; i <= x/2;i++){
		a.insert(lcm(i,x-i));
		a.insert(lcm(sums(i),x-i));
		a.insert(lcm(i,sums(x-i)));
		sumdp[x] = lcm(sums(i),sums(x-i));
		a.insert(sumdp[x]);
	}
	if (x == 2 || x == 3){
		sumdp[x] = x;
		return x;
	}
	return sumdp[x];
}
int main() {
	ifstream fin("exercise.in");
	ofstream fout("exercise.out");
	fin >> n;
	fin >> m;
	for (int i = 1; i <= n;i++){
		a.insert(i);
		sumdp[i] = 0;
		//cout << "aaa" << endl;
	}
	for (int i = 2; i <= n/2;i++){
		//cout << lcm(i,n-i) << endl;
		//fout << i << endl;
		a.insert(lcm(i,n-i));
		a.insert(lcm(sums(i),n-i));
		a.insert(lcm(i,sums(n-i)));
		a.insert(lcm(sums(i),sums(n-i)));
	}
	long long tot = 0;
	//cout << a.size() << endl;
	for (it = a.begin(); it!= a.end();++it){
		//cout << "aaa" << endl;
		//fout << *it << endl;
		tot = (*it+tot)%m;
	}
	fout << tot << endl;
	return 0;
}
