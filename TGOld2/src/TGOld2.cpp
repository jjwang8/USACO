#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <list>
using namespace std;
int n,si = 0;
int a[100000] = {0};
int m[100000] = {0};
list<int> en;
list<int>::iterator it;
stack<int> f;
void ins(int v, int s,int e){
	int cur = si-1;
	while(cur != s-1){
		m[cur+1]=m[cur];
		cur--;
	}
	m[e] = v;
}
void rem(int dif){
	for (int i = 1; i < si;i++){
		m[i] = m[i+dif];
	}
}
int main(){
	cin >> n;
	for (int i = 0; i < n;i++){
		cin >> a[i];
	}
	int i;
	int g = 0,la=(1<<30);
	f.push(0);
	for (i = 1; i  <= n;i++){
		for (int l = 0; l < si;l++){
			cout << m[l] << endl;
		}
		//cout << g << " " << la << " " << si << endl;
		cout << endl;
		if (i == 1){
			m[0] = a[i-1],g=a[i-1],la=a[i-1],si=1;
			continue;
		}
		if (a[i-1] < la){
			if (f.top()+1 == a[i-1]){
				f.push(a[i-1]);
				continue;
			}
			if (f.top()+1 > a[i-1]){
				break;
			}
			ins(a[i-1],0,0);
			si++,la=a[i-1];
		}
		if (a[i-1] > g){
			m[si] = a[i-1];
			si++,g=a[i-1];
			en.push_back(si-1);
			continue;
		}
		if (a[i-1] < g && a[i-1] > la){
			bool temp = 0;
			for(it=en.begin();it!=en.end();++it){
				cout << *it << " " << *it-1 << endl;
				if (m[*it] > a[i-1] && m[*it-1] < a[i-1]){
					ins(a[i-1],*it-1,*it);
					si++;
					temp = 1;
					break;
				}
			}
			if (temp == 0){
				int dif = 0;
				for (int l = 0; l < si;l++){
					if (m[l] > a[i-1]){
						m[0] = a[i-1];
						rem(dif-1);
						si = si-dif+1;
						break;
					} else {
						f.push(m[0]);
						dif++;
					}
				}
			}
		}

	}

	cout << si+f.size()-1 << endl;
}
