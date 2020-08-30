#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long LL;

LL T, N, A[100100], num[100100];
void main1() {
	cin >> N;
	for (LL i = 0; i < N; i++) {
		cin >> A[i];
	}

	if (N == 1) {
		cout << "1 1\n";
		cout << "0\n";
		cout << "1 1\n";
		cout << "0\n";
		cout << "1 1\n";
		cout << -A[0] << endl;
		return;
	}

	for (LL x = 0; x < N; x++) {
		LL a = (N - 1) * x;
		a %= N;
		num[a] = (N - 1) * x;
	}

	vector<LL> ans1, ans2;
	for (LL i = 0; i < N - 1; i++) {
		LL rem = (N - A[i] % N) % N;
		rem += 10 * N;
		rem %= N;

		ans1.pb(num[rem]);
		ans2.pb(num[rem] + A[i]);
	}

	cout << 1 << ' ' << N - 1 << endl;
	for (LL u : ans1) {
		cout << u << ' ';
	}
	cout << endl;

	cout << N << ' ' << N << endl;
	LL rem = (((N - A[N - 1] % N) % N) + 10 * N) % N;
	cout << rem << endl;

	ans2.pb(A[N - 1] + rem);

	cout << 1 << ' ' << N << endl;
	for (LL u : ans2) {
		cout << -u << ' ';
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// cin >> T;
	T = 1;
	while (T--) {
		main1();
	}

	return 0;
}