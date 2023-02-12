//============================================================================
// Name        : AirPlaneBoarding.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
vector<pair<int, int> > a;
stack<int> w;
int curp[300000];
int n, at = 0,ti = 0, ct = 0;
bool s = false;
int cal(int c, int e){
	while (w.size() > 0){
		if (e < a[w.top()].first){
			ti += e-(curp[c]+at);
			at += e-(curp[c]+at);
		}
		if (curp[w.top()]+at+ct > a[w.top()].first){
			//ti += a[w.top()].first-(curp[c]+at);
			//at += a[w.top()].first-(curp[c]+at);
			//ct += a[w.top()].first-(curp[c]+at);
			if (a[w.top()].second < ct){
				w.pop();
				continue;
			}
			ti += a[w.top()].second-ct;
			at += a[w.top()].second-ct;
			ct += a[w.top()].second-ct;

			w.pop();
			continue;
		}
		if (curp[c]+at+ct < a[w.top()].first){
			ti += a[w.top()].first-(curp[w.top()]+at+ct);
			at += a[w.top()].first-(curp[w.top()]+at+ct);
			//ct += a[w.top()].first-(curp[c]+at);
			ti += a[w.top()].second;
			ct += a[w.top()].second;
			//ti += a[w.top()].first-(curp[c]+at);
			if (a[w.top()].first- (curp[c]+at) < a[w.top()].second){
				//ti += a[w.top()].second;
				at += a[w.top()].first- (curp[c]+at);
				w.pop();
				continue;
			}
			at += a[w.top()].second;
		}
		ti += a[w.top()].first-(curp[c]+at)-1;
		at += a[w.top()].first-(curp[c]+at)-1;
		//ct += a[w.top()].first-(curp[c]+at);
		ti += a[w.top()].second;
		ct += a[w.top()].second;

		w.pop();
		c--;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n;i++){
		int temp[2];
		cin >> temp[0];
		cin >> temp[1];
		a.push_back(make_pair(temp[0]-1, temp[1]));
		curp[i] = i-n;

	}
	for (int i = n-1; i >= 0;i--){
		int temp = at;
		if (curp[i]+temp < a[i].first){
			if (s){
				cal(i-1, a[i].first);
			}
			w.push(i);
			at += a[i].first-(curp[i]+temp);
			ti += a[i].first-(curp[i]+temp);
			s = true;
			//stuff
			continue;
		}
		if (curp[i]+temp > a[i].first){
			w.push(i);
			at -= (curp[i]+temp)-a[i].first;
			ti -= (curp[i]+temp)-a[i].first;
			//ct += (curp[i]+temp)-a[i].first;
			// stuff
		}
		if (curp[i]+temp == a[i].first){
			w.push(i);
			//stuff
			continue;
		}
	}
	return 0;
}
