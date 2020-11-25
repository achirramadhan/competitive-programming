#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;

LL D, K;
void main1() {
	cin >> D >> K;

	vector<ii> points;
	vector<LL> num;
	for (LL i = 0; i <= D; i += K) {
		num.pb(i);
	}
	
	LL v = num.back();
	for (LL u : num) {
		while (u * u + v * v > D * D) {
			v -= K;
		}

		if (points.size() > 0 && points.back().se == v / K) {
			points.pop_back();
		}

		points.pb({u / K, v / K});
	}

	LL minD = abs(points[0].fi - points[0].se);
	ii chs = points[0];
	for (ii &u : points) {
		if (abs(u.fi - u.se) < minD) {
			minD = abs(u.fi - u.se);
			chs = u;
		}
	}

	cout << (((chs.fi + chs.se) % 2)? "Ashish\n" : "Utkarsh\n");
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