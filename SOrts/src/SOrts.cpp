#include <iostream>
#include <algorithm>
using namespace std;

int N, B[100001];
pair<int,int> A[100001];

// Concise implementation of a binary indexed tree
void modify(int j) { for (; j<=N; j+=(j&-j)) B[j]++; }
int prefix_sum(int j) { int sum = 0; for (; j>0; j-=(j&-j)) sum += B[j]; return sum; }

int main(void)
{
  int answer = 1;
  cin >> N;
  for (int i=1; i<=N; i++) {
    int x;
    cin >> x;
    A[i] = make_pair(x, i);
  }
  sort (A+1, A+N+1);
  for (int i=1; i<=N-1; i++) {
    modify(A[i].second);
    answer = max(answer, i - prefix_sum(i));
  }
  cout << answer << "\n";
  return 0;
}
