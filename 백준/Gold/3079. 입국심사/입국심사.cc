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

ll n, m;
ll arr[100001];

ll f(ll x) {
    ll output = 0;
    for (int i = 1; i <= n; i++) {
        ll tmp = x / arr[i];
        output += tmp;
        if(output > MAX)
            break;
    }
    return output;
}


signed main() {
    fastIo();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    ll left = 0, right = MAX * MAX, ret;
    while (left <= right) {
        ll mid = left + right >> 1;
        ll namu = f(mid);
        if (namu >= m) {
            ret = mid;
            right = mid - 1;
        } else if (namu < m) {
            left = mid + 1;
        }
    }

    cout << ret;

    return 0;
}
