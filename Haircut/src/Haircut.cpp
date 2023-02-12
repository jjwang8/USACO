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
int n;
int a[100005] = {};
long long inc[100005] = {};
struct da{
	int c[2] = {-1,-1};
	int val = -1;
	long long si[2] = {};
	int par = -1;
	int am = 1;
};
vector<da> tr;
void up(int x){
	while (x != 0){
		int org = x;
		//cout << x << endl;
		x = tr[x].par;
		if (tr[x].c[0] == org){
			tr[x].si[0]++;
		} else {
			tr[x].si[1]++;
		}
	}
}
void ch(int x){
	if (tr.size() == 0){
		da temp;
		temp.val = a[x];
		tr.push_back(temp);
	}
	else {
		bool t = 1;
		long long en = 0, tot = 0;
		while (t){
			if (tr[en].val == a[x]){
				tot += tr[en].si[1];
				inc[a[x]] += tot;
				tr[en].am++;
				t = 0;
				up(en);
			} else if (tr[en].val > a[x]){
				if (tr[en].c[0] == -1){
					tot += tr[en].si[1] + tr[en].am;
					inc[a[x]] += tot;
					da temp;
					temp.val = a[x], temp.par = en;
					tr.push_back(temp);
					tr[en].c[0] = tr.size()-1;
					tr[en].si[0]++;
					up(en);
					t = 0;
				}
				else {
					tot += tr[en].am + tr[en].si[1];
					en = tr[en].c[0];
				}
			} else {
				if (tr[en].c[1] == -1){
					inc[a[x]] += tot;
					da temp;
					temp.val = a[x], temp.par = en;
					tr.push_back(temp);
					tr[en].c[1] = tr.size()-1;
					tr[en].si[1]++;
					up(en);
					t = 0;
				} else {
					en = tr[en].c[1];
				}
			}
		}
	}
}
int main() {
	ifstream fin("haircut.in");
	ofstream fout("haircut.out");
	fin >> n;
	for (int i = 0; i < n;i++){
		fin >> a[i];
	}
	for (int i = 0; i < n;i++){
		ch(i);
	}
	long long tot = 0;
	for (int i = 0; i < n;i++){
		fout << tot << endl;
		tot += inc[i];
	}
	return 0;
}
