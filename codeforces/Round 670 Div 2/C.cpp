#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
struct AnsCtr {
	int ctr1, ctr2, isDouble;
};

int T, N;
vector<ii> edges;
vector<int> adj[100100];
vector<int> sz, par;
void clear() {
	edges.clear();
	for (int i = 0; i < N + 10; i++) {
		adj[i].clear();
	}

	sz = vector<int>(N + 10, -1);
	par = vector<int>(N + 10, -1);
}
void dfs(int now, int p) {
	sz[now] = 1;
	par[now] = p;
	for (int u : adj[now]) {
		if (u == p) continue;
		dfs(u, now);
		sz[now] += sz[u];
	}
}
AnsCtr getCtr() {
	dfs(1, -1);
	bool isDouble = false;
	int ctr1 = -1, ctr2 = -1;
	for (int i = 1; i <= N; i++) {
		if (sz[i] * 2 == N) {
			isDouble = true;
			ctr1 = i;
			ctr2 = par[i];
		}
	}

	return {ctr1, ctr2, isDouble};
}

void main1() {
	cin >> N;

	clear();

	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		edges.pb(ii(u, v));
		adj[u].pb(v);
		adj[v].pb(u);
	}

	AnsCtr ans = getCtr();
	int ctr1 = ans.ctr1;
	int ctr2 = ans.ctr2;
	if (!ans.isDouble) {
		cout << edges[0].fi << ' ' << edges[0].se << endl;
		cout << edges[0].fi << ' ' << edges[0].se << endl;
		return;
	}

	int child = -1;
	for (int u : adj[ctr1]) {
		if (u != ctr2) {
			child = u;
			break;
		}
	}

	cout << ctr1 << ' ' << child << endl;
	cout << ctr2 << ' ' << child << endl;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		main1();
	}

	return 0;
}