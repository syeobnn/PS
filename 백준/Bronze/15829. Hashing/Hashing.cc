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
const int INF = 987654321;
const ll LINF = 3123372036854775807;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fastIo();

    int n;
    string a;
    ll b = 0;
    ll sum = 0;

    cin >> n;
    cin >> a;

    for (int i=0;i<n;i++) {
        ll num = a[i]- 'a' + 1;
        for (int j=0;j<i;j++) {
            num *= multiplier;
            num %= divisor;
        }
        sum += num;
        sum %= divisor;
    }

    cout << sum << "\n";

    return 0;
}
