#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
int s[10000001];
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	s[0] = 0;
	for (int i = 1; i < K; i++)
		s[i] = (M * ((long long) s[i - 1]) + M) % MOD;
	for (int i = K; i <= N; i++)
		s[i] = (M * ((long long) s[i - 1]) + MOD
				- ((M - 1) * ((long long) s[i - K])) % MOD) % MOD;
	int ans = 1;
	for (int i = 1; i <= N; i++)
		ans = (M * ((long long) ans)) % MOD;
	cout << (((long long) ans) + MOD - ((long long) s[N]) + s[N - 1]) % MOD
			<< '\n';
}
