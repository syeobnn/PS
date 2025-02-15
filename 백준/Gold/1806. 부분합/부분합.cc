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

vector<ll> arr;
int n, k;

int main() {
    fastIo();

    cin >> n >> k;

    ll l =0, r =0, sum =0, ans = INF;

    arr.resize(n);

    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    while (l <= r) {
        if (sum >= k) {
            ans = min(ans, r - l);
            sum -= arr[l++];
        }
        else if (r == n) {
            break;
        }
        else {
            sum += arr[r++];
        }
    }

    if (ans == INF)
        cout << 0 << "\n";
    else
        cout << ans;

    return 0;
}