#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>

#define ll long long
#define pii pair<int, int>
#define MAX 1e9
#define log2 18

using namespace std;

const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int ddx[] = {1, -1, 0, 0};
const int ddy[] = {0, 0, -1, 1};
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int n, m;
char arr[32][32];
int ans;
set<char> check_alpha;
bool check_arr[26];

void dfs(int cury, int curx, int depth) {

    ans = max(ans, depth);

    for (int i = 0; i < 4; i++) {
        int nx = curx + ddx[i];
        int ny = cury + ddy[i];
        int next_alpha = arr[ny][nx] - 'A';

        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !check_arr[next_alpha]) {
            check_arr[next_alpha] = true;
            dfs(ny, nx, depth + 1);
            check_arr[next_alpha] = false;
        }
    }
}

int main() {
    fastIo();

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    check_arr[arr[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << ans << "\n";

    return 0;
}
