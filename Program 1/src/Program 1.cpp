//============================================================================
// Name        : Program.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int n, flips[4];
int ans = (1<<30);
bool m[10][110];
void t(int x,int y, int type){
	for (int i = 0; i < type;i++){
		for (int l = 0; l < type;l++){
			m[x+i][y+l] = !m[x+i][y+l];
		}
	}
}
bool check(int x, int y,int type){
	if (type == 1){
		return 1;
	}
	if (4-x >= type && n-y >= type){
		return 1;
	} else {
		return 0;
	}
}
void f(int x, int y,int cost){
	//cout << x << " " << y << endl;
	bool first = true;
	bool found = false;
	int start = 0;
	for (int i = x; i < 4;i++){
		if (found){
			break;
		}
		if (first){
			start = y;
			start = false;
		} else {
			start = 0;
		}
		for (int l = start;l < n;l++){
			if (m[i][l] == 1){
				for (int j =1; j <= 4;j++){
					if (check(i,l,j)){
						t(i,l,j);
						f(i,l,cost+flips[j-1]);
						t(i,l,j);
					}
				}
				found = true;
				break;
			}
			else if(i == 3 && l == n-1){
				//cout << ans << endl;
				ans = min(ans,cost);
			}
		}
	}

}
int main() {
	cin >> n;
	for (int i = 0; i < 4;i++){
		cin >> flips[i];
	}
	for (int i = 0; i < 4;i++){
		for (int l = 0; l< n;l++){
			cin >> m[i][l];
		}
	}
	f(0,0,0);
	cout << ans;
	return 0;
}
