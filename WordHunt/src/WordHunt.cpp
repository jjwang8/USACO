//============================================================================
// Name        : WordHunt.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <queue>
#include <set>
using namespace std;
string w[26][60000];
char b[4][4];
int c = 0;
bool br;
string temp;
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
bool tb[4][4];
bool val(int x,int y){
	if (x < 0 || x > 4 || y < 0 || y > 4){
		return false;
	}
	if (tb[x][y]){
		return 0;
	}
	return 1;
}
bool com(string st, string en){
	for (int i = 0; i < min(st.length(),en.length()); i++){
		if (st[i] != en[i]){
			return false;
		}
	}
	return true;
}
int fin(string tw, char st, int sn){
	c = 0;
	while (com(w[st-'a'][sn+c], tw)){
		c++;
	}
	return c;
}
void gen(int x, int y, string tw, int st){
	for (int i = 0; i < 8;i++){
		if (val(x+dir[i][0],y+dir[i][1])){
			temp = tw+b[x+dir[i][0]][y+dir[i][1]];
			fin(temp, temp[0], st);
			gen(x+dir[i][0], y+dir[i][1], tw+b[x+dir[i][0]][y+dir[i][1]], );
		}
	}
}
int main() {
	ifstream fin("words.txt");
	cout << "starting" << endl;
	for (int i = 0;i < 26;i++){
		fin >> temp;
		while (temp[0] == 'a'+i){
			cout << temp << endl;
			if (temp.length() < 3){
				fin >> temp;
				continue;
			}
			if (temp == "z--"){
				br = 1;
				break;
			}
			w[i][c] = temp;
			c++;
			fin >> temp;
		}
		if (br == 1){
			break;
		}
		if (temp[0] != 'a'+i){
			w[i+1][0] = temp;
			c = 1;
		} else {
			c = 0;
		}
	}
	cout << "Complete" << endl;
	//time_t = time(0);
	for (int i = 0;i< 4;i++){
		cin >> temp;
		b[i][0] = temp[0];
		b[i][1] = temp[1];
		b[i][2] = temp[2];
		b[i][3] = temp[3];
	}
	gen(0,0,""+b[0][0],0);
	return 0;
}
