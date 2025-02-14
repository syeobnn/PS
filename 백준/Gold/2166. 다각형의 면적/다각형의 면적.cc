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
const int INF = 987654321;
const ll LINF = 3123372036854775807;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool comp1(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second > b.second; // 두 번째 요소는 내림차순
    }
    return a.first < b.first; // 첫 번째 요소는 오름차순
}

bool comp2(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second > b.second; // 두 번째 요소는 내림차순
    }
    return a.first > b.first; // 첫 번째 요소는 내림차순
}

bool comp3(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second < b.second; // 두 번째 요소는 오름차순
    }
    return a.first > b.first; // 첫 번째 요소는 내림차순
}

bool comp4(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second < b.second; // 두 번째 요소는 오름차순
    }
    return a.first < b.first; // 첫 번째 요소는 오름차순
}

vector<pair<int, int> > arr;

// 주어진 세 점으로 삼각형의 넓이를 계산하는 함수
long double triangleArea(long double x1, long double y1, long double x2, long double y2, long double x3, long double y3) {
    return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
}

int main() {
    fastIo();

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr.emplace_back(x, y);
    }

    long double sum = 0.0;

    for (int i = 1; i < n - 1; i++) {
        sum += triangleArea(arr[i].first, arr[i].second, arr[i + 1].first,
            arr[i + 1].second, arr[0].first, arr[0].second);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(sum);

    return 0;
}