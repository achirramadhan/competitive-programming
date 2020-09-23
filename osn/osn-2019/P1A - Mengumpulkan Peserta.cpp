#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> ii;

int R, C;
string tab[100100];
const int INF = (int)1e9 + 10;
int getPref(int r1, int c1, int r2, int c2, vector<vector<int> > &pref) {
	int ans = pref[r2][c2];
	if (c1 - 1 >= 0) {
		ans -= pref[r2][c1 - 1];
	}
	if (r1 - 1 >= 0) {
		ans -= pref[r1 - 1][c2];
	}
	if (r1 - 1 >= 0 && c1 - 1 >= 0) {
		ans += pref[r1 - 1][c1 - 1];
	}

	return ans;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> tab[i];
	}

	int num = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			num += tab[i][j] == '1';
		}
	}

	vector<vector<int> > pref(R + 10, vector<int> (C + 10, 0));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			pref[i][j] = tab[i][j] == '1';
			if (i - 1 >= 0) {
				pref[i][j] += pref[i - 1][j];
			}
			if (j - 1 >= 0) {
				pref[i][j] += pref[i][j - 1];
			}
			if (i - 1 >= 0 && j - 1 >= 0) {
				pref[i][j] -= pref[i - 1][j - 1];
			}

			// cout << pref[i][j] << " ";
		}
		// cout << endl;
	}

	vector<ii> fac;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			fac.pb(ii(i, num/i));
		}
	}

	int ans = INF;
	for (ii u : fac) {
		// cout << "u : " << u.fi << " " << u.se << endl;
		if (R - u.fi < 0 || C - u.se < 0) {
			continue;
		}
		for (int i = 0; i <= R - u.fi; i++) {
			for (int j = 0; j <= C - u.se; j++) {
				int tmpPref = getPref(i, j, i + u.fi - 1, j + u.se - 1, pref);
				// cout << tmpPref << " ";
				ans = min(ans, num - tmpPref);
			}
			// cout << endl;
		}
	}

	cout << (ans == INF? -1 : ans) << endl;
	return 0;
}