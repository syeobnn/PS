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
ll dp[510][510];

ll multi(int s, int m, int e) {
    return arr[s] * arr[m] * arr[e];
}

int main() {
    fastIo();

    fill(&dp[0][0], &dp[0][0] + 510 * 510, LINF);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back(a);
        if (i == n - 1)
            arr.push_back(b);
    }

    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    for (int i = 1; i < n; i++) {
        for (int dx = 0; dx + i < n; dx++) {
            int dy = dx + i; //떨어진 거리만큼

            for (int mid = dx; mid < dy; mid++) {
                dp[dx][dy] = min(dp[dx][dy],
                    dp[dx][mid] + dp[mid + 1][dy] + multi(dx, mid + 1, dy + 1));
                //dp가 행렬 순서를 뜻하기 때문에 dp[1][2]는 1번행렬 * 2번행렬을 계산한 값이다.
                //나는 1차원 배열에 저장했기 때문에 0,1(index)이 1번 행렬 1,2가 2번 행렬이 된다.
                //그래서 dx와 mid값이 같아질 수 있기 때문에 mid + 1을 했고
                //dy+1이 dy번째 행렬의 열의 크기이기 때문에 dy+1을 해줬다.
                //근데 내가 행렬을 그대로 저장한 게 아니라 1차원 배열에 저장해놓고 값을 사용하기 때문에 직관적이지 않은듯
            }
        }
    }

    cout << dp[0][n-1];

    return 0;
}
