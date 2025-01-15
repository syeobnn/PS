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
#define log2 20

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
vector<pii > tree[100001];
vector<pii > arr[100001];
int parents[log2 + 1][100001];
int maxLen[log2 + 1][100001];
int minLen[log2 + 1][100001];
int level[100001];
int minAns, maxAns;
int temp;
//int arr[21][200001];

void mk_tree(int cur, int par, int lv, int cost) {
    level[cur] = lv;
    parents[0][cur] = par;
    maxLen[0][cur] = cost;
    minLen[0][cur] = cost;

    for (auto i: arr[cur]) {
        if (i.first == par)continue;
        tree[cur].emplace_back(i);
        mk_tree(i.first, cur, lv + 1, i.second);
    }
}

int new_min(int a, int b) {
    if (!min(a, b)) {
        //min값이 0이면 되도록 0이 아닌 값을 반환하도록
        return max(a, b);
    }
    return min(a, b);
}

int func_query(int n, int x) {
    int ans = x;

    for (int i = 0; i < log2; i++) {
        if (n & (1 << i))
            ans = arr[i][ans].first;
    }

    return ans;
}

int lca(int a, int b) {
    //level[a] < level[b];
    minAns = 10000000;
    maxAns = -1;
    int ans = 0;
    int idx_l = level[b] - level[a];

    for (int i = 0; i < log2; i++) {
        if (idx_l & (1 << i)) {
            b = parents[i][b];
        }
    }

    for (int i = log2; i >= 0; i--) {
        if (parents[i][b] == parents[i][a]) continue;
        a = parents[i][a];
        b = parents[i][b];
    }

    if (a == b) //높이를 맞췄더니 a가 parents여서 바로 되는 경우
        return a;

    return parents[0][a]; //a가 parents가 아니라 한칸 아래에서 멈춘 경우
}

int main() {
    fastIo();

    /*하나의 정점에서 시작하는 minimum spanning tree가 주어짐
     *하나의 정점에서 시작해서 다른 node들 까지의 거리를 저장
     *최소 공통 조상을 찾아서 찾는 node들에 있는 거리를 더하고 공통조상노드의 거리 2번을 빼면 될 것 같은데
    */
    int p;

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].emplace_back(b, c);
        arr[b].emplace_back(a, c);
        p = a;
    }

    mk_tree(p, p, 1, 0);

    for (int i = 0; i < log2; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp = parents[i][j];
            parents[i + 1][j] = parents[i][tmp];
            maxLen[i + 1][j] = max(maxLen[i][j], maxLen[i][tmp]);
            minLen[i + 1][j] = new_min(minLen[i][j], minLen[i][tmp]);
        }
    }

    cin >> T;

    while (T--) {
        int a, b;
        int node;
        int idx_a, idx_b;
        int mmin = 1000000, mmax = -1;
        cin >> a >> b;
        if (level[a] < level[b]) {
            //왼쪽에 있는 변수가 level이 더 작음
            node = lca(a, b);
        } else {
            node = lca(b, a);
        }

        idx_a = level[a] - level[node];
        for (int i = 0; i < log2; i++) {
            if (idx_a == 0) continue;
            if (idx_a & (1 << i)) {
                mmin = new_min(mmin, minLen[i][a]);
                mmax = max(mmax, maxLen[i][a]);
                a = parents[i][a];
            }
        }

        idx_b = level[b] - level[node];
        for (int i = 0; i < log2; i++) {
            if (idx_b == 0) continue;
            if (idx_b & (1 << i)) {
                mmin = new_min(mmin, minLen[i][b]);
                mmax = max(mmax, maxLen[i][b]);
                b = parents[i][b];
            }
        }

        cout << mmin << " " << mmax << "\n";
    }

    return 0;
}
