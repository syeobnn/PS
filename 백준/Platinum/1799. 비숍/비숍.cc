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

int n;
vector<int> arr[13];
int leftDiag[30];   //하강형 좌측
int rightDiag[30];  //하강형 우측
int ans[2];

void bishop(int y, int x, int count, int color) {
    if (n < x) {
        y++;
        x = (x + 1) % 2;
    }

    if (n < y) {
        ans[color] = max(ans[color], count);
        return;
    }

    if (arr[y][x] && !leftDiag[x+y] && !rightDiag[x - y + n]) {
        leftDiag[x+y] = rightDiag[x-y+n] = 1;
        bishop(y, x+2, count + 1, color);
        leftDiag[x+y] = rightDiag[x-y+n] = 0;
    }

    bishop(y, x+2, count, color);
}

int main() {
    fastIo();

    cin >> n;

    for (int i =1;i<=n;i++) {
        arr[i].resize(n+2, 0);
        for (int j =1;j<=n;j++) {
            cin >> arr[i][j];
        }
    }

    bishop(1, 1, 0, 0);
    bishop(1, 2, 0, 1);

    cout << ans[0] + ans[1] << "\n";

    return 0;
}