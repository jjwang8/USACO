#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int n;
vector<vector<pair<int, int> > > a(100000);
int p(){
	priority_queue<pair<int, int> > q;
	q.push(make_pair(-0,1));
	int dis[100000];
	for (int i = 0;i< 100000;i++){
		dis[i] = (1<<30);
	}
	dis[1] = 0;
	while(!q.empty()){
		pair<int, int> cur;
		cur = q.top();
		q.pop();
		cur.first = -cur.first;
		for (int i = 0; i < a[cur.second].size();i++){
			if (dis[a[cur.second][i].first] > cur.first+a[cur.second][i].second){
				dis[a[cur.second][i].first] = cur.first+a[cur.second][i].second;
				//cout << dis[a[cur.second][i].first] << endl;
				q.push(make_pair(-(cur.first+a[cur.second][i].second),a[cur.second][i].first));
			}
		}
	}
	return dis[5];
}
int main(){
	cin >> n;
	for (int i = 0; i < n;i++){
		int temp[3];
		cin >> temp[0] >> temp[1] >> temp[2];
		a[temp[0]].push_back(make_pair(temp[1], temp[2]));
		a[temp[1]].push_back(make_pair(temp[0], temp[2]));
	}
	cout << p() << endl;
}
