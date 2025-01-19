#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define ll long long
using namespace std;

const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int INF = 2046483647;
const ll LINF = 9123372035854775807;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<pair<int, int>> arr(101);

int dp[101][100001];

int main() {
    fastIo();

    int N, K;

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        int w, v;
        cin >> w >> v;
        arr[i].first = w;
        arr[i].second = v;
    }

    //first = weight, second = value;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j >= arr[i].first)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].first] + arr[i].second);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][K];

    return 0;
}