#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

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

int N;
vector<ll> arr;

bool func(ll mid) {
    ll l_max = -INF;
    ll r_min = INF;

    for (ll i =0;i<N;i++) {
        ll temp = mid / arr[i];
        ll t_l = i - temp;
        ll t_r = i + temp;
        l_max = max(l_max, t_l);
        r_min = min(r_min, t_r);
        if (l_max>r_min) return false;
    }

    return l_max <= r_min;
}

int main() {
    fastIo();

    cin >> N;
    arr.resize(N+1);
    ll bbig = 0;

    for (int i=0;i<N;i++) {
        cin >> arr[i];
        bbig = max(arr[i], bbig);
    }

    ll l = 0;
    ll r = bbig * N;
    ll ans = r;

    while (l <= r) {
        ll mid = l + r >> 1;
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