#include <bits/stdc++.h>

#define pb push_back
using namespace std;

int N, M, Q;
int main() {
	cin >> N >> M >> Q;
	vector<int> pasangan(N + M + 10, 0);

	for (int i = 1; i <= M + N; i <<= 1) {
		vector<int> tanya;
		for (int j = 1; j <= M + N; j++) {
			if (i & j) {
				tanya.pb(j);
			}
		}

		cout << "? " << (int)tanya.size();
		for (int u : tanya) {
			cout << " " << u;
		}
		cout << endl;

		int numAns, a;
		cin >> numAns;
		for (int j = 0; j < numAns; j++) {
			cin >> a;
			pasangan[a] += i;
		}
	}

	// for (int i = 1; i <= M + N; i++) {
	// 	cout << i << " : " << pasangan[i] << endl;
	// }

	for (int i = 1; i <= N; i++) {
		if (pasangan[i] < N + 1 || pasangan[i] > N + M) {
			cout << "! " << i << endl;
			return 0;
		}

		for (int j = N + 1; j < pasangan[i]; j++) {
			if (pasangan[j] == i) {
				cout << "! " << i << endl;
				return 0;
			}
		}
	}

	for (int i = N + 1; i <= N + M; i++) {
		if (pasangan[i] < 1 || pasangan[i] > N) {
			cout << "! " << i << endl;
			return 0;
		}

		for (int j = 1; j < pasangan[i]; j++) {
			if (pasangan[j] == i) {
				cout << "! " << i << endl;
				return 0;
			}
		}
	}

	assert(false);

	return 0;
}