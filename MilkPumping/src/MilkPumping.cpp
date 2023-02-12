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
int n,m,k;
vector<vector<int> > a(100005);
vector<pair<int, int> > lin;
int ty[100005][3] = {{}};
vector<pair<int, int> > pdat;
int ocr[100005] = {};
int v[100005]= {};
int rmq[100005][100] = {{}};
int val[100005] = {};
bool v2[100005] = {};
void plca1(int loc, int lvl){
	pair<int, int> temp;
	temp.first = lvl;
	temp.second = loc;
	pdat.push_back(temp);
	v[loc] = 1;
	if (ocr[loc] == 0 && loc != 1){
		ocr[loc] = pdat.size()-1;
	}
	int con = 0;
	for (unsigned int i = 0; i < a[loc].size();i++){
		if (v[a[loc][i]]){
			continue;
		}
		if (con >= 1){
			pdat.push_back(temp);
		}
		plca1(a[loc][i], lvl+1);
		con++;
	}
}
void plca2(){
	for (int i = 0; i < pdat.size();i++){
		rmq[i][0] = i;
	}
	for (int i = 1; (1<<i) <= pdat.size();i++){
		for (int l = 0; (l+(1<<i)-1) < pdat.size();l++){
			if (pdat[rmq[l][i-1]].first < pdat[rmq[l+(1<<(i-1))][i-1]].first){
				rmq[l][i] = rmq[l][i-1];
			} else {
				rmq[l][i] = rmq[l+(1<<(i-1))][i-1];
			}
		}
	}
}
int lca(int x, int y){
	int temp = (int)log2(y-x+1);
	if (pdat[rmq[x][temp]].first <= pdat[rmq[y-(1<<temp)+1][temp]].first){
		return pdat[rmq[x][temp]].second;
	} else {
		return pdat[rmq[y-(1<<temp)+1][temp]].second;
	}
}
int sp(int loc, int pat){
	int tot = 0;
	v2[loc] = 1;
	for (unsigned int i = 0; i < a[loc].size();i++){
		if (v2[a[loc][i]] > 0){
			continue;
		}
		int temp = sp(a[loc][i], pat+ty[loc][0]-ty[loc][1]);
		tot += temp;
	}
	val[loc] += tot+ty[loc][1];
	return tot-ty[loc][0]+ty[loc][1];
}
int main() {
	cin >> n;
	cin >> k;
	for(int i = 0; i < n-1;i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		a[temp[0]].push_back(temp[1]);
		a[temp[1]].push_back(temp[0]);
	}
	for (int i = 0; i < k;i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		lin.push_back(make_pair(temp[0],temp[1]));
	}
	plca1(1, 1);
	plca2();
	for (int i = 0; i < pdat.size();i++){
		for (int l = 0; l < 10;l++){
			cout << rmq[i][l] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < pdat.size();i++){
		cout << pdat[i].first << " " << pdat[i].second << endl;
	}
	for (int i = 0; i < k;i++){
		int temp = lca(min(ocr[lin[i].first],ocr[lin[i].second]), max(ocr[lin[i].first],ocr[lin[i].second]));
		if (temp == lin[i].first){
			ty[lin[i].first][0]++;
			ty[lin[i].second][1]++;
		} else if (temp == lin[i].second){
			ty[lin[i].second][0]++;
			ty[lin[i].first][1]++;
		} else{
			ty[temp][0] += 2;
			ty[lin[i].first][1]++;
			ty[lin[i].second][1]++;
			val[temp]--;
		}
		cout << temp << lin[i].first << lin[i].second << ocr[lin[i].first] << ocr[lin[i].second]<< endl;
	}
	sp(1, 0);
	int ma = 0;
	for (int i = 1; i <= n;i++){
		if (val[i] > ma){
			ma = val[i];
		}
	}
	cout << ma << endl;
	return 0;
}
/*
1 2
2 4
2 5
1 3
3 6
3 7
 */
