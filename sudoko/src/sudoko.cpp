//============================================================================
// Name        : sudoko.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int n;
int s[100][9][9];
int r[100][9][9];
int c[100][9][9];
int sq[100][3][3][9];
int com[100][9][9];
bool ch(int w,int x, int y, int v){
	return r[w][x][v] == 0 && c[w][y][v] == 0 && sq[w][x%3][y%3][v] == 0;
}
void re(int w){

}
void slov(int w, int x,int y){
	for (int i = x;i < 9;i++){
		for (int l = y;l < 9;l++){
			if (s[w][i][l] == 0){
				for (int j = 1; j <= 9;j++){
					if (ch(w,i,l,j)){
						s[w][i][l] = -j;
						r[w][i][j]++;
						c[w][l][j]++;
						sq[w][i%3][l%3][j]++;
						if (i == 8 && l == 8){
							re[w];
						} else {
							slov(w,i,l);
						}
					}
				}
			}
		}
	}
}
int main() {
	ifstream fin("in.in");
	ofstream fout("out.out");
	fin >> n;
	fout << "Reading\n";
	for (int i = 0; i < n;i++){
		for (int l = 0; l < 9;l++){
			for (int j = 0; j < 9;j++){
				cin >> s[i][l][j];
				r[i][l][s[i][l][j]]++;
				c[i][j][s[i][l][j]]++;
				sq[i][l%3][j%3][s[i][l][j]]++;
			}
		}
	}
	fout << "Done\n";
	for (int i = 0; i < n;i++){
		fout << "Solving " << i+1 << "/" << n << "\n";
		slov(i,0,0);
	}
	return 0;
}
