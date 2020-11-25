#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef long long LL;

LL N, Q;
LL pref[2][120];
string str;
void main1() {
	cin >> N >> Q;
	cin >> str;

	for (int i = 0; i < N + 10; i++) {
		pref[0][i] = 0;
		pref[1][i] = 0;
	}

	for (int i = 0; i < N; i++) {
		pref[0][i] = str[i] == '0';
		pref[1][i] = str[i] == '1';

		if (i > 0) {
			pref[0][i] += pref[0][i - 1];
			pref[1][i] += pref[1][i - 1];
		}
	}

	LL l, r;
	for (int i = 0; i < Q; i++) {
		cin >> l >> r;
		l--; r--;
		int ka = str[r] - '0';
		int ki = str[l] - '0';

		if ((0 < l && pref[ki][l - 1] > 0) ||
			(pref[ka][N - 1] - pref[ka][r] > 0)) {
			cout << "YES\n";
			continue;
		}

		cout << "NO\n";
	}
}
LL T;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		main1();
	}

	return 0;
}