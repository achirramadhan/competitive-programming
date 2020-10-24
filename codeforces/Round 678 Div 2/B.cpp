#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef long long LL;

LL N;
LL PRIME = 1031;
void main1() {
	cin >> N;
	LL sisa = PRIME - 1;
	sisa /= 2;

	LL num = sisa / (N - 1);
	LL num1 = sisa % (N - 1);
	LL num2 = N - sisa % (N - 1);

	vector<LL> bil;
	for (int i = 0; i < num1; i++) {
		bil.pb((num + 1) * 2);
	}
	for (int i = num1; i < N - 1; i++) {
		bil.pb(num * 2);
	}

	bil.pb(1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << bil[(i + j) % N];
			cout << (j == N - 1? '\n' : ' ');
		}
	}
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