#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;

LL X;
const LL INF = (LL)1e18 + 10;
void main1() {
	cin >> X;
	LL sum = 0;
	LL now = 0;
	LL cnt = 0;
	for (LL i = 1; i * i < INF; i *= 2) {
		now = 2 * now + i * i;
		sum += now;
		if (sum > X) break;
		cnt++;
	}
	cout << cnt << endl;
}
LL T;
int main() {
	cin >> T;
	while (T--) {
		main1();
	}

	return 0;
}