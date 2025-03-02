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

pii down = {1, 0};
pii up = {-1, 0};
pii left_ = {0, -1};
pii right_ = {0, 1};

pii operator +(pii a, pii b) {
    pii temp;
    temp.first = a.first + b.first;
    temp.second = a.second + b.second;
    return temp;
}

int main() {
    fastIo();

    int n;
    string s;
    char arr[11][11] = {0};

    pair<int, int> cur = {0, 0};

    cin >> n;
    cin >> s;

    fill(&arr[0][0], &arr[0][0] + 11 * 11, '.');

    for (int i = 0; i < s.size(); i++) {
        auto &[y, x] = cur;
        char ret_char;

        if (s[i] == 'U') {
            auto[ny, nx] = cur + up;
            if (ny <0 || nx <0 || ny >= n || nx >= n)
                continue;

            if (arr[y][x] == '.')
                arr[y][x] = '|';
            else if (arr[y][x] == '-')
                arr[y][x] = '+';

            if (arr[ny][nx] == '.')
                arr[ny][nx] = '|';
            else if (arr[ny][nx] == '-')
                arr[ny][nx] = '+';

            y = ny;
            x = nx;
        }
        else if (s[i] == 'D') {
            auto[ny, nx] = cur + down;
            if (ny <0 || nx <0 || ny >= n || nx >= n)
                continue;

            if (arr[y][x] == '.')
                arr[y][x] = '|';
            else if (arr[y][x] == '-')
                arr[y][x] = '+';

            if (arr[ny][nx] == '.')
                arr[ny][nx] = '|';
            else if (arr[ny][nx] == '-')
                arr[ny][nx] = '+';

            y = ny;
            x = nx;
        }
        else if (s[i] == 'L') {
            auto[ny, nx] = cur + left_;
            if (ny <0 || nx <0 || ny >= n || nx >= n)
                continue;

            if (arr[y][x] == '.')
                arr[y][x] = '-';
            else if (arr[y][x] == '|')
                arr[y][x] = '+';

            if (arr[ny][nx] == '.')
                arr[ny][nx] = '-';
            else if (arr[ny][nx] == '|')
                arr[ny][nx] = '+';

            y = ny;
            x = nx;
        }
        else if (s[i] == 'R') {
            auto[ny, nx] = cur + right_;
            if (ny <0 || nx <0 || ny >= n || nx >= n)
                continue;

            if (arr[y][x] == '.')
                arr[y][x] = '-';
            else if (arr[y][x] == '|')
                arr[y][x] = '+';

            if (arr[ny][nx] == '.')
                arr[ny][nx] = '-';
            else if (arr[ny][nx] == '|')
                arr[ny][nx] = '+';

            y = ny;
            x = nx;
        }
    }

    for (int i =0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}
