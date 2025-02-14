#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

ll N;
vector<pair<int, ll>> G[100001];
ll streecnt[100001];
ll dp[100001];
ll dp2[100001];
void func(int cur, int par) {
    ll &val = dp[cur] = 0;
    streecnt[cur] = 1;
    for (auto &p:G[cur]) {
        if (p.first == par) continue;
        func(p.first, cur);
        val += streecnt[p.first] * p.second + dp[p.first];
        streecnt[cur] += streecnt[p.first];
    }
}

void func2(int cur, int par, ll pval) {
    if (!par) dp2[cur] = dp[cur];
    else {
        dp2[cur] = dp2[par] - streecnt[cur] * pval + (N - streecnt[cur]) * pval;
    }
    for (auto &p:G[cur]) {
        if (p.first == par) continue;
        func2(p.first, cur, p.second);
    }
    
}
ll anode1, aval1, sz1, anode2, aval2, sz2;

void solve(ll &an, ll &av, ll &z) {
    cin >> N; z = N;
    for (int i = 1; i <= N; i++) G[i].clear();
    memset(streecnt, 0, sizeof(streecnt));
    for (int i = 1; i < N; i++) {
        int x, y, w; cin >> x >> y >> w;
        G[x].emplace_back(make_pair(y, w));
        G[y].emplace_back(make_pair(x, w));
    }

    func(1, 0);
    func2(1, 0, 0);
    av = 1000000000000000007LL;
    for (int i = 1; i <= N; i++) {
        if (dp2[i] < av) av = dp2[i], an = i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve(anode1, aval1, sz1);
    solve(anode2, aval2, sz2);
    cout << anode1 << ' ' << anode2 << '\n';
    cout << aval1 * sz2 + aval2 * sz1 + sz1 * sz2;

}