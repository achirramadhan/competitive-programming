#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long LL;

typedef pair<LL, LL> ii;
typedef pair<LL, ii> iii;

vector<LL> adj[13000];
LL pos[13000];
vector<iii> edges;
LL N, M, K;
LL par[13000], sz[13000];
LL get_par(LL now) {
    if (par[now] != now) {
        par[now] = get_par(par[now]);
    }
    return par[now];
}
void uni(LL a, LL b) {
    a = get_par(a);
    b = get_par(b);

    if (sz[a] < sz[b]) {
        par[a] = b;
    } else {
        par[b] = a;
        if (sz[a] == sz[b]) {
            sz[a]++;
        }
    }
}
LL hitung_mst(vector<iii> &e) {
    sort(e.begin(), e.end());

    LL sum = 0;
    for (auto u : e) {
        LL a = get_par(u.se.fi);
        LL b = get_par(u.se.se);
        if (a == b) {
            continue;
        }

        sum += u.fi;
        uni(a, b);
    }

    return sum;
}
LL mst(bool isPos) {
    vector<iii> e;
    if (isPos == 0) {
        for (iii u : edges) {
            if (pos[u.se.fi] == 2 && pos[u.se.se] == 2) {
                e.pb(u);
            }
        }
    } else if (isPos == 1) {
        for (iii u : edges) {
            if (pos[u.se.fi] == 1 && pos[u.se.se] == 1) {
                e.pb(u);
            }
        }
        // for (auto u : e) {
        //     cout << u.fi << ' ' << u.se.fi << ' ' << u.se.se << endl;
        // }
    }

    return hitung_mst(e);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    LL u;
    for (LL i = 0; i < 13000; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (LL i = 1; i <= N; i++) {
        cin >> u;
        pos[u] = 1;
    }
    for (LL i = 1; i <= M; i++) {
        cin >> u;
        pos[u] = 2;
    }

    LL v, w;
    for (LL i = 0; i < K; i++) {
        cin >> u >> v >> w;
        edges.pb({w, {u, v}});
    }

    cout << mst(0) + mst(1) << endl;

    return 0;
}