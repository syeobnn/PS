#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define MAX 1e9
#define log2 18
#define divisor 1000000007

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll> >;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int ddx[] = {1, -1, 0, 0};
const int ddy[] = {0, 0, -1, 1};
const int INF = 987654321;
const ll LINF = 3123372036854775807;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<pll> arr[200010];
int level[200010];
int pararr[log2+1][200010];
ll length[200010];
int A = 1, B = 1;
ll jirum;

void mktree(int par, int cur, ll len, int lv) {
    pararr[0][cur] = par;
    level[cur] = lv;
    length[cur] = len + length[par];
}

void mksparse(int n) {
    for (int i = 0; i < log2; i++) {
        for (int j = 1; j <= n; j++) {
            if (pararr[i][j] == -1) continue;
            int temp = pararr[i][j];
            pararr[i + 1][j] = pararr[i][temp];
        }
    }
}

int lca(int a, int b) {
    if (level[a] > level[b])
        swap(a, b);
    int lvlDeg = level[b] - level[a];

    for (int i = 0; i < log2; i++) {
        if (lvlDeg & (1 << i)) {
            b = pararr[i][b];
        }
    }

    for (int i = log2; i >= 0; i--) {
        if (pararr[i][a] == pararr[i][b]) continue;
        a = pararr[i][a];
        b = pararr[i][b];
    }

    if (a == b)
        return a;

    return pararr[0][a];
}

ll mkdist(int a, int t) {
    int ulca = lca(a, t);
    ll dist = length[a] + length[t] - 2 * length[ulca];
    return dist;
}

void get_jirum(int s) {
    ll tmpa = mkdist(A, s);
    ll tmpb = mkdist(B, s);

    if (tmpa > tmpb) {
        if (tmpa > jirum) {
            B = s;
            jirum = tmpa;
        }
    } else {
        if (tmpb > jirum) {
            A = s;
            jirum = tmpb;
        }
    }
}

int main() {
    fastIo();

    memset(pararr, -1, sizeof(pararr));

    int n;

    cin >> n;

    pararr[0][1] = 1;
    level[1] = 1;

    for (int i = 2; i <= n + 1; i++) {
        int node, amount;
        cin >> node >> amount;
        arr[node].emplace_back(i, amount + length[node]);
        mktree(node, i, amount, level[node] + 1);
    }

    mksparse(n+1);

    for (int i = 2; i <= n + 1; i++) {
        get_jirum(i);

        cout << jirum << "\n";
    }

    return 0;
}
