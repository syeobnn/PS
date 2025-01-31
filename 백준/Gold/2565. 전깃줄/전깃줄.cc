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

vector<pii > arr;
int dp[1010];

int main() {
    fastIo();

    int n;
    int many = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        arr.emplace_back(l, r);
    }

    sort(arr.begin(), arr.begin() + n, [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    });

    dp[0] = 1;
    for (int i =1;i<=n;i++) {
        dp[i] = 1;
        for (int j =0;j<i;j++) {
            if (arr[i].second > arr[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        many = max(many, dp[i]);
    }

    cout << n - many << "\n";

    return 0;
}
