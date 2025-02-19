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

vector<int> arr;
bool dp[2002][2002];

int main() {
    fastIo();

    int n, q;
    cin >> n;

    arr.resize(n+1);

    for (int i = 1; i<=n;i++) {
        cin >> arr[i];
    }

    for (int i = 1; i<=n;i++) {
        dp[i][i] = true;
        if (i==n)
            continue;
        if (arr[i] == arr[i+1]) {
            dp[i][i+1] = true;
        }
    }

    for (int i =1;i<=n;i++) {
        int temp = 1;
        for (int j = i; j<=n;j++, temp++) {
            if (dp[temp + 1][j - 1] && (arr[temp] == arr[j])) {
                dp[temp][j] = true;
            }
        }
    }

    cin >> q;

    for (int i =0;i<q;i++) {
        int a, b;
        cin >> a >> b;
        if (dp[a][b])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }

    return 0;
}