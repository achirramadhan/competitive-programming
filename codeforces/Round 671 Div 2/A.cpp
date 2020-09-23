#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;

int N;
string str;
void main1() {
	cin >> N;
	cin >> str;

	if (N % 2 == 0) {
		bool evenExist = 0;
		for (int i = 1; i < N; i += 2) {
			evenExist |= ((str[i] - '0') % 2) == 0;
		}

		cout << (evenExist? 2 : 1) << endl;
	} else {
		bool oddExist = 0;
		for (int i = 0; i < N; i += 2) {
			oddExist |= ((str[i] - '0') % 2) == 1;
		}

		cout << (oddExist? 1 : 2) << endl;
	}
}
LL T;
int main() {
	cin >> T;
	while (T--) {
		main1();
	}

	return 0;
}