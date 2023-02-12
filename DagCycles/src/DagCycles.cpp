#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
#include <algorithm>
using namespace std;
int n,m,k,ma = 0, ans = 0, re;
string a[100];
bool v[100][100][2] = {{{}}};
int mov[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
bool val(int x, int y){
	return !((x < 0 || y > n) || (x > n || y < 0));
}
int sp(int x, int y, bool s){
	queue<pair<pair<int, int>, bool> > q;
	int tot = 0;
	q.push(make_pair(make_pair(x,y),s));
	bool w = 0;
	while(q.size() > 0){
		pair<pair<int, int>, bool> cur;
		cur = q.front();
		q.pop();
		if (v[cur.first.first][cur.first.second][cur.second]){
			continue;
		}
		v[cur.first.first][cur.first.second][cur.second] = true;
		cout << cur.first.first << " " << cur.first.second  << " " << cur.second << endl;
		for (int i = 0; i < 4;i++){
			if (cur.second){
				if (a[cur.first.first][cur.first.second] == '/'){

					if (i == 1 || i == 2){
						if (!val(cur.first.first+mov[i][0], cur.first.second+mov[i][1])){
							//cout << cur.first.first+mov[i][0] << " " << cur.first.second+mov[i][1] << endl;
							w = 1;
							continue;
						}
						if (v[cur.first.first+mov[i][0]][cur.first.second+mov[i][1]][!(a[cur.first.first+mov[i][0]][cur.first.second+mov[i][1]] == '/' || i == 2)]){
							continue;
						}
						q.push(make_pair(make_pair(cur.first.first+mov[i][0], cur.first.second+mov[i][1]),
								!(a[cur.first.first+mov[i][0]][cur.first.second+mov[i][1]] == '/' || i == 2)));
					}
				} else {
					if (i == 2 || i == 3){
						if (!val(cur.first.first+mov[i][0], cur.first.second+mov[i][1])){
							//cout << cur.first.first+mov[i][0] << " " << cur.first.second+mov[i][1] << endl;;
							w = 1;
							continue;
						}
						if (v[cur.first.first+mov[i][0]][cur.first.second+mov[i][1]][!(a[cur.first.first+mov[i][0]][cur.first.second+mov[i][1]] == '\\' || i == 2)]){
							continue;
						}
						q.push(make_pair(make_pair(cur.first.first+mov[i][0], cur.first.second+mov[i][1]),
								!(a[cur.first.first+mov[i][0]][cur.first.second+mov[i][1]] == '\\' || i == 2)));
					}
				}
			} else {
				if (a[cur.first.first][cur.first.second] == '/'){
					if (i == 0 || i == 3){
						if (!val(cur.first.first+mov[i][0], cur.first.second+mov[i][1])){
							//cout << cur.first.first+mov[i][0] << " " << cur.first.second+mov[i][1] << endl;
							w = 1;
							continue;
						}
						if (v[cur.first.first+mov[i][0]][cur.first.second+mov[i][1]][a[cur.first.first+mov[i][0]][cur.first.second+mov[i][1]] == '/' || i == 0]){
							continue;
						}
						q.push(make_pair(make_pair(cur.first.first+mov[i][0], cur.first.second+mov[i][1]),
								a[cur.first.first+mov[i][0]][cur.first.second+mov[i][1]] == '/' || i == 0));
					}
				} else {
					if (i == 0 || i == 1){
						if (!val(cur.first.first+mov[i][0], cur.first.second+mov[i][1])){
							//cout << cur.first.first+mov[i][0] << " " << cur.first.second+mov[i][1] << endl;
							w = 1;
							continue;
						}
						if (v[cur.first.first+mov[i][0]][cur.first.second+mov[i][1]][a[cur.first.first+mov[i][0]][cur.first.second+mov[i][1]] == '\\' || i == 0]){
							continue;
						}
						q.push(make_pair(make_pair(cur.first.first+mov[i][0], cur.first.second+mov[i][1]),
								a[cur.first.first+mov[i][0]][cur.first.second+mov[i][1]] == '\\' || i == 0));
					}
				}
			}
		}
		//cout << tot << endl;
		tot++;
	}
	if (w){
		return -1;
	}
	return tot;
}
int main() {
	cin >> m;
	cin >> n;
	for( int i = 0; i < n;i++){
		cin >> a[i];
	}
	for (int i = 0; i < n;i++){
		for (int l = 0; l < m;l++){
			for (int j = 0; j < 2;j++){
				if (v[i][l][j]){
					continue;
				}
				re = sp(i,l,j);
				if (re == -1 || re == 0){
					continue;
				}
				ma = max(re, ma);
				cout << re << "aaa" << i << " " << l << " " << j<< endl;
				ans++;

			}
		}
	}
	if (ans == 0){
		cout << "There are no cycles." << endl;
	} else {
		cout << ans << " Cycles; the longest has length " << ma << "." << endl;
	}
	return 0;
}
/*
2 2
/\
\/
*/
