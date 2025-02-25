#include <bits/stdc++.h>
#include <iostream>

#define MAX 1e9
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
const int ddx[] = {1, -1, 0, 0};
const int ddy[] = {0, 0, -1, 1};
const int INF = 0x3f3f3f3f;
const ll LINF = 3123372036854775807;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fastIo();

    int r, c, k;
    int flag = 0;

    cin >> r >> c >> k;

    for (int i =0;i<r;i++) {
        string a, b;
        bool valid = false, use = false;

        cin >> a >> b;

        if (a.find('-') != string::npos) {
            valid = false;
        }
        else {
            valid = true;
        }

        if (b.find('*') != string::npos) {
            use = true;
        }
        else {
            use = false;
        }

        if (valid == false && use == true) {
            flag = 1;
        }

        if (flag)
            break;
    }

    if (flag)
        cout << "N\n";
    else
        cout << "Y\n";

    return 0;
}
