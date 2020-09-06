#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
typedef pair<int, int> ii;

int N, A[100100], sal[100100];
bool kerja() {
	vector<bool> taken(N + 10, 0);
	vector<int> ans;
	for (int i = 0, j = 0; i < N && j < N; i++) {
		while (A[j] != sal[i] && j < N) {
			j++;
		}
		
		if (j == N) break;
		ans.pb(A[j]);
		taken[j] = 1;
	}
	
	for (int i = N - 1; i >= 0; i--) {
		if (!taken[i]) {
			ans.pb(A[i]);
		}
	}
	
	// for (int u : ans) {
	// 	cout << u << ' ';
	// }
	// cout << endl;
	
	for (int i = 1; i < N; i++) {
		if (ans[i] <= ans[i - 1]) {
			return false;
		}
	}
	
	return true;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sal[i] = A[i];
	}

	sort(sal, sal + N);
	
	if (kerja()) {
		cout << "Ya\n";
		return 0;
	}
	
	reverse(A, A + N);
	if (kerja()) {
		cout << "Ya\n";
		return 0;
	}
	
	cout << "Tidak\n";
	
	return 0;
}