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

int find_number(vector<pair<int, char> > &arr) {
    int t = 0;
    int bignum = 0;
    pair<int, int> same[5] = {make_pair(0, 0)};
    map<int, int> poker_num;
    int two[2] = {0};
    int straight = (1 << 5) - 1;
    bool st = false;
    int ret = 0;

    for (int i = 0; i < 5; i++) {
        t += 1 << arr[i].first;
        bignum = max(bignum, arr[i].first);
        poker_num[arr[i].first]++;
    }

    //straight 판별
    for (int i = 9; i > 0; i--) {
        if ((t & (straight << i)) == (straight << i)) {
            st = true;
            ret = i + 4;
            break;
        }
    }

    if (st)
        return ret + 500;

    for (auto &[num, count]: poker_num) {
        switch (count) {
            case 4:
                same[4].first = num;
                same[4].second = 1;
            break;
            case 3:
                same[3].first = num;
                same[3].second = 1;
            break;
            case 2:
                same[2].first = max(num, same[2].first);
                two[same[2].second] = num;
                same[2].second += 1; //2, 2
            break;
            case 1:
                same[1].first = max(num, same[1].first);
                same[1].second = 1;
                break;
            default:
                break;
        }
    }

    if (same[4].second)
        return 800 + same[4].first;
    if (same[3].second) {
        int temp = 0;
        if (same[2].second) {
            temp += same[3].first * 10;
            temp += same[2].first;
            return temp + 700;
        }
        temp += same[3].first;
        return temp + 400;
    }
    if (same[2].second) {
        if (same[2].second > 1) {
            int big = max(two[0], two[1]) * 10;
            int small = min(two[0], two[1]);
            ret = big + small;
            return ret + 300;
        }
        ret = two[0];
        return ret + 200;
    }

    return 100 + bignum;
}

int find_color(vector<pair<int, char> > &arr) {
    map<char, int> m;
    int big = 0;
    for (auto &[num, col] : arr) {
        m[col]++;
        big = max(big, num);
    }
    for (auto &[col, cnt] : m) {
        if (cnt==5) {
            return 600 + big;
        }
    }

    return 0;
}

int main() {
    fastIo();

    vector<pair<int, char> > arr;
    arr.resize(5);

    for (int i = 0; i < 5; i++) {
        cin >> arr[i].second;
        cin >> arr[i].first;
    }

    sort(arr.begin(), arr.end());

    int num = find_number(arr);
    int color = find_color(arr);

    if (color && ((num / 100) == 5)) {
        cout << 900 + num % 10 << "\n";
        return 0;
    }

    int ans = max(num, color);

    cout << ans << "\n";

    return 0;
}
