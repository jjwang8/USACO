#include <cstdio>
#include <queue>
#include <vector>
#include <cassert>
using namespace std;
#define NMAX 100000
#define MMAX 50000
vector<pair<int, int>> edges[MMAX];
vector<int> succ[NMAX];
int pred[NMAX];
int result[NMAX];
bool doable(int n, int k) {
	for (int i = 0; i < n; i++) {
		succ[i].clear();
		pred[i] = 0;
	}
	for (int i = 0; i < k; i++) {
		for (auto p : edges[i]) {
			succ[p.first].push_back(p.second);
			pred[p.second]++;
		}
	}
	priority_queue<int> q;
	for (int i = 0; i < n; i++) {
		if (pred[i] == 0) {
			q.push(-i);
		}
	}

	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			return false;
		}
		int v = -q.top();
		q.pop();

		result[i] = v;
		for (int next : succ[v]) {
			pred[next]--;
			if (pred[next] == 0) {
				q.push(-next);
			}
		}
	}

	return true;
}

int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	assert(1 <= m && m <= MMAX);
	assert(1 <= n && n <= NMAX);
	for (int i = 0; i < m; i++) {
		int d;
		scanf("%d", &d);
		int last;
		for (int j = 0; j < d; j++) {
			int e;
			scanf("%d", &e);
			e--;
			if (j > 0) {
				edges[i].push_back(make_pair(last, e));
			}
			last = e;
		}
	}
	int lo = 0;
	int hi = m + 1;
	while (hi > lo + 1) {
		int mid = (lo + hi) / 2;
		if (doable(n, mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	int ans = lo;
	doable(n, ans);
	for (int i = 0; i < n; i++) {
		printf("%d%c", result[i] + 1, i == n - 1 ? '\n' : ' ');
	}
}
