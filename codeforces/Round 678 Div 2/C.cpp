#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef long long LL;

LL N, X, POS;
const LL MODD = (LL)1e9 + 7;
void main1() {
	cin >> N >> X >> POS;

	vector<LL> ch, fl;
	LL l = 0, r = N;
	while (l < r) {
		LL m = (l + r) / 2;
		ch.pb(m);
		if (m <= POS) {
			l = m + 1;
			fl.pb(-1);
		} else {
			r = m;
			fl.pb(1);
		}
	}

	LL check = ch.size();

	l = X - 1;
	LL g = N - X;
	vector<LL> occ(N + 10, 0);
	occ[POS] = 1;

	for (LL i = 0; i < check; i++) {
		if (fl[i] == -1) {
			if (occ[ch[i]] == 0) {
				occ[ch[i]] = l;
				l--;
			}
		} else {
			occ[ch[i]] = g;
			g--;
		}
	}

	LL sisa = l + g;
	for (LL i = 0; i < N; i++) {
		if (occ[i] == 0) {
			occ[i] = sisa;
			sisa--;
		}
	}

	LL ans = 1;
	for (LL i = 0; i < N; i++) {
		ans *= occ[i];
		ans %= MODD;
	}
	cout << ans << endl;
}
LL T;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// cin >> T;
	T = 1;
	while (T--) {
		main1();
	}

	return 0;
}