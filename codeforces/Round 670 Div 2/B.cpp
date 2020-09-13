#include <bits/stdc++.h>

#define pb push_back
using namespace std;

typedef long long LL;

LL T;
LL N, A[200100];
const LL INF = (LL)1e18 + 10;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (LL i = 0; i < N; i++) {
			cin >> A[i];
		}

		sort(A, A + N, [&](LL a, LL b) { return abs(a) < abs(b); });

		if (A[N - 5] == 0) {
			cout << 0 << endl;
			continue;
		}

		LL sign = 1;
		vector<LL> neg;
		vector<LL> pos;
		for (LL i = 0; i < 5; i++) {
			if (A[N - i - 1] > 0) {
				sign *= 1;
				pos.pb(N - i - 1);
			} else {
				sign *= -1;
				neg.pb(N - i - 1);
			}
		}

		if (N == 5 || sign == 1) {
			LL ans = 1;
			for (LL i = N - 1; i > N - 6; i--) {
				ans *= A[i];
			}
			cout << ans << endl;
			continue;
		} else {
			LL ans = 1;
			for (LL i = N - 1; i > N - 6; i--) {
				ans *= A[i];
			}

			LL leastPos = -INF;
			LL biggestNeg = INF;
			if (pos.size() > 0) {
				leastPos = A[pos.back()];
			}
			if (neg.size() > 0) {
				biggestNeg = A[neg.back()];
			}

			LL maxi = ans;
			for (LL i = N - 6; i > -1; i--) {
				if (A[i] >= 0 && biggestNeg != INF) {
					maxi = max(maxi, (ans / biggestNeg) * A[i]);
				}
				if (A[i] <= 0 && leastPos != -INF) {
					maxi = max(maxi, (ans / leastPos) * A[i]);
				}
			}
			
			if (maxi < 0) {
				maxi = 1;
				for (int i = 0; i < 5; i++) {
					maxi *= A[i];
				}
			}

			cout << maxi << endl;
		}
	}

	return 0;
}