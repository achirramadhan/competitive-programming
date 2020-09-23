#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;

LL N, A[100100];
void main1() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);

	vector<int> ans(N + 10, 0);
	int j = 0;
	for (int i = 1; i < N; i += 2) {
		ans[i] = A[j++];
	}
	for (int i = 0; i < N; i += 2) {
		ans[i] = A[j++];
	}

	int num = 0;
	for (int i = 1; i < N - 1; i++) {
		if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) {
			num++;
		}
	}

	cout << num << endl;
	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}
LL T;
int main() {
	// cin >> T;
	T = 1;
	while (T--) {
		main1();
	}

	return 0;
}