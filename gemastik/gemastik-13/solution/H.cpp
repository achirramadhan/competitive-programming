#include <bits/stdc++.h>

#define pb push_back
using namespace std;
typedef long long LL;

LL N, M, Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> Q;
	vector<vector<LL> > A(N + 20, vector<LL>(M + 20, 0));

	for (LL i = 1; i <= N; i++){
		for (LL j = 1; j <= M; j++){
			cin >> A[i][j];
		}
	}

	for (LL i = 1; i <= N; i++) {
		for (LL j = 1; j <= M; j++) {
			A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
		}
	}

	LL x1, y1, x2, y2;
	while (Q--) {
		cin >> x1 >> y1 >> x2 >> y2;

		cout << A[x2][y2] - A[x2][y1 - 1] - A[x1 - 1][y2] + A[x1 - 1][y1 - 1] << endl;
	}

	return 0;
}