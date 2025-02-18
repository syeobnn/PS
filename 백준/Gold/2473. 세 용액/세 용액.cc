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
const int INF = 0x3f3f3f3f;
const ll LINF = 3123372036854775807;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int n;
vector<ll> arr;

int main() {
    fastIo();

    cin >> n;
    arr.resize(n);

    for (int i =0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll sum = LINF;
    int l, m, r;
    int flag =0;

    for (int i =0;i<n-2;i++) {
        for (int j =n-1;j>0;j--) {
            int left = i + 1, right = j - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                ll temp = arr[i] + arr[j] + arr[mid];

                if (temp > 0) {
                    right = mid - 1;
                    if (abs(temp) < sum) {
                        sum = abs(temp);
                        l = arr[i]; m = arr[mid]; r = arr[j];
                    }
                }
                else if (temp < 0) {
                    left = mid + 1;
                    if (abs(temp) < sum) {
                        sum = abs(temp);
                        l = arr[i]; m = arr[mid]; r = arr[j];
                    }
                }
                else {
                    flag = 1;
                    l = arr[i]; m = arr[mid]; r = arr[j];
                    if (flag)
                        break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            break;
    }

    cout << l << " " << m << " " << r << "\n";

    return 0;
}