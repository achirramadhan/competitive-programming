#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef long long LL;

LL N;
void main1() {
	cin >> N;

	LL now;
	cin >> now;

	LL u;
	LL depth = 1;
	vector<LL> num_leaf(N + 10, 0), pos(N + 10, 0);
	num_leaf[0] = 1;
	pos[0] = pos[1] = 1;
	for (LL i = 1; i < N; i++) {
		cin >> u;
		if (u > now) {
			num_leaf[depth]++;
		} else {
			if (pos[depth] + 1 > num_leaf[depth - 1]) {
				depth++;
			}

			pos[depth]++;
			num_leaf[depth]++;
		}
		now = u;
	}

	cout << depth << endl;
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