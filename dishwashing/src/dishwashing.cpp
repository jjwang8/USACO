//============================================================================
// Name        : dishwashing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n;
vector<stack<int> > a;
int main() {
	cin >> n;
	for (int i = 0; i < n;i++){
		int temp;
		cin >> temp;
		if (a.size() == 0){
			stack<int> t;
			t.push(temp);
			a.push_back(t);
		} else {
			bool d = 0;
			for (int i = 0;i < a.size();i++){
				if (a[i].top() > temp){
					if (i == 0){
						a[i].push(temp);
						d =1;
						break;
					}

					a[i].push(temp);
					d = 1;
					break;
				}
			}
			if (d == 0){
				stack<int> t;
				t.push(temp);
				a.push_back(t);
			}
		}
	}
	return 0;
}
