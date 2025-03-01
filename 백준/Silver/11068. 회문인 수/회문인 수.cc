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

bool find_hwae(vector<int> arr) {

    int start = 0, end = arr.size() - 1;

    while (start <= end) {

        if (arr[start] != arr[end]) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int main() {
    fastIo();

    int T;

    cin >> T;

    while (T--) {

        int n;
        bool flag = false;
        cin >> n;

        for (int i = 2; i <= 64; i++) {
            vector<int> arr;
            int temp = n;

            for (int j = 0; temp != 0; j++) {
                arr.push_back(temp % i);
                temp /= i;
            }

            flag = find_hwae(arr);

            if (flag)
                break;
        }

        if (flag)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }

    return 0;
}
