#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long LL;

LL T, N, A[100100];
void main1() {
	cin >> N;
	for (LL i = 0; i < N; i++) {
		cin >> A[i];
	}

	priority_queue<LL> pq;

	for (LL i = 0; i < N; i++) {
		pq.push(A[i]);
	}

	while (!pq.empty()) {
		LL ca = pq.top();
		pq.pop();

		ca--;

		if (pq.empty()) {
			cout << "T\n";
			return;
		}

		LL ca2 = pq.top();
		pq.pop();
		ca2--;

		if (ca > 0) {
			pq.push(ca);
		}

		if (ca2 > 0) {
			pq.push(ca2);
		}
	}

	cout << "HL\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		main1();
	}

	return 0;
}