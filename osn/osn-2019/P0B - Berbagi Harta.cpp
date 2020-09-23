#include <bits/stdc++.h>

#define pb push_back
using namespace std;
typedef long long LL;

LL N, P, Q, H[200100], A[200100], B[200100];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> P >> Q;
	for (LL i = 1; i <= N; i++) {
		cin >> H[i];
	}

	vector<bool> taken(N + 10, 0);
	for (LL i = 0; i < P; i++) {
		cin >> A[i];
		taken[A[i]] = 1;
	}

	vector<bool> isDouble(N + 10, 0);
	vector<LL> numDouble;
	for (LL i = 0; i < Q; i++) {
		cin >> B[i];
		if (taken[B[i]]) {
			isDouble[B[i]] = 1;
			numDouble.pb(H[B[i]]);
		}
	}

	sort(numDouble.begin(), numDouble.end());
	LL cnt = 0;
	LL ans = 0;
	for (LL i = (LL)numDouble.size() - 1; i > -1; i--) {
		if (cnt % 2 == 0) {
			ans += numDouble[i];
		}
		cnt++;
	}

	for (LL i = 1; i <= N; i++) {
		if (taken[i] && !isDouble[i]) {
			ans += H[i];
		}
	}

	cout << ans << endl;
	return 0;
}