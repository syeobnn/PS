#include <bits/stdc++.h>
#include <iostream>

#define MAX 1e9
#define log2 18
#define divisor 1000000000
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

long long dp[10][101][1<<10];

int main() {
    fastIo();

    long long n, ans = 0;

    cin >> n;

    for (int i =1;i<=9;i++) {
        dp[i][1][1<<i] = 1;
    }

    if (n < 10) {
        cout << 0 << "\n";
        return 0;
    }

    for (int i =2;i<=n;i++) {
        for (int j = 0; j<=9;j++) {
            for (int index = 0; index < (1 << 10); index++) {
                if (j)
                    dp[j][i][index | (1 << j)] += dp[j-1][i-1][index];
                dp[j][i][index | (1 << j)] %= divisor;
                if (j<9)
                    dp[j][i][index | (1 << j)] += dp[j+1][i-1][index];
                dp[j][i][index | (1 << j)] %= divisor;
            }
        }
    }

    for (int i =0;i<=9;i++) {
        ans += dp[i][n][(1<<10) - 1] % divisor;
    }

    cout << ans % divisor << "\n";

    return 0;
}