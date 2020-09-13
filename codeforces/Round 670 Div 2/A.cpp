#include <bits/stdc++.h>

using namespace std;

int T, A, B;
int N, u;
int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		int u;
		vector<int> cnt(110, 0);
		for (int i = 0; i < N; i++) {
			cin >> u;
			cnt[u]++;
		}

		int ans = 0;
		for (int i = 0; i <= 100; i++) {
			cnt[i]--;
			if (cnt[i] < 0) {
				ans += i;
				break;
			}
		}

		for (int i = 0; i <= 100; i++) {
			cnt[i]--;
			if (cnt[i] < 0) {
				ans += i;
				break;
			}
		}

		cout << ans << endl;
	}

	return 0;
}