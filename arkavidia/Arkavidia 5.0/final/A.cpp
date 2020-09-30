#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef long long LL;

LL N, M;
const LL MAXI = 200100;
vector<LL> leastFac(MAXI, 1);
void get_fac(vector<LL> &fac, LL N) {
	while (N > 1) {
		fac.pb(leastFac[N]);
		N /= leastFac[N];
	}

	sort(fac.begin(), fac.end());
	fac.erase(unique(fac.begin(), fac.end()), fac.end());
}
void main1() {
	cin >> N >> M;
	vector<LL> fac(N + 10, 0);
	get_fac(fac, N);

	vector<bool> dp(N + 10, 0);
	dp[0] = 1;
	for (LL i = 0; i < N + 10; i++) {
		for (LL u : fac) {
			if (i + u >= N + 10) {
				break;
			}
			dp[i + u] = dp[i + u] | dp[i];
		}
	}

	cout << ((dp[M] & dp[N - M])? "YA\n" : "TIDAK\n");
}
LL T;
void generate_prime() {
	for (LL i = 1; i < MAXI; i++) {
		leastFac[i] = i;
	}

	for (LL i = 2; i < MAXI; i++) {
		for (LL j = i * i; j < MAXI; j += i) {
			if (leastFac[j] == j) {
				leastFac[j] = i;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	generate_prime();

	cin >> T;
	while (T--) {
		main1();
	}

	return 0;
}