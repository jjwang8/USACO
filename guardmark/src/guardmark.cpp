//============================================================================
// Name        : guardmark.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
int n,h, c[25][3];
unordered_map<int, pair<int, pair<int, int> > > a;
priority_queue<int> mi;
bool bil;
int main() {
	cin >> n;
	cin >> h;
	for (int i = 0; i < n;i++){
		cin >> c[i][0];
		cin >> c[i][1];
		cin >> c[i][2];
	}
	a[0] = make_pair(0, make_pair((1<<30),0));
	for (int i = 0; i < h; i = i+0){
		for (int l = a[i].second.second;l < n; l++){
			//if (a[i].second.first- c[l][1] < 0){
			//	continue;
			//}
			if (a[i+c[l][0]].second.first >= min(a[i].second.first-c[l][1],c[l][2])){
				//continue;
			}
			//cout << min(a[i].second.first-c[l][1],c[l][2]) << " " << c[l][0] << " " << i<< " " << l << endl;
			if (i+c[l][0] >= h){

				if (a[h].second.first >= min(a[i].second.first-c[l][1],c[l][2])){
					//continue;
				}
				a[h] = make_pair(a[i].first+c[l][1], make_pair(min(a[i].second.first-c[l][1],c[l][2]), n));
				mi.push(-(i+c[l][0]));
				bil = 1;
				cout << a[h].first << " " << a[i+c[l][0]].second.first << " " << a[i+c[l][0]].second.second << endl;
				continue;
			}
			a[i+c[l][0]] = make_pair(a[i].first+c[l][1], make_pair(min(a[i].second.first-c[l][1],c[l][2]),l+1));
			//cout << a[i+c[l][0]].first << " " << a[i+c[l][0]].second.first << " " << a[i+c[l][0]].second.second << endl;
			//mi = min(i+c[l][0], mi);
			mi.push(-(i+c[l][0]));
		}
		if (mi.size() == 0 && bil != 1){
			cout << "Mark is too tall!!!" << endl;
			return 0;
		}
		i = -mi.top();
		//cout << i << endl;
		mi.pop();
	}
	if (bil != 1){
		cout << "Mark is too tall" << endl;
	} else {
		cout << a[h].second.first << endl;
	}
	return 0;
}
