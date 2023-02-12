//============================================================================
// Name        : MockG1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int nn,mn,x,y;
int n[20],m[20];
int knap[100003];
int within(int value){
	if (value > y){
		return 100002;
	} else if (value < 1){
		return 10002;
	}else {
		return value;
	}
}
int main() {
	cin >> nn;
	cin >> mn;
	cin >> x;
	cin >> y;
	for (int i = 0; i < nn;i++){
		cin >> n[i];
	}
	for (int i = 0;i <  mn;i++){
		cin >> m[i];
	}
	knap[0] = 1;
	for (int i = 0; i < y;i++){
		if (knap[i] > 0){
			//cout << knap[i]+1 << endl;
			for (int l = 0; l < nn;l++){
				if (knap[within(i+n[l])] > knap[i]+1 || knap[within(i+n[l])] == 0){
					knap[within(i+n[l])] = knap[i]+1;
				}
			}
		}
	}
	for (int i = 0; i < y;i++){
			if (knap[i] > 0){
				//cout << knap[i]+1 << endl;
				for (int l = 0; l < nn;l++){
					if (knap[within(i+n[l])] > knap[i]+1 || knap[within(i+n[l])] == 0){
						knap[within(i+n[l])] = knap[i]+1;
					}
				}
			}
		}
	//for (int i = 0; i < y;i++){
	//		cout << knap[i] << endl;
	//	}
	for (int i = y-1; i >= 1;i--){
		if (knap[i] > 0){
			for (int l = 0; l < mn;l++){
				if (knap[within(i-m[l])] > knap[i]+1 || knap[within(i-m[l])] == 0){
					knap[within(i-m[l])] = knap[i]+1;
				}
			}
		}
	}
	for (int i = 0; i < y;i++){
			if (knap[i] > 0){
				//cout << knap[i]+1 << endl;
				for (int l = 0; l < nn;l++){
					if (knap[within(i+n[l])] > knap[i]+1 || knap[within(i+n[l])] == 0){
						knap[within(i+n[l])] = knap[i]+1;
					}
				}
			}
		}
	for (int i = y-1; i >= 1;i--){
		if (knap[i] > 0){
			for (int l = 0; l < mn;l++){
				if (knap[within(i-m[l])] > knap[i]+1 || knap[within(i-m[l])] == 0){
					knap[within(i-m[l])] = knap[i]+1;
				}
			}
		}
	}for (int i = y-1; i >= 1;i--){
		if (knap[i] > 0){
			for (int l = 0; l < mn;l++){
				if (knap[within(i-m[l])] > knap[i]+1 || knap[within(i-m[l])] == 0){
					knap[within(i-m[l])] = knap[i]+1;
				}
			}
		}
	}
	for (int i = 0; i < y;i++){
		cout << knap[i] << " "<< endl;
	}
	cout << knap[x]-1 << endl;
	return 0;
}
