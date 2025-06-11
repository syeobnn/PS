#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <ratio>

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

ll home, router;
ll ans;
vector<ll> arr;

ll func(ll mid) {
    ll base = arr[0];
    ll rt_temp = 1;

    for (ll i = 0; i < home; i++) {
        if (arr[i] - base >= mid) {
            base = arr[i];
            rt_temp++;
        }
    }

    return (rt_temp >= router) ? mid : 0;
}

int main() {
    fastIo();

    cin >> home >> router;
    arr.resize(home);

    for (ll i = 0; i < home; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll l = 1;
    ll r = arr[home - 1] - arr[0];

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (func(mid)) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}