#include <bits/stdc++.h>

#define pb push_back
using namespace std;
typedef long long LL;

LL N;
LL A[10100], B[10100];
int main() {
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (LL i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		B[i] = A[i];
	}

	reverse(B + 1, B + N + 1);

	LL dp[2][N + 10];
	for (LL j = 0; j <= N + 10; j++) {
		dp[0][j] = j;
	}

	for (LL i = 1; i <= N; i++) {
		LL row = i % 2;
		LL rowm1 = (i - 1) % 2;
		dp[row][0] = i;

		for (LL j = 1; j <= N; j++) {
			dp[row][j] = dp[row][j - 1] + 1;
			dp[row][j] = min(dp[row][j], dp[rowm1][j] + 1);
			if (A[i] == B[j]) {
				dp[row][j] = min(dp[row][j], dp[rowm1][j - 1]);
			}
		}

		// for (LL j = 0; j <= N; j++) {
		// 	cout << dp[row][j] << ' ';
		// }
		// cout << endl;
	}

	printf("%lld\n", dp[N % 2][N] / 2);

	return 0;
}