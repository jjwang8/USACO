//============================================================================
// Name        : Modern.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
int n,a[26][20],ins[26],tot = 0,asd = 0;
char let[7] = {'B','E','S','I','G','O','M'};
bool even(int num){
	return num%2;
}
bool equ(int var[]){
	return ((var[0]+var[1]+var[2]+var[2]+var[3]+var[1])%2 == 0)+((var[4]+var[5]+var[1]+var[2])%2 == 0)+((var[6]+var[5]+var[5])%2 == 0) == 0;
}
void pos(int loc,int num[],int wh){
	for (int i = loc;i < 7;i++){
		for (int l = 0;l < ins[let[i]-'A'];l++){
			int temp[wh+1];
			for (int j = 0; j < wh+1;j++){
				if (j == wh){
					temp[j] = a[let[i]-'A'][l];
				} else {
					temp[j] = num[j];
				}
			}
			if (wh == 6 && equ(temp) == 0){
				tot++;
			} else {
				pos(i+1,temp,wh+1);
			}
		}
	}
}
int main() {
	ifstream fin("geteven.in");
	ofstream fout("geteven.out");
	fin >> n;
	for (int i = 0;i < 26;i++){
		ins[i] = 0;
	}
	for (int i = 0;i < n;i++){
		char temp;
		fin >> temp;
		fin >> a[temp-'A'][ins[temp-'A']];
		ins[temp-'A']++;
	}
	int temp[1];
	pos(0,temp,0);
	fout << tot;
	return 0;
}
