#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef long long LL;

LL N;
void main1() {
	cin >> N;

	if (N == 1) {
		cout << 0 << endl;
	} else if (N == 2) {
		cout << 1 << endl;
	} else if (N % 2 == 0) {
		cout << min(N - 1, 2LL) << endl;
	} else {
		cout << min(N - 1, 3LL) << endl;
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