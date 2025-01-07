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
#define MAX 1500051

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
int d, v;
int dp[MAX];
int arr[MAX][2];

int main() {
    fastIo();

    cin >> N;

    for(int i =1;i<=N;i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i = 1;i<=N+1;i++){
        dp[i] = max(dp[i], dp[i - 1]);
        dp[arr[i][0] + i] = max(dp[i] + arr[i][1], dp[arr[i][0] + i]);
    }

    cout << dp[N+1];

    return 0;
}
