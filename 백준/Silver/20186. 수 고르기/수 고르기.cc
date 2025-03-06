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

priority_queue<int> pq;
int visited[5001];
int n, k;

int main() {
    fastIo();

    cin >> n >> k;

    int ans = 0;
    int num = k;

    for (int i =0;i<n;i++) {
        int a; cin >> a;
        pq.push(a);
    }

    while (k--) {
        ans += pq.top(); pq.pop();
    }

    cout << ans - num*(num-1)/2 << "\n";

    return 0;
}