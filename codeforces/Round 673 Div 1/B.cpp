#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef pair<ii, LL> iii;

LL N;
void main1() {
	cin >> N;
	vector<LL> A(N + 10, -1);
	LL sum = 0;
	for (LL i = 1; i <= N; i++) {
		cin >> A[i];
		sum += A[i];
	}

	if (sum % N != 0) {
		cout << -1 << endl;
		return;
	}

	LL avg = sum / N;

	vector<iii> op;
	for (LL i = 2; i <= N; i++) {
		LL div = A[i] / i;
		LL tmp1 = A[1] + div * i;
		LL tmp2 = A[i] - div * i;
		if (tmp2 == 0) {
			A[1] = tmp1;
			A[i] = tmp2;
			if (div > 0) op.pb({{i, 1}, div});
		}
		// cout << A[i] << ' ';
	}
	// cout << endl;
	// for (int i = 1; i <= N; i++) {
	// 	cout << A[i] << ' ';
	// }
	// cout << endl;
	// cout << op.size() << endl;

	vector<ii> rems;
	for (LL i = 2; i <= N; i++) {
		if (A[i] == 0) continue;
		LL rem = i - A[i] % i;
		rems.pb({rem, i});
	}
	sort(rems.begin(), rems.end());
	for (ii u : rems) {
		LL rem = u.fi, id = u.se;

		A[1] -= rem * 1;
		A[id] += rem * 1;
		op.pb({{1, id}, rem});

		if (A[1] < 0) {
			cout << -1 << endl;
			return;
		}

		LL div = A[id] / id;
		A[1] += div * id;
		A[id] -= div * id;
		op.pb({{id, 1}, div});
	}

	// for (int i = 1; i <= N; i++) {
	// 	cout << A[i] << ' ';
	// }
	// cout << endl;

	for (LL i = 2; i <= N; i++) {
		LL rem = avg - A[i];
		if (rem == 0) continue;
		A[1] -= rem;
		A[i] += rem;
		op.pb({{1, i}, rem});
	}

	// for (int i = 1; i <= N; i++) {
	// 	cout << A[i] << ' ';
	// }
	// cout << endl;

	cout << (LL)op.size() << endl;
	for (iii u : op) {
		cout << u.fi.fi << ' ' << u.fi.se << ' ' << u.se << endl;
	}
}
LL T;
int main() {
	cin >> T;
	while (T--) {
		main1();
	}

	return 0;
}