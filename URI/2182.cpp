#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int V, A, comp, best;
vector<vii> grf;
vi vis;
double dfs(int u, int ult, double &dist) {
	best = max(best, u);
	vis[u] = 0;
	int v, w;
	for(int i = 0 ; i < grf[u].size(); i++) {
		v = grf[u][i].first; 
		w = grf[u][i].second; 
		if(vis[v] == -1) {
			dfs(v, u, dist+=w);
			comp++;
		}
		else if(vis[v] == 0 && v != ult) {comp++;dist+=w;}
	}
	vis[u] = 1;
	return dist;
}

int dfs_call()
{
	double aux, mini = INF, d;
	int ans = 0;
	vis.assign(V, -1);
	for(int i=1; i<V; i++) {
		if(vis[i] == -1) {
			comp = best = d = 0;
			
			aux = dfs(i, 0, d);
			if(comp != 0.0) aux/=comp;
			if(aux == mini) {
				ans = max(ans, best); 
			}
			else if(aux < mini) {mini = aux;ans = best;}
		}
	}
	return ans;
}

int main()
{
	int o, d, w;

	scanf("%d %d", &V, &A);
	V++;
	grf.resize(V);
	
	for(int i=0; i<A; i++) {
		scanf("%d %d %d", &o, &d, &w);
		grf[o].push_back(ii(d, w));
		grf[d].push_back(ii(o, w));
	}
	printf("%d\n", dfs_call());
}