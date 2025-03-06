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
#define log2 51

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

vector<int> arr;
vector<int> picked;
int visited[5001];
int n, k;

//pick() 고르는거
//minu() minus하는거

int pick() {
    int big = -INF;
    int idx = 0;

    for (int i = 0;i<n;i++) {
        if (big < arr[i] && !visited[i]) {
            big = arr[i];
            idx = i;
        }
    }

    visited[idx] = 1;

    picked.push_back(idx);

    return idx;
}

void minu(int idx) {
    for (int i = idx; i<n;i++) {
        arr[i]--;
    }
}

int main() {
    fastIo();

    cin >> n >> k;

    int ans = 0;

    arr.resize(n);

    for (int i =0;i<n;i++) {
        cin >> arr[i];
    }

    while (k--) {
        int idx = pick();
        minu(idx + 1);
    }

    for (auto i : picked) {
        ans += arr[i];
    }

    cout << ans << "\n";

    return 0;
}