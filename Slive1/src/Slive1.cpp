//============================================================================
// Name        : Slive1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;
int n, tot = 0;
typedef pair<int, int> p;
vector<p> a;

int main() {
	ifstream fin("lifeguards.in");
	ofstream fout("lifeguards.out");
	fin >> n;
	for (int i = 0; i < n; i++) {
		p temp;
		fin >> temp.first;
		fin >> temp.second;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	int b = a[0].second;
	int f = a[0].first;
	for (int i = 0; i < n; i++) {
		if (a[i].first > b) {
			tot += b-f;
			b = a[i].second;
			f = a[i].first;
		} else if (a[i].second > b) {
			b = a[i].second;
		}

	}
	tot += b-f;
	cout << tot << endl;
	int ma = a[0].second - a[0].first;
	for (int i = 0; i < n - 1; i++) {
		if (a[i].second > a[i + 1].first && a[i + 1].second < a[i].second) {
			ma = 0;
			break;
		} else if (i != 0 && a[i].first < a[i - 1].second) {
			if (a[i + 1].first < a[i].second) {
				if (ma > a[i + 1].first - a[i - 1].second) {
					ma = a[i + 1].first - a[i - 1].second;
				}
			} else {
				if (ma > a[i].second - a[i - 1].second) {
					ma = a[i].second - a[i - 1].second;
				}
			}
		} else if (a[i + 1].first < a[i].second) {
			if (ma > a[i + 1].first - a[i].first) {
				ma = a[i + 1].first - a[i].first;
			}
		}
	}
	fout << tot-ma;
	return 0;
}
