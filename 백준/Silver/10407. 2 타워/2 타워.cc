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

int main() {
    fastIo();

    string s;

    cin >> s;

    int a = s[s.size() - 1] - '0';

    if (a == 1 && s.size() == 1)
        cout << 2 << "\n";
    else
        cout << 1 << "\n";

    return 0;
}
