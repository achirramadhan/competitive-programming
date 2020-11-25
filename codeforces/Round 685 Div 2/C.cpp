#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef long long LL;

LL N, K;
void main1() {
	cin >> N >> K;

	vector<int> cnt1(30, 0), cnt2(30, 0);
	string str1, str2;
	cin >> str1;
	cin >> str2;

	for (char u : str1) {
		cnt1[u - 'a']++;
	}
	for (char u : str2) {
		cnt2[u - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (cnt1[i] < cnt2[i]) {
			cout << "No\n";
			return;
		}

		cnt1[i] -= cnt2[i];
		if (cnt1[i] % K != 0) {
			cout << "No\n";
			return;
		}

		cnt1[i + 1] += cnt1[i];
		cnt1[i] = 0;
	}

	cout << "Yes\n";
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