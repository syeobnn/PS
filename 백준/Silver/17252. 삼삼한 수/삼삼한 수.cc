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

vector<long long> samsam;

void make_samsam() {
    long long temp = 1;

    while (temp < (1LL << 32)) {
        samsam.push_back(temp);
        temp *= 3;
    }
}

int main() {
    fastIo();

    long long n;

    cin >> n;

    if (n == 0) {
        cout << "NO\n";
        return 0;
    }


    make_samsam();

    for (long long i = samsam.size() - 1;i>=0;i--) {
        auto num_minus =  samsam[i];

        if (n >= num_minus)
            n -= num_minus;
    }

    if (n == 0)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
