#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define ll long long
#define pii pair<int, int>
#define MAX 1e9

using namespace std;

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

int N, M;
vector<int> arr;

int divBead(int maxSum) {
    int groupCount = 1, intervalMin = arr[0], intervalMax = arr[0];
    for (auto i: arr) {
        intervalMin = min(intervalMin, i);
        intervalMax = max(intervalMax, i);
        if (intervalMax - intervalMin > maxSum) {
            groupCount++;
            intervalMin = i;
            intervalMax = i;
            if (groupCount > M)
                return 0;
        }
    }
    return 1;
}

int main() {
    fastIo();

    cin >> N >> M;
    arr.resize(N);
    int low = 0, high = 0;
    int sum;
    int lin;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        low = min(low, arr[i]);
        high = max(high, arr[i]);
    }

    sum = high - low;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (divBead(mid)) {
            sum = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << sum << '\n';

    return 0;
}