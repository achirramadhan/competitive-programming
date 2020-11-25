#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef long long LL;

LL L, R, N;
string str;
void main1() {
	cin >> N;
	cin >> str;

	LL ans0 = 0, ans1 = 0;
	for (int i = 1; i < N; i++) {
		if (str[i] == str[i - 1]) {
			if (str[i] == '0') {
				ans0++;
			} else {
				ans1++;
			}
		}
	}

	cout << max(ans0, ans1) << endl;
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