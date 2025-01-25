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

int arr[510][510];
int dp[510][510];

int main() {
    fastIo();

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (i == 1) {
                dp[i][j] = arr[i][j];
                continue;
            }
            dp[i][j] = 50000000;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                if (k == j)
                    continue;
                dp[i + 1][j] = min(dp[i][k] + arr[i + 1][j], dp[i + 1][j]);
            }
        }
    }

    int ans = 5000000;

    for (int i = 1; i <= m; i++) {
        ans = min(dp[n][i], ans);
    }

    cout << ans << "\n";

    return 0;
}
