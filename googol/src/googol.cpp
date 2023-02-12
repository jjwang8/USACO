//============================================================================
// Name        : googol.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include <math.h>
#include <string>
#include <algorithm>
using namespace std;
string ad(string x, string y){
	x.begin(), x.end();
	y.begin(), y.end();
	string res = "";
	int car = 0;
	for (int i =max(x.size(), y.size())-1;i >= 0; i--){
		if (i > min(x.size(),y.size())){
			if (x.size() > y.size()){
				res += x[i];
			} else {
				res += y[i];
			}
		} else {
			res += (x[i]-'0'+y[i]-'0')%10 + car+'0';
			car = ((x[i]-'0'+y[i]-'0')%10 + car)/10+'0';
		}
	}
	reverse(res.begin(), res.end());
	//cout << res << endl;
	return res;
}
string fin(string x, bool lef){
	string ans[2];
	cout << x << endl;
	cin >> ans[0];
	cin >> ans[1];
	cout << x << " " << lef << endl;
	if (ans[0] == "0" && ans[1] == "0"){
		return "1";
	}
	if (ans[0]  == "0"|| ans[1] == "0"){
		return "2";
	}
	if (lef == 0){
		return ad(fin(ans[1], 0), "1");
	}
	return ad(ad(fin(ans[1],1), fin(ans[0], 0)),"1");
}
int main() {
	cout << fin("1", 1) << endl;
	return 0;
}
