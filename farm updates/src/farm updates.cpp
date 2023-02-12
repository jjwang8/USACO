//============================================================================
// Name        : farm.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
int n,q;
struct node{
	int num;
	int par = 0;
	vector<int> child;
	bool state = true;
	bool ref = true;
	int time;
	bool cref = false;
};
vector<node> cow(100005);
int main() {
	cin >> n;
	cin >> q;
	for (int i = 0;i < q;i++){
		vector<int> temp;
		char temp2;
		cin >> temp2;
		temp.push_back(temp2-'A');
		if (temp2 == 'A'){
			cin >> temp2;
			temp.push_back(temp2-'0');
			cin >> temp2;
			temp.push_back(temp2-'0');
		} else {
			cin >> temp2;
			temp.push_back(temp2-'0');
		}
		if (temp[0] == 'D'-'A'){
			cow[temp[1]].state = false;
			if (cow[cow[temp[1]].par].ref == true){

			} else if (cow[temp[1]].cref == true){

			} else {
				cow[temp[1]].time = i;
				cow[temp[1]].ref = false;
			}
			bool hasparent = cow[temp[1]].par > 0;
			int npar = cow[temp[1]].par;
			while (hasparent){
				bool sact = false;
				if (cow[npar].child.size() > 0){
					for (int l = 0; l < cow[npar].child.size();l++){
						if (cow[cow[npar].child[l]].ref == true){
							sact = true;
							break;
						}
					}
				} else if (cow[npar].state == true){
					cow[npar].cref = false;
					sact = true;
				} else {
					cow[npar].cref = false;
				}
				if (sact == true){
					hasparent = false;
				} else {
					if (cow[npar].ref == true){
						cow[npar].ref = false;
						cow[npar].state = false;
						cow[npar].time = i;
					}
					hasparent = cow[npar].par > 0;
				}
				npar = cow[npar].par;
			}
		} else if (temp[0] == 0){
			if (cow[temp[1]].par == 0){
				cow[temp[1]].par = temp[2];
				if (cow[temp[1]].ref == 1){
					bool hasparent = 1;
					int npar = temp[2];
					while (hasparent){
						if (cow[npar].ref == false){
							cow[npar].ref = true;
							hasparent = cow[npar].par > 0;
						}
						if (cow[npar].cref == false){
							cow[npar].cref = true;
						}
						if (cow[npar].ref == 1){
							hasparent = false;
						}
						npar = cow[npar].par;
					}
				}
			} else if (cow[temp[2]].par == 0){
				cow[temp[2]].par = temp[1];
				if (cow[temp[2]].ref == 1){
					bool hasparent = 1;
					int npar = temp[1];
					while (hasparent){
						if (cow[npar].ref == false){
							cow[npar].ref = true;
							hasparent = cow[npar].par > 0;
						}
						if (cow[npar].cref == false){
							cow[npar].cref = true;
						}
						if (cow[npar].ref == 1){
							hasparent = false;
						}
						npar = cow[npar].par;
					}
				}
			} else {

			}
		}
	}
	return 0;
}
