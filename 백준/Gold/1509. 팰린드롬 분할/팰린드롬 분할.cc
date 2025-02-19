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

vector<char> arr;
bool dp[2502][2502];

int n;
int ans[2502];

int main() {
    fastIo();

    string s;

    cin >> s;

    n = s.size();

    //cout << n << "\n";

    arr.resize(n+1);

    for (int i = 1; i<=n;i++) {
        arr[i] = s[i-1];
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

    fill(&ans[0], &ans[2501], INF);

    ans[0] = 0;

    for (int i =1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            if (dp[j][i]) {
                if (ans[i] > ans[j-1] + 1)
                    ans[i] = ans[j-1] + 1;
            }
        }
    }

    cout << ans[n] << "\n";

    return 0;
}