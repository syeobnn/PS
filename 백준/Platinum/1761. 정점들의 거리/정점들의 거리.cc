#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define ll long long
#define pii pair<int, int>
#define MAX 1e9
#define log2 18

using namespace std;

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

int N, Q;
int level[100010];
int parents[log2 + 1][100010];
long long lenlen[100010];
vector<pair<int, long long>> arr[100010];
vector<pair<int, long long>> tree[100010];

void mk_tree(int cur, int par, long long len, int lv) {
    parents[0][cur] = par;
    level[cur] = lv;
    lenlen[cur] = len;
    for (auto i : arr[cur]) {
        int next = i.first;
        if (par == next)
            continue;
        long long cost = len + i.second;
        tree[cur].emplace_back(next, cost);
        mk_tree(next, cur, cost, lv+1);
    }
}

int lca(int a, int b) {
    if (level[a] > level[b])
        swap(a, b);
    int lvlDeg = level[b] - level[a];

    for (int i =0;i<log2;i++) {
        if (lvlDeg & (1 << i)) {
            b = parents[i][b];
        }
    }

    for (int i = log2; i>=0;i--) {
        if (parents[i][a] == parents[i][b]) continue;
        a = parents[i][a];
        b = parents[i][b];
    }

    if (a == b)
        return a;

    return parents[0][a];
}

int main() {
    fastIo();

    cin >> N;

    for (int i =0;i<N - 1;i++) {
        int a, b, c;
        cin >> a >> b >> c;

        arr[a].emplace_back(b, c);
        arr[b].emplace_back(a, c);
    }

    mk_tree(1, 1, 0, 1);

    for (int i =0;i<log2;i++) {
        for (int j=1;j<=N;j++) {
            int temp = parents[i][j];
            parents[i+1][j] = parents[i][temp];
        }
    }

    cin >> Q;

    while (Q--) {
        int a, b;

        //거리구하기
        /*누적합으로 거리는 다 계산이 되어있음
         *각 node의 거리를 더한 뒤 lca node의 거리만큼 두 번 빼주면 됨
         */
        cin >> a >> b;

        int l = lca(a, b);

        long long ans = lenlen[a] + lenlen[b] - lenlen[l]*2;

        cout << ans << "\n";
    }
    return 0;
}
