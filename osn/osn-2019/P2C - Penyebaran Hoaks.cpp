#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int par[200100], ran[200100], sz[200100];

int N, S, Q;
vector<iii> V;
int getPar(int now) {
	if (par[now] == now) {
		return now;
	}
	par[now] = getPar(par[now]);
	return par[now];
}
void Union(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if (a == b) return;
	if (ran[a] < ran[b]) {
		par[a] = b;
		sz[b] += sz[a];
	} else {
		if (ran[a] == ran[b]) {
			ran[a]++;
		}
		par[b] = a;
		sz[a] += sz[b];
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 200100; i++) {
		par[i] = i;
		sz[i] = 1;
	}

	cin >> N >> S >> Q;
	int T;
	for (int i = 1; i <= N; i++) {
		cin >> T;
		int a, b;
		for (int j = 0; j < T; j++) {
			cin >> a >> b;
			V.pb(iii(ii(a, b), i));
		}
	}

	sort(V.begin(), V.end());
	int maxi = -1;
	int bf = -1;
	for (iii u : V) {
		// cout << u.fi.fi << " " << u.fi.se << " " << u.se << endl;
		if (u.fi.fi <= maxi) {
			Union(bf, u.se);
		}
		bf = u.se;
		maxi = max(maxi, u.fi.se);
	}

	// cout << "===========par\n";
	for (int i = 1; i<= N; i++) {
		// cout << i << " : " << getPar(i) << endl;
	}

	int a;
	while (Q--) {
		cin >> a;
		cout << sz[getPar(a)] << endl;
	}

	return 0;
}