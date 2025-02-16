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
#define divisor 1234567891
#define multiplier 31

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
const int INF = 0x3f3f3f3f;
const ll LINF = 3123372036854775807;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int n;
int arr[1010][3];
int dp[1010][3];
int dp0[1010];
int dp1[1010];
int dp2[1010];

int mkdp(int index, int cur, int diff) {//index는 다음 숫자
    if (index == n - 1)
        return cur;
    int a = dp0[index] + arr[index + 1][(cur + 1) % 3];
    int b = dp0[index] + arr[index + 1][(cur + 2) % 3];
    if (a > b) {
        dp0[index] = b;
        mkdp(index + 1, (cur + 2) % 3, diff);
    }
    else if (a == b) {
        dp0[index] = b;
        mkdp(index + 1, (cur + 2) % 3, diff);
        mkdp(index + 1, (cur + 1) % 3, diff);
    }
    else {
        dp0[index] = a;
        mkdp(index + 1, (cur + 1) % 3, diff);
    }
}

int main() {
    fastIo();

    cin >> n;

    //fill(&dp[0][0], &dp[1009][3], INF);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = INF;

    for (int i = 0;i<3;i++) {//색깔 선택
        fill(&dp[0][0], &dp[1009][3], INF);
        for (int j =0;j<3;j++) {
            if (j == i) {
                dp[1][j] = arr[1][j];
            }
        }

        for (int j = 1;j<n;j++) {
            dp[j+1][0] = min(dp[j][2] + arr[j+1][0], dp[j][1] + arr[j+1][0]);
            dp[j+1][1] = min(dp[j][2] + arr[j+1][1], dp[j][0] + arr[j+1][1]);
            dp[j+1][2] = min(dp[j][0] + arr[j+1][2], dp[j][1] + arr[j+1][2]);
        }

        for (int j =0;j<3;j++) {
            if (j == i) continue;
            ans = min(ans, dp[n][j]);
        }
    }

    cout << ans << "\n";

    return 0;
}