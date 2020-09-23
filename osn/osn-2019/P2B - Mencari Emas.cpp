#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;

int R, C, Q;
int ans[10];
ii kand;
bool inRange(ii a) {
	return 1 <= a.fi && a.fi <= R && 1 <= a.se && a.se <= C;
}
bool memenuhi(int a, int b) {
	return abs(a - 1) + abs(b - 1) == ans[0] &&
		abs(a - 1) + abs(b - C) == ans[1] &&
		abs(a - R) + abs(b - 1) == ans[2] &&
		abs(a - R) + abs(b - C) == ans[3];
}
int manDis(ii a, ii b) {
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}
bool isPossible(ii a, ii b) {
	return min(manDis(a, ii(1, 1)), manDis(b, ii(1, 1))) == ans[0] &&
		min(manDis(a, ii(1, C)), manDis(b, ii(1, C))) == ans[1] &&
		min(manDis(a, ii(R, 1)), manDis(b, ii(R, 1))) == ans[2] &&
		min(manDis(a, ii(R, C)), manDis(b, ii(R, C))) == ans[3];
}
int main() {
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C >> Q;
	cout << "? 1 1" << endl;
	cin >> ans[0];
	cout << "? 1 " << C << endl;
	cin >> ans[1];
	cout << "? " << R << " 1" << endl;
	cin >> ans[2];
	cout << "? " << R << " " << C << endl;
	cin >> ans[3];

	vector<ii> kand;
	ii kand1, kand2, kand3, kand4;
	int tmpI = (ans[0] + ans[1] - C + 1)/2;
	kand1 = ii(tmpI + 1, ans[0] + 1 - tmpI);
	if (inRange(kand1)) kand.pb(kand1);
	// cout << kand1.fi << " " << kand1.se << endl;

	tmpI = (R + ans[0] - ans[2] - 1)/2;
	kand2 = ii(tmpI + 1, ans[0] + 1 - tmpI);
	if (inRange(kand2)) kand.pb(kand2);
	// cout << kand2.fi << " " << kand2.se << endl;

	tmpI = (C - ans[2] - 1 + ans[3])/2;
	kand3 = ii(R - ans[3] + tmpI, C - tmpI);
	if (inRange(kand3)) kand.pb(kand3);
	// cout << kand3.fi << " " << kand3.se << endl;

	tmpI = (ans[1] + ans[3] - R + 1)/2;
	kand4 = ii(R - ans[3] + tmpI, C - tmpI);
	if (inRange(kand4)) kand.pb(kand4);
	// cout << kand4.fi << " " << kand4.se << endl;

	sort(kand.begin(), kand.end());
	kand.erase(unique(kand.begin(), kand.end()), kand.end());

	int sz = kand.size();
	assert(sz > 0);
	if (sz == 1) {
		cout << "! " << kand[0].fi << " " << kand[0].se << " " << kand[0].fi << " " << kand[0].se << endl;
	} else if (sz == 2) {
		cout << "! " << kand[0].fi << " " << kand[0].se << " " << kand[1].fi << " " << kand[1].se << endl;
	} else {
		cout << "? " << kand[0].fi << " " << kand[0].se << endl;
		cin >> ans[4];
		if (ans[4] == 0) {
			for (int i = 1; i < sz; i++) {
				if (isPossible(kand[0], kand[i])) {
					cout << "! " << kand[0].fi << " " << kand[0].se << " " << kand[i].fi << " " << kand[i].se << endl;
					return 0;
				}
			}
			assert(false);
		} else {
			for (int i = 1; i < sz; i++) {
				for (int j = i + 1; j < sz; j++) {
					if (isPossible(kand[i], kand[j])) {
						cout << "! " << kand[i].fi << " " << kand[i].se << " " << kand[j].fi << " " << kand[j].se << endl;
						return 0;						
					}
				}
			}
			assert(false);
		}
	}
	return 0;
}