#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;

int N;
void main1() {
	cin >> N;
	vector<int> A(N + 1, -1);
	vector<vector<int> > id(N + 1, vector<int> ());
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		id[A[i]].pb(i);
	}

	vector<int> st(N + 1, -1);
	for (int i = 1; i <= N; i++) {
		if ((int)id[i].size() == 0) continue;

		sort(id[i].begin(), id[i].end());
		int now = 0;
		int maxDis = 0;
		for (int u : id[i]) {
			// cout << u << ' ';
			maxDis = max(maxDis, u - now);
			now = u;
		}
		// cout << endl;
		maxDis = max(maxDis, N + 1 - now);
		st[i] = maxDis;
	}

	// for (int i = 1; i <= N; i++) {
	// 	cout << st[i] << ' ';
	// }
	// cout << endl;

	vector<int> ans(N + 1, -1);
	for (int i = 1; i <= N; i++) {
		if (st[i] == -1) continue;
		if (ans[st[i]] == -1) {
			ans[st[i]] = i;
		} else {
			ans[st[i]] = min(ans[st[i]], i);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (ans[i - 1] == -1) {
			// pass
		} else {
			int tmp = ans[i];
			if (tmp == -1) ans[i] = ans[i - 1];
			else ans[i] = min(tmp, ans[i - 1]);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}
LL T;
int main() {
	cin >> T;
	while (T--) {
		main1();
	}

	return 0;
}