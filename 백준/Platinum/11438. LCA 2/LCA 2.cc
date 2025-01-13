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

int N, T;
vector<int> tree[100001];
vector<int> arr[100001];
int parents[log2 + 1][100001];
int level[100001];
//int arr[21][200001];

void mk_tree(int cur, int par, int lv) {
    level[cur] = lv;
    parents[0][cur] = par;

    for (auto i: arr[cur]) {
        if (i == par)continue;
        tree[cur].push_back(i);
        mk_tree(i, cur, lv + 1);
    }
}

int func_query(int n, int x) {
    int ans = x;

    for (int i = 0; i < log2; i++) {
        if (n & (1 << i))
            ans = arr[i][ans];
    }

    return ans;
}

int lca(int a, int b) {
    //level[a] < level[b];
    int ans = 0;
    int idx_l = level[b] - level[a];

    for (int i = 0; i < log2; i++) {
        if (idx_l & (1 << i)) {
            b = parents[i][b];
        }
    }

    for (int i = log2; i >= 0 ; i--) {
        if (parents[i][b] == parents[i][a]) continue;
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

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    mk_tree(1, 1, 1);

    for (int i = 0; i < log2; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp = parents[i][j];
            parents[i + 1][j] = parents[i][tmp];
        }
    }

    cin >> T;

    while (T--) {
        int a, b;
        int ans;
        cin >> a >> b;
        if (level[a] < level[b]) {
            //왼쪽에 있는 변수가 level이 더 작음
            ans = lca(a, b);
        } else {
            ans = lca(b, a);
        }
        cout << ans << "\n";
    }

    return 0;
}
