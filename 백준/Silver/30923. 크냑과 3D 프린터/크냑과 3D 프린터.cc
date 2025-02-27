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

int main() {
    fastIo();

    int n;
    long long cnt = 0;

    cin >> n;

    arr.resize(n);

    for (int i =0;i<n;i++) {
        cin >> arr[i];
        cnt += arr[i];
    }

    cnt *= 2;

    cnt += n * 2;

    long long temp = 0;

    for (int i =0;i<n-1;i++) {
        int a = abs(arr[i] - arr[i+1]);
        temp += a;
    }

    cnt += temp;

    cnt += arr[0] + arr[n-1];

    cout << cnt << "\n";

    return 0;
}
