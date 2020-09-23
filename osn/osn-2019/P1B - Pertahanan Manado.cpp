#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;

struct Paket {
	LL a, b, p;
	bool operator < (Paket other) {
		if (b == other.b) {
			if (a == other.a) {
				return p < other.p;
			}
			return a < other.a;
		}
		return b < other.b;
	}
};
LL N, M, S;
Paket tab[200100];
LL memo[200100];
vector<ii> batas; // index, value
LL getMin(LL le) {
	ii ans = *lower_bound(batas.begin(), batas.end(), ii(le, 0));

	// cout << "Cetak u\n";
	// for (ii u : batas) {
	// 	cout << u.fi << " " << u.se << endl;
	// }
	// cout << "le " << le << " " << ans.fi << " " << ans.se << endl;

	return ans.se;
}
void update(LL idx, LL val) {
	while (!batas.empty() && batas.back().se >= val) {
		batas.pop_back();
	}
	batas.pb(ii(idx, val));
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> S;
	for (LL i = 0; i < M; i++) {
		cin >> tab[i].a >> tab[i].b >> tab[i].p;
	}
	sort(tab, tab + M);

	// for (LL i = 0; i < M; i++) {
	// 	cout << tab[i].a << " " << tab[i].b << " " << tab[i].p << endl;
	// }

	LL j = 0;
	memo[0] = 0;
	batas.pb(ii(0, 0));
	for (LL i = 1; i <= N; i++) {
		memo[i] = memo[i - 1] + S;
		while (j < M && tab[j].b < i) j++;
		for (; j < M && tab[j].b == i; j++) {
			LL mini = getMin(tab[j].a - 1);
			// cout << mini << endl;
			memo[i] = min(memo[i], mini + tab[j].p);
		}
		update(i, memo[i]);
	}

	cout << memo[N] << endl;
	return 0;
}