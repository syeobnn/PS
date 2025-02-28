#include <bits/stdc++.h>
#include <iostream>

#define MAX (50000 + 32767)
#define MIN (50000 - 32768)
#define log2 18
#define divisor 1000000000
#define multiplier 31

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll> >;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int ddx[] = {0, 0, 1, -1, 0, 0};
const int ddy[] = {0, 0, 0, 0, -1, 1};
const int ddz[] = {1, -1, 0, 0, 0, 0};
const int INF = 0x3f3f3f3f;
const ll LINF = 3123372036854775807;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

char arr[52][52][52] = {0};
queue<tuple<int, int, int> > q;
int n;

void bfs(int z, int y, int x) {
    q.push(make_tuple(z, y, x));

    arr[z][y][x] = '0';
    char stop = z + '0';

    while (!q.empty()) {
        auto [curz, cury, curx] = q.front();
        q.pop();

        if (arr[curz][cury][curx] == stop)
            continue;

        for (int i = 0; i < 6; i++) {
            int nxtx = curx + ddx[i];
            int nxty = cury + ddy[i];
            int nxtz = curz + ddz[i];

            if (nxtx < 0 || nxtx >= 2*z + 1 ||
                nxty < 0 || nxty >= 2*z + 1 ||
                nxtz < 0 || nxtz >= 2*z + 1)
                continue;

            if (arr[nxtz][nxty][nxtx] == '.') {
                q.push(make_tuple(nxtz, nxty, nxtx));
                arr[nxtz][nxty][nxtx] = arr[curz][cury][curx] + 1;
            }
        }
    }
}

int main() {
    fastIo();

    cin >> n;

    for (int t = 1; t <= n; t++) {
        int temp;

        cin >> temp;

        fill(&arr[0][0][0], &arr[0][0][0] + 52*52*52, '.');

        bfs(temp, temp, temp);

        cout << "Scenario #" << t << ":\n";

        for (int i = 0; i < temp * 2 + 1; i++) {
            cout << "slice #" << i + 1 << ":\n";
            for (int j = 0; j < temp * 2 + 1; j++) {
                for (int k = 0; k < temp * 2 + 1; k++) {
                    cout << arr[i][j][k];
                }
                cout << "\n";
            }
        }

        cout << "\n";
    }

    return 0;
}
