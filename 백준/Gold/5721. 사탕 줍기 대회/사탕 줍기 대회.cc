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

int dpx[100010];
int dpy[100010];

int main() {
    fastIo();

    int n, m;

    while (true) {
        int mmax = 0;

        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        for (int i = 1; i <= n; i++) {
            int temp;
            for (int j = 1; j <= m; j++) {
                cin >> temp;
                if (j == 1) {
                    dpx[j] = temp;
                    continue;
                }
                dpx[j] = max(dpx[j - 1], dpx[j - 2] + temp);
            }
            dpy[i] = dpx[m];
        }

        for (int i =2;i<=n;i++) {
            dpy[i] = max(dpy[i - 1], dpy[i - 2] + dpy[i]);
        }

        cout << dpy[n] << "\n";

        memset(dpx, 0, sizeof(dpx));
        memset(dpy, 0, sizeof(dpy));
    }

    return 0;
}
