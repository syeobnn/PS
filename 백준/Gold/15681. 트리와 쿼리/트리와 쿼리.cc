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

int N, R, T;
vector<int> arr[100001];
int visited[100001];
int sumArr[100001];

int dfs(int node) {
    int sum = 1;
    visited[node] = 1;

    sort(arr[node].begin(), arr[node].end());

    for (int child: arr[node]) {
        if (!visited[child]) {
            sum += dfs(child); // 왼쪽, 오른쪽 서브트리 순회
        }
    }

    sumArr[node] = sum;

    return sum;
}

int main() {
    fastIo();

    cin >> N >> R >> T;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(R);

    while (T--) {
        int a;
        cin >> a;
        cout << sumArr[a] << "\n";
    }

    return 0;
}