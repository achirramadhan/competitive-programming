#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;

LL N, X;
const LL INF = (LL)1e18 + 10;
void main1() {
	cin >> N >> X;
	LL sum = 0;
	LL u;
	bool allEq = 1;
	bool eqExist = 0;
	for (int i = 0; i < N; i++) {
		cin >> u;
		sum += u;

		if (u != X) {
			allEq = 0;
		}
		if (u == X) {
			eqExist = 1;
		}
	}

	if (sum == N * X) {
		if (allEq) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
	} else {
		if (eqExist) {
			cout << 1 << endl;
		} else {
			cout << 2 << endl;
		}
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