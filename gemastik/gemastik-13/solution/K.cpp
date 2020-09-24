#include <bits/stdc++.h>

#define pb push_back
using namespace std;
typedef long long LL;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	double u;
	vector<double> A;
	double sum = 0, maxi = 0;
	while (cin >> u) {
		A.pb(u);
		maxi = max(maxi, u);
		sum += u;
	}

	if (maxi > sum - maxi) {
		cout << "MUSTAHIL\n";
	} else {
		cout << "MUNGKIN\n";
	}

	return 0;
}