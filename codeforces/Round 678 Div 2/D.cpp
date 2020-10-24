#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef long long LL;

LL N, A[200100];
vector<LL> adj[200100];

vector<LL> dfs(LL now, LL par) { // return max_catch, sum, num_leaf
	bool passed = false;
	LL max_catch = 0;
	LL sum = 0;
	LL num_leaf = 0;
	for (LL u : adj[now]) {
		if (u == par) continue;
		passed = true;

		vector<LL> tmp = dfs(u, now);
		max_catch = max(max_catch, tmp[0]);
		sum += tmp[1];
		num_leaf += tmp[2];
	}

	// leaf
	if (!passed) {
		vector<LL> ans;
		ans.pb(A[now]); // max_catch
		ans.pb(A[now]); // sum
		ans.pb(1); // num_leaf
		return ans;
	}

	sum += A[now];

	if (max_catch * num_leaf >= sum) {
		vector<LL> ans;
		ans.pb(max_catch);
		ans.pb(sum);
		ans.pb(num_leaf);
		return ans;
	}

	vector<LL> ans;
	max_catch = (sum + num_leaf - 1) / num_leaf;
	ans.pb(max_catch);
	ans.pb(sum);
	ans.pb(num_leaf);
	return ans;
}
void main1() {
	cin >> N;
	LL u;
	for (LL i = 2; i <= N; i++) {
		cin >> u;
		adj[u].pb(i);
		adj[i].pb(u);
	}

	for (LL i = 1; i <= N; i++) {
		cin >> A[i];
	}

	vector<LL> ans = dfs(1, -1);

	cout << ans[0] << endl;
}
LL T;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// cin >> T;
	T = 1;
	while (T--) {
		main1();
	}

	return 0;
}