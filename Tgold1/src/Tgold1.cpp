#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <fstream>
using namespace std;
int n,q,en[100005],re[100005][3];
vector<vector<int > > a(100000);
queue<pair<int,pair<int, pair<int,int > > > > v;
int ou[100000];
void p(){
	int d[50000][100005] = {0};
	while(!v.empty()){
		pair<int,pair<int,pair<int,int> > > cur;
		cur = v.front();
		v.pop();
		d[cur.second.second.second][cur.first] =1;
		//cout << d[cur.first] << endl;
		for (int i = 0; i < a[cur.first].size();i++){
			if (d[cur.second.second.second][a[cur.first][i]] == 1){
				continue;
			}
			if (a[cur.first][i] == cur.second.second.first){
				//cout << "aaa" << endl;
				//cout << en[a[cur.first][i]] << " " << cur.second << endl;
				ou[cur.second.second.second]= cur.second.first^en[a[cur.first][i]];
			}
			//cout << cur.second << endl;
			v.push(make_pair(a[cur.first][i],cur.second.first^en[a[cur.first][i]]));
		}
	}
}
int main(){
	ifstream fin("cowland.in");
	ofstream fout("cowland.out");
	cin >> n >> q;
	for (int i = 0; i < n;i++){
		cin >> en[i+1];
	}
	for (int i = 0; i < n-1;i++){
		int temp[2];
		cin >> temp[0] >> temp[1];
		a[temp[0]].push_back(temp[1]);
		a[temp[1]].push_back(temp[0]);
	}
	for (int i = 0;i < q;i++){
		cin >> re[i][0] >> re[i][1] >> re[i][2];
	}
	int con = 0;
	for (int i = 0; i< q;i++){
		if (re[i][0] == 2){
			con++;
			v.push(make_pair(re[i][1],make_pair(en[re[i][1]],make_pair(re[i][2],i))));
		} else{
			con = 0;
			p();
			for (int i = 0; i < con;i++){
				cout << ou[i-con] << endl;
			}
			con = 0;
			en[re[i][1]] = re[i][2];
		}
	}
}
