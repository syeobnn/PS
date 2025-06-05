#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define MAX 1e9
#define log2 18

using namespace std;

const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int ddx[] = {1, -1, 0, 0};
const int ddy[] = {0, 0, -1, 1};
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int ctoi(char a) {
    if (a < 'a') return a - 'A';
    return a - 'a' + 26;
}

int main() {
    fastIo();

    int N;

    cin >> N;

    int c[110][110] = {0};
    int f[110][110] = {0};
    vector<int> graph[110];

    for (int i =0;i<N;i++) {
        char from, to;
        int capacity;

        cin >> from >> to >> capacity;
        from = ctoi(from), to = ctoi(to);
        c[from][to] = c[to][from] += capacity;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int ans = 0, S = ctoi('A'), E = ctoi('Z');

    while (1) {
        int prev[110];
        memset(prev, -1, sizeof(prev));
        queue<int> Q;
        Q.push(S);
        while (!Q.empty() && prev[E] == -1) {
            int cur = Q.front();
            Q.pop();
            for (int next : graph[cur]) {
                if (c[cur][next] - f[cur][next] > 0 && prev[next] == -1) {
                    Q.push(next);
                    prev[next] = cur;
                    if (prev[next] == prev[E])
                        break;
                }
            }
        }

        if (prev[E] == -1) break;

        int flow = INF;

        for (int i = E; i != S; i = prev[i]) {
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        }

        for (int i = E; i != S; i = prev[i]) {
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }

        ans += flow;
    }

    cout << ans << "\n";

    return 0;
}
