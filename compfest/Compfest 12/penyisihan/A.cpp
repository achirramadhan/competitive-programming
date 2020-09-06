#include <bits/stdc++.h>

#define pb push_back
using namespace std;
typedef long long LL;

LL N, M, A[100100];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	vector<LL> num;
	for (LL i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] != 0) num.pb(A[i]);
	}
	
	if ((LL)num.size() < 9) {
		for (LL i = (LL)num.size(); i < 9; i++) {
			num.pb(0);
		}
	}
	
	LL num2 = 0, num5 = 0;
	while (M % 2 == 0) {
		num2++;
		M /= 2;
	}
	while (M % 5 == 0) {
		num5++;
		M /= 5;
	}
	
	vector<LL> rem(1000100, -1);
	LL now = 1;
	for (LL i = 0; i < 1000100; i++) {
		rem[i] = now;
		now *= (LL)1e9;
		now %= M;
	}
	
	// for (LL i = 0; i < 20; i++) {
		// cout << rem[i] << ' ';
	// }
	// cout << endl;
	
	for (LL i = 1; i < 1000100; i++) {
		rem[i] += rem[i - 1];
		rem[i] %= M;
	}
	
	// for (LL i = 0; i < 20; i++) {
		// cout << rem[i] << ' ';
	// }
	// cout << endl;
	
	vector<LL> idxOcc(M + 10, -1);
	LL chs1 = -1, chs2 = -1;
	for (LL i = 0; i < 1000100; i++) {
		if (idxOcc[rem[i]] != -1) {
			chs1 = idxOcc[rem[i]];
			chs2 = i;
			break;
		}
		
		idxOcc[rem[i]] = i;
	}
	
	// cout << chs1 << ' ' << chs2 << endl;
	// cout << rem[chs1] << ' ' << rem[chs2] << endl;
	for (LL i = chs2; i > chs1; i--) {
		for (LL u : num) {
			cout << u;
		}
	}
	
	LL num0 = 0;
	for (LL i = chs1; i >= 0; i--) {
		for (LL u : num) {
			cout << 0;
			num0++;
		}
	}
	
	num2 -= num0;
	num5 -= num0;
	
	num2 = max(num2, num5);
	num2 = max(num2, 0LL);
	
	for (LL i = 0; i < num2; i++) {
		cout << 0;
	}
	
	cout << endl;
	
	return 0;
}