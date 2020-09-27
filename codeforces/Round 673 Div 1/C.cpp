#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef pair<LL, ii> iii;

LL N;
LL BIT[500100], A[500100];
const LL MAXI = (LL)1e9 + 10;
void update(LL now) {
	for (LL i = now; i < 500100; i += (i & -i)) {
		BIT[i]++;
	}
}
LL query(LL now) {
	LL sum = 0;
	for (LL i = now; i > 0; i -= (i & -i)) {
		sum += BIT[i];
	}
	return sum;
}
LL countInv() {
	set<LL> se;
	for (LL i = 1; i <= N; i++)
		se.insert(A[i]);
	
	map<LL, LL> ma;
	LL id = 1;
	for (auto u : se) {
		ma[u] = id++;
	}

	vector<LL> sal;
	sal.pb(0);
	for (LL i = 1; i <= N; i++) {
		sal.pb(ma[A[i]]);
		// cout << ma[A[i]] << ' ';
	}
	// cout << endl;

	LL numInv = 0;	
	for (LL i = 1; i <= N; i++) {
		LL u = sal[i];
		numInv += (i - 1) - query(u);
		// cout << numInv << ' ';
		update(u);
	}
	// cout << endl;

	return numInv;
}
void main1() {
	cin >> N;
	for (LL i = 1; i <= N; i++) {
		cin >> A[i];
	}

	LL ans = 0;
	vector<iii> sal(N + 10, {0, {0, 0}});

	for (LL j = 1; j <= N; j++)
		sal[j] = {A[j], {0, j}}; // self, prefix, idx

	for (LL i = 31; i >= 0; i--) {
		LL sumInv = 0, sumNegInv = 0;
		LL num0 = 0, num1 = 0, inv = 0;

		// cout << "DEBUG " << i << endl;
		// for (LL j = 1; j <= N; j++) {
		// 	cout << sal[j].fi << ' ' << sal[j].se.fi << ' ' << sal[j].se.se << endl;
		// }
		// cout << endl;

		for (LL j = 1; j <= N; j++) {
			if (sal[j].se.fi != sal[j - 1].se.fi) { // prefix beda
				sumInv += inv;
				sumNegInv += num0 * num1 - inv;
				// cout << inv << "-" << num0 << "-" << num1 << endl;
				num0 = num1 = inv = 0;
			}

			if ((sal[j].fi & (1LL << i)) == 0) {
				inv += num1;
			}

			if (sal[j].fi & (1LL << i)) num1++;
			else num0++;
		}

		sumInv += inv;
		// cout << inv << "-" << num0 << "-" << num1 << endl;
		sumNegInv += num0 * num1 - inv;
		num0 = num1 = inv = 0;

		// cout << i << ' ' << sumNegInv << ' ' << sumInv << endl;
		if (sumNegInv < sumInv) {
			ans += (1LL << i);
			for (LL j = 1; j <= N; j++) {
				sal[j].fi ^= (1LL << i);
			}
		}

		for (LL j = 1; j <= N; j++) {
			sal[j].se.fi += (1LL << i) & sal[j].fi; // update prefix
		}

		sort(sal.begin() + 1, sal.begin() + N + 1, [&](iii &a, iii &b) {
			return a.se < b.se;
		});
	}

	for (LL i = 1; i <= N; i++) {
		A[sal[i].se.se] = sal[i].fi;
	}
	
	// for (LL i = 1; i <= N; i++) {
	// 	cout << A[i] << ' ';
	// }
	// cout << endl;

	LL numInv = countInv();

	cout << numInv << ' ' << ans << endl;
}
LL T;
int main() {
	// cin >> T;
	T = 1;
	while (T--) {
		main1();
	}

	return 0;
}