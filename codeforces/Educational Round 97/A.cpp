#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef long long LL;

LL L, R;
void main1() {
	cin >> L >> R;

	LL A = 2 * L;
	if (R < A) {
		cout << "YES\n";
	} else {
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