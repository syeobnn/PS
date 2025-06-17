#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>

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

ll n, k;

bool func(ll mid) {
    ll cnt = 0;
    for (int i = 1; i<=n;i++) {
        cnt += min(n, mid/i);
    }

    return cnt >= k;
}

int main() {
    fastIo();

    cin >> n >> k;

    ll l = 0, r = n * n, ans = INF;

    while (l <= r) {
        ll mid = (l + r + 1) / 2;
        if (func(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}