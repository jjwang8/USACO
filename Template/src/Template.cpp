#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
int n,tot = 0, st = 0;
int mov[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<int> a;
int binsea(int tar){
	int lef = 0;
	int rit = .size();
	while (lef <= rit) {
		int mid = lef + (rit - lef) / 2;
	        if ([mid] == tar)
	            return mid;
	        if ([m] < tar)
	            lef = mid + 1;
	        else
	            rit = mid - 1;
	    }
	    return -1;
}
int ranlk[][] = {};
void ranqryint(){
	for (int i = 0; i < n;i++){
		ranlk[i][0] = i;
	}
	for (int l = 1; (1<<l) <= n;l++){
		for (int i = 0; (i+(1<<l)-1) < n;i++){
			if (a[ranlk[i][l-1]] < a[ranlk[i+(1<<(l-1))][l-1]]){
				ranlk[i][l] = ranlk[i][l-1];
			} else {
				ranlk[i][l] = ranlk[i+(1<<(l-1))][l-1];
			}
		}
	}
}
int ranqry(int lef, int rit){
	int si = (int)log2(rit-lef+1);
	if (a[ranlk[lef][si]] <= a[ranlk[rit-(1<<si)+1][si]]){
		return a[ranlk[lef][si]];
	} else {
		return a[ranlk[rit-(1<<si)+1][si]];
	}
}
bool val(int x, int y){
	return !((x < 0 || y > n) || (x > n || y < 0));
}
void sp(int st, int en){

}

int main() {
	cin >> n;

	return 0;
}
