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
#define log2 18

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

int arr[22];
int dp[1000010] = {1, 1};

int main() {
    fastIo();

    //원래는 %2를 해서 2롤 나눠지는 횟수 만큼

    int n;

    cin >> n;

    for (int i = 2;i<=n;i++) {
        dp[i] += (dp[i - 2] + dp[i/2]);
        dp[i] %= 1000000000;
    }

    cout << dp[n];

    return 0;
}
