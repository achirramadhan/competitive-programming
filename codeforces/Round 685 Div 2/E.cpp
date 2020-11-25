#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;

LL N;
LL ask_xor(LL i, LL j) {
	cout << "XOR " << i + 1 << ' ' << j + 1 << endl;
	LL u;
	cin >> u;
	return u;
}
LL ask_and(LL i, LL j) {
	cout << "AND " << i + 1 << ' ' << j + 1 << endl;
	LL u;
	cin >> u;
	return u;
}
void main1() {
	cin >> N;

	vector<LL> X(N, 0);
	vector<vector<LL> > occ(N, vector<LL> ());

	X[0] = 0;
	occ[0].pb(0);
	for (LL i = 1; i < N; i++) {
		X[i] = ask_xor(0, i);
		occ[X[i]].pb(i);
	}

	for (LL i = 0; i < N; i++) {
		if (occ[i].size() > 1) {
			vector<LL> ans(N, 0);
			LL u = occ[i][0];
			LL v = occ[i][1];

			ans[u] = ans[v] = ask_and(u, v);
			ans[0] = ans[u] ^ X[u];

			for (LL i = 1; i < N; i++) {
				ans[i] = ans[0] ^ X[i];
			}

			cout << "!";
			for (LL i = 0; i < N; i++) {
				cout << ' ' << ans[i];
			}
			cout << endl;
			return;
		}
	}

	LL id1 = 0, id2 = 0;
	for (LL i = 1; i < N; i++) {
		if (X[i] == 1) {
			id1 = i;
		}
		if (X[i] == 2) {
			id2 = i;
		}
	}

	LL and0id1 = ask_and(0, id1);
	LL and0id2 = ask_and(0, id2);

	vector<LL> ans(N, 0);
	ans[0] = ((and0id1) >> 2) << 2;
	ans[0] += (and0id1 & 2);
	ans[0] += (and0id2 & 1);

	for (LL i = 1; i < N; i++) {
		ans[i] = ans[0] ^ X[i];
	}

	cout << "!";
	for (LL i = 0; i < N; i++) {
		cout << ' ' << ans[i];
	}
	cout << endl;
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