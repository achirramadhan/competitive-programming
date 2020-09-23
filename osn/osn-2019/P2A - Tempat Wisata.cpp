#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int N, M;
int BIT[400100];
iii T[200100]; // a, b, idx
int ans[200100];
void update(int idx, int val) {
	for (int i = idx; i < 400100; i += (i & (-i))) {
		BIT[i] += val;
	}
}
int query(int idx) {
	int ans = 0;
	for (int i = idx; i > 0; i -= i & (-i)) {
		ans += BIT[i];
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	vector<int> bil;
	for (int i = 0; i < N; i++) {
		cin >> T[i].fi.fi >> T[i].fi.se;
		bil.pb(T[i].fi.fi);
		bil.pb(T[i].fi.se);
		T[i].se = i;
	}

	sort(bil.begin(), bil.end());
	bil.erase(unique(bil.begin(), bil.end()), bil.end());
	// for (int u : bil) {
	// 	cout << u << " ";
	// }
	// cout << endl;

	for (int i = 0; i < N; i++) {
		T[i].fi.fi = (lower_bound(bil.begin(), bil.end(), T[i].fi.fi) - bil.begin()) + 1;
		T[i].fi.se = (lower_bound(bil.begin(), bil.end(), T[i].fi.se) - bil.begin()) + 1;

		// cout << T[i].fi.fi << " " << T[i].fi.se << endl;
	}

	sort(T, T + N, [&](iii a, iii b) { return (a.fi.se != b.fi.se? a.fi.se < b.fi.se : a.fi.fi < b.fi.fi);});

	// for (int i = 0; i < N; i++) {
	// 	cout << T[i].fi.fi << " " << T[i].fi.se << endl;
	// }

	memset(BIT, 0, sizeof BIT);
	for (int i = 0; i < N; i++) {
		ans[T[i].se] += i - query(T[i].fi.fi - 1);
		update(T[i].fi.se, 1);
	}

	memset(BIT, 0, sizeof BIT);
	for (int i = N - 1; i > -1; i--) {
		ans[T[i].se] += query(T[i].fi.se);
		update(T[i].fi.fi, 1);
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}