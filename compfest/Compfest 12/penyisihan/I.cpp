#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
typedef pair<int, int> ii;

int N, K, L;
map<ii, int> ma;
bool cekEdges(vector<ii> edges) {
	vector<int> adj[N + 10];
	if ((int)edges.size() != N - 1) {
		return false;
	}
	
	for (ii u : edges) {
		adj[u.fi].pb(u.se);
		adj[u.se].pb(u.fi);
	}
	
	queue<int> q;
	q.push(1);
	vector<bool> fl(N + 10, 0);
	
	while (!q.empty()) {
		int ca = q.front();
		q.pop();
		
		if (fl[ca]) {
			continue;
		}
		
		fl[ca] = 1;
		for (int u : adj[ca]) {
			q.push(u);
		}
	}
	
	int yes = 1;
	for (int i = 1; i <= N; i++) {
		if (!fl[i]) {
			yes = 0;
			break;
		}
	}
	
	return yes;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	cin >> K;
	int u, v;
	for (int i = 0; i < K; i++) {
		cin >> u >> v;
		ma[ii(u, v)]++;
	}
	
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> u >> v;
		ma[ii(u, v)]--;
	}
	
	vector<ii> edges;
	for (auto u : ma) {
		if (u.se != 0) {
			int num = abs(u.se);
			for (int i = 0; i < num; i++) {
				edges.pb(u.fi);
			}
		}
	}
	
	cout << (cekEdges(edges)? "Pohon\n" : "Bukan pohon\n");
	
	return 0;
}
