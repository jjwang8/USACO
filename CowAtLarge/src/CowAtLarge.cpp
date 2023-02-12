#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 100000

vector<int> edges[MAXN];
int distLeaf[MAXN];
int distStart[MAXN];
int ans;

void dfsDistances(int i,int par)
{
	distLeaf[i] = MAXN + 1;
	if(par != -1)
		distStart[i] = 1 + distStart[par];
	else
		distStart[i] = 0;
	bool isLeaf = 1;
	for(int j=0;j<edges[i].size();j++)
		if(par != edges[i][j])
		{
			dfsDistances(edges[i][j],i);
			distLeaf[i] = min(distLeaf[i], 1 + distLeaf[edges[i][j]]);
			isLeaf = 0;
		}
	if(isLeaf)
		distLeaf[i] = 0;
}

void dfsDistances2(int i,int par)
{
	if(par!=-1)
		distLeaf[i] = min(distLeaf[i],distLeaf[par]+1);
	for(int j=0;j<edges[i].size();j++)
		if(par!=edges[i][j])
			dfsDistances2(edges[i][j],i);
}

void dfs(int i,int par)
{
	if((par!=-1)&&(distLeaf[i]<=distStart[i])&&(distLeaf[par]>distStart[par]))
		ans++;
	for(int j=0;j<edges[i].size();j++)
		if(edges[i][j]!=par)
			dfs(edges[i][j],i);
}

int main()
{
	int K;
	int N,a,b;
	cin >> N >> K;
	K--;
	for(int i=1;i<N;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for(int i=K;i<K+1;i++)
	{
		if(edges[i].size()==1)
		{
			cout << 1 << '\n';
			continue;
		}
		ans = 0;
		dfsDistances(i,-1);
		dfsDistances2(i,-1);
		dfs(i,-1);

		cout << ans << '\n';
	}
}
