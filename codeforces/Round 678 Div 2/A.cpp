#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef long long LL;

LL N, M;
void main1() {
	cin >> N >> M;
	LL sum = 0;
	LL u;
	for (int i = 0; i < N; i++) {
		cin >> u;
		sum += u;
	}

	cout << (sum == M? "YES\n" : "NO\n");
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