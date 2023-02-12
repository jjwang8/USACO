#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int n;
struct nod{
	int no;
	bool st;
};
vector<vector<int> > a;
vector<vector<nod> > p(200005);
vector<vector<nod> > g(200005);
int v[100005][2];
vector<vector<int> > con(100005);
int dfs(nod x, int c){

	if (v[x.no][x.st] == 1){
		return 0;
	}
	//cout << c << " " << x.no << " " << x.st << endl;
	v[x.no][x.st] = 1;
	g[c].push_back(x);
	if (x.st == 0){
		for (int i = 1; i <= 2;i++){
			nod cur;
			if (p[a[x.no][i]][0].no == x.no && p[a[x.no][i]][0].st == x.st){
				cur = p[a[x.no][i]][1];
			} else {
				cur = p[a[x.no][i]][0];
			}
			dfs(cur, c);
		}
	} else {
		for (int i = 3; i <= 4;i++){
			nod cur;
			if (p[a[x.no][i]][0].no == x.no && p[a[x.no][i]][0].st == x.st){
				cur = p[a[x.no][i]][1];
			} else {
				cur = p[a[x.no][i]][0];
			}
			dfs(cur, c);
		}
	}

}
int main() {
	cin >> n;
	for (int i = 0; i < n;i++){
		vector<int> temp(5);
		for (int l = 0; l < 5;l++){
			cin >> temp[l];
		}
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size();i++){
		nod temp;
		temp.no = i;
		temp.st = 0;
		p[a[i][1]].push_back(temp);
		p[a[i][2]].push_back(temp);
		temp.st = 1;
		p[a[i][3]].push_back(temp);
		p[a[i][4]].push_back(temp);
	}
	int cur = 0;
	for (int i = 0; i < n;i++){
		nod temp;
		temp.no = i;
		if (v[i][0] == 0){
			temp.st = 0;
			dfs(temp, cur);
			cur++;
		}
		if (v[i][1] == 0){
			temp.st = 1;
			dfs(temp, cur);
			cur++;
		}
	}
	int cyc[100005] = {};
	vector<vector<int> > gro(100005);
	for (int i = 0; i <= cur;i++){
		for (int l = 0; l < g[i].size();l++){
			con[g[i][l].no].push_back(i);
		}
		cyc[i] = i;
		gro[i].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < n;i++){
		if (con[i][0] == con[i][1]){
			continue;
		}
		if (cyc[con[i][0]] == cyc[con[i][1]]){
			continue;
		}
		int org = cyc[con[i][0]];
		for (int l = 0; l < gro[org].size();l++){
			gro[cyc[con[i][1]]].push_back(gro[org][l]);
			cyc[gro[org][l]] = cyc[con[i][1]];
		}

		//cyc[con[i][1]] = cyc[con[i][0]];
		ans += a[i][0];
	}
	cout << ans << endl;
	return 0;
}
/*3
1 1 2 3 4
2 6 2 3 5
3 5 6 1 4
*/
