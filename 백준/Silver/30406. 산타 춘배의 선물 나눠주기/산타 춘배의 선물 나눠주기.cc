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

int n;
int arr[4] = {0};

int func(int a, int b) {
    // a > b
    if (arr[a] == 0 || arr[b] == 0)
        return 0;

    int temp = 0;

    while (arr[a] != 0 && arr[b] != 0 ) {
        arr[a]--;
        arr[b]--;
        temp++;
    }

    return temp;
}

int main() {
    fastIo();

    int cnt = 0;
    cin >> n;

    for (int i=0;i<n;i++) {
        int a;
        cin >> a;
        arr[a]++;
    }

    cnt += func(3, 0) * 3;
    cnt += func(1, 2) * 3;
    cnt += func(2, 0) * 2;
    cnt += func(1, 3) * 2;
    cnt += func(1, 0);
    cnt += func(2, 3);

    cout << cnt << "\n";

    return 0;
}
