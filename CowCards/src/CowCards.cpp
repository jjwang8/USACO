//============================================================================
// Name        : CowCards.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;
int n, a[4][100500];
bool b[100500];
bool fin(int x, bool t){
	if (t){
		for (int i =0;i < n;i++){
			if (a[2][i] > x && a[2][i] != -1){
				//cout << a[2][i] << " " << x << endl;
				a[2][i] = -1;
				return 1;
			}
		}
	} else{
		for (int i =n-1;i >= 0;i--){
			//cout << a[2][i] << " " << x << endl;
			if (a[3][i] < x && a[3][i] != -1){

				a[3][i] = -1;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	cin >> n;
	for (int i = 0; i < n;i++){
		if (i+1 <= n/2){
			cin >> a[0][i];
			b[a[0][i]] = 1;
		} else {
			cin >> a[1][i-n/2];
			b[a[1][i-n/2]] = 1;
		}


	}
	//for (int i =0;i < n;i++){
	//	cout << a[0][i] << endl;
	//}
	int c = 0;
	for (int i =1;i <= 2*n;i++){
		if (!b[i]){
			a[2][c] = i;
			c++;
		}
	}
	sort(a[0], a[0]+n/2);
	sort(a[1], a[1]+n/2);
	sort(a[2], a[2]+n);

	int sc = 0;
	copy(a[2], a[2]+n, a[3]);
	//for (int i =0;i < n;i++){
	//	cout << a[3][i] << endl;
	//}
	for (int i =0;i < n/2;i++){
		if (fin(a[0][i], 1)){
			sc++;
		}
	}
	//cout << sc << endl;
	for (int i = 0;i < n/2;i++){
		if (fin(a[1][i], 0)){
			sc++;
		}
	}
	cout << sc << endl;
	return 0;
}
