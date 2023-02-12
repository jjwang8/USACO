#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
#include <algorithm>
using namespace std;
vector<pair<int, int> > a;
int n, gmi, tot = 0;
bool v[10005] = {};
void sp(int st, int en){

}
int main() {
	cin >> n;
	for (int i = 0; i < n;i++){
		pair<int, int> temp;
		cin >> temp.first;
		temp.second = i;
		a.push_back(temp);
	}
	sort(a.begin(),a.end());
	gmi = a[0].first;
	for (int i = 0; i < n;i++){
		if (v[i]){
			continue;
		}
		int lmi = (1<<30), c = 0, cur = i;
		while(v[cur] == 0){
			tot += a[cur].first;
			v[cur] = 1;
			lmi = min(lmi, a[cur].first);
			cur = a[cur].second;
			c++;
		}
		if (c == 1){
			tot -= a[cur].first;
			continue;
		}
		tot += min((c-2)*lmi, c*gmi+lmi+gmi);
	}
	cout << tot << endl;
	return 0;
}
