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

vector<pii> arr; //f에 메모리 크기, s에 비용
int value[110][10010];

int main() {
    fastIo();

    int n, m;
    int ans = INF;

    cin >> n >> m;

    arr.resize(n + 1);

    for (int i =1;i<=n;i++) {
        cin >> arr[i].first;
    }

    for (int i =1;i<=n;i++) {
        cin >> arr[i].second;
    }

    for (int i =1;i<=n;i++) {
        for (int j = 0; j<=n * 100;j++) {
            auto [cur_value, cur_cost] = arr[i];

            if (cur_cost > j) {
                value[i][j] = value[i - 1][j];
                continue;
            }

            value[i][j] = max(value[i - 1][j], value[i-1][j - cur_cost] + cur_value);
        }
    }

    for (int i =1;i<=n;i++) {
        for (int j = 0; j<=n * 100;j++) {
            if (value[i][j] >= m) {
                ans = min(ans, j);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
