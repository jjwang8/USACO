#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
long long n;
bool has[200005] = {};
bool has2[200005] = {};
long long a[200005];
vector<queue<long long> > b(200005);
unsigned long long tot = 0;
struct Query
{
    long long l, r, idx;
};

// cmp function to sort queries according to r
bool cmp(Query x, Query y)
{
    return x.r < y.r;
}

// updating the bit array
void update(long long idx, long long val, long long bit[], long long n)
{
    for (; idx <= n; idx += idx&-idx)
        bit[idx] += val;
}

// querying the bit array
long long query(long long idx, long long bit[], long long n)
{
    long long sum = 0;
    for (; idx>0; idx-=idx&-idx)
        sum += bit[idx];
    return sum;
}

void answeringQueries(long long arr[], long long n, Query queries[], long long q)
{
    // initialising bit array
    long long bit[n+1];
    memset(bit, 0, sizeof(bit));

    // holds the rightmost index of any number
    // as numbers of a[i] are less than or equal to 10^6
    long long last_visit[1000005];
    memset(last_visit, -1, sizeof(last_visit));

    // answer for each query
    long long ans[q];
    long long query_counter = 0;
    for (long long i=0; i<n; i++)
    {
        // If last visit is not -1 update -1 at the
        // idx equal to last_visit[arr[i]]
        if (last_visit[arr[i]] !=-1)
            update (last_visit[arr[i]] + 1, -1, bit, n);

        // Setting last_visit[arr[i]] as i and updating
        // the bit array accordingly
        last_visit[arr[i]] = i;
        update(i + 1, 1, bit, n);

        // If i is equal to r of any query  store answer
        // for that query in ans[]
        while (query_counter < q && queries[query_counter].r == i)
        {
            ans[queries[query_counter].idx] =
                     query(queries[query_counter].r + 1, bit, n)-
                     query(queries[query_counter].l, bit, n);
            query_counter++;
        }
    }

    // print answer for each query
    for (long long i=0; i<q; i++)
        tot += ans[i]-1;
}
int main() {
	cin >> n;
	for (long long i = 0; i < n;i++){
		long long temp;
		cin >> temp;
		a[i] = temp;
		b[temp].push(i);
	}
	Query queries[200005];
	long long si = 0;
	for (long long i = 0; i < n;i++){
		b[a[i]].pop();
		if (b[a[i]].size() == 0){
			queries[i].l = i;
			queries[i].r = n-1;
			queries[i].idx = i;
		} else {
			queries[i].l = i;
			queries[i].r = b[a[i]].front();
			queries[i].idx = i;
		}
	}
	sort(queries, queries+n, cmp);
	answeringQueries(a, n, queries, n);
	cout << tot << endl;
	return 0;
}
