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

int N;
int arr[50001];
int sum[50001];
int dp[3][50001];
int K;

int main() {
    fastIo();

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    cin >> K;

    for (int i = 1; i <= N; i++) {
        sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = K; i <= N; i++) {
        dp[0][i] = max(dp[0][i - 1], sum[i] - sum[i - K]);
        if (i >= K * 2) {
            dp[1][i] = max(dp[1][i - 1], dp[0][i - K] + sum[i] - sum[i - K]);
        }
        if (i >= K * 3) {
            dp[2][i] = max(dp[2][i - 1], dp[1][i - K] + sum[i] - sum[i - K]);
        }
    }

    cout << dp[2][N];

    return 0;
}
