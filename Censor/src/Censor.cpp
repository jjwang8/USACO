//============================================================================
// Name        : Censor.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;
string s,w[100000];
string c;
int n;
stack<vector<int> > a;
bool che(int loc){
	vector<int> temp;
	temp.push_back(a.top()[0]+1);
	for (int i = 0;i < a.top().size()-1;i++){
		if (s[loc] == w[a.top()[i+1]][a.top()[0]+1]){
			temp.push_back(a.top()[i+1]);
		}
	}
	if (temp.size() > 1){
		a.pop();
		a.push(temp);
		return false;
	}
	return true;
}
void de(int st, int en){
	int con = 0;
	while(con != en){
		if (c[st-con] == 0){
			con++;
			en++;
		} else{
			c[st-con] = 0;
			con++;
		}
	}
}
int main() {
	ifstream fin("censor.in");
	ofstream fout("censor.out");
	fin >> s;
	fin >> n;
	c =s;
	for (int i = 0; i < n;i++){
		fin >> w[i];
	}
	for (int i = 0;i< s.size();i++){
		if (a.size() == 0){
			vector<int> temp;
			temp.push_back(0);
			for (int l = 0;l < n;l++){
				if (s[i] == w[l][0]){
					temp.push_back(l);
				}
			}
			if (temp.size() > 1){
				a.push(temp);
			}
		} else {
			if (che(i)){
				vector<int> temp;
				temp.push_back(0);
				for (int l = 0;l < n;l++){
					if (s[i] == w[l][0]){
						temp.push_back(l);
					}
				}
				if (temp.size() > 1){
					a.push(temp);
				} else {
					stack<vector<int> > fff;
					a = fff;
				}
			}else{
				if (a.top()[0]+1 == w[a.top()[1]].size()){
					de(i,w[a.top()[1]].size());
					a.pop();
				}
			}
		}

	}
	for (int i =0;i < c.size();i++){
		if (c[i] != 0){
			cout << c[i];
		}
	}
	//fout << endl;
	//fout << c << endl;
	return 0;
}
