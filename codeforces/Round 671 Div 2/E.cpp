#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;

LL N;
void main1() {
	cin >> N;
	vector<LL> fac;
	vector<LL> prime;
	for (LL i = 1; i * i <= N; i++) {
		if (N % i == 0) {
			if (i != 1) fac.pb(i);
			fac.pb(N / i);
		}
	}
	sort(fac.begin(), fac.end());
	fac.erase(unique(fac.begin(), fac.end()), fac.end());
	for (LL i = 0; i < (LL)fac.size(); i++) {
		bool isPrime = 1;
		for (LL j = 0; j < i; j++) {
			if (fac[i] % fac[j] == 0) {
				isPrime = 0;
			}
		}
		if (isPrime) {
			prime.pb(fac[i]);
		}
	}

	vector<LL> l1;
	LL m = prime.size();
	for (LL i = 0; i < m; i++) {
		l1.pb(prime[i] * prime[(i + 1) % m]);
	}

	vector<vector<LL> > l2(m, vector<LL>());
	vector<bool> taken((LL)fac.size(), 0);
	for (LL i = 0; i < m; i++) {
		for (LL j = 0; j < (LL)fac.size(); j++) {
			if (prime[i] == fac[j]) {
				taken[j] = 1;
			}
			if (l1[i] == fac[j]) {
				taken[j] = 1;
			}
		}
	}

	if (l1.back() == l1[0] && (LL)l1.size() > 1) {
		for (LL j = 0; j < (LL)fac.size(); j++) {
			if (!taken[j] && fac[j] % l1.back() == 0) {
				l1.back() = fac[j];
				taken[j] = 1;
				break;
			}
		}
	}

	for (LL i = 0; i < m; i++) {
		for (LL j = 0; j < (LL)fac.size(); j++) {
			if (!taken[j] && (fac[j] % prime[i]) == 0) {
				l2[i].pb(fac[j]);
				taken[j] = 1;
			}
		}
	}

	vector<LL> ans;
	for (LL i = 0; i < m; i++) {
		ans.pb(prime[i]);
		for (LL u : l2[i]) {
			ans.pb(u);
		}
		ans.pb(l1[i]);
	}

	for (LL i = 0; i < (LL)fac.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;

	LL chg = (LL)ans.size() - (LL)fac.size();
	cout << chg << endl;
}
LL T;
int main() {
	cin >> T;
	while (T--) {
		main1();
	}

	return 0;
}