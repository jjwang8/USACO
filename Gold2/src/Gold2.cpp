//============================================================================
// Name        : Gold2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
vector<vector<int> > a;
int n;
int tot;

bool com(int x,int y){
	for (int i = 0; i < 5;i++){
		for(int l= 0;l < 5;l++){
			if (a[x][i] == a[y][l]){
				return true;
			} else if (a[x][i] < a[y][l]) {
				break;
			}
		}
	}
	return false;
}
bool cmp(const vector<int> &j,const vector<int> &k)
{
	//cout << j[0] << " " << k[0] << endl;
	return j[0]<k[0];
}
int main() {
	ifstream fin("cowpatibility.in");
	ofstream fout("cowpatibility.out");
	fin >> n;
	for (int i = 0;i < n;i++){
		vector<int> temp2;
		for (int l = 0; l < 5;l++){
			int temp;
			fin >> temp;
			temp2.push_back(temp);
		}
		sort(temp2.begin(),temp2.end());
		a.push_back(temp2);
	}
	sort(a.begin(), a.end(), cmp);
	//cout << "aaa" << endl;
	for (int i = 0; i < n;i++){
		for (int l = i+1; l < n;l++){
			//cout << "aaa" << endl;
			if (a[l][0] > a[i][4]){
				tot += n-l;
				break;
			}
			//cout << i << " " << l << endl;
			if (com(i,l) == false){
				tot++;
			}

		}
	}
	fout << tot << endl;
	return 0;
}
