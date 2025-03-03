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

long long N, K;
int parents[log2 + 1][1000001];
int arr[1000001];
int shuffle_[1000001];
int ans[1000001];

int main() {
    fastIo();

    cin >> N >> K;//N은 개수, K는 셔플 수

    for (int i = 1;i <=N;i++) {
        cin >> arr[i];
    }

    for (int i = 1;i<=N;i++) {
        cin >> shuffle_[i];
    }

    for (int i = 1;i<=N;i++) {
        parents[0][shuffle_[i]] = i;
    }

    for (int i = 1;i<=log2;i++) {
        for (int j = 1;j<=N;j++) {
            int temp = parents[i-1][j];
            parents[i][j] = parents[i-1][temp];
        }
    }

    for (int i = 1;i<=N;i++) {
        int a = i;
        for (int j = 0;j<log2;j++) {
            if ( K & (1LL << j)) {
                a = parents[j][a];
            }
        }
        ans[i] = arr[a];
    }

    for (int i=1;i<=N;i++) {
        cout << ans[i] << " ";
    }

    cout << "\n";

    return 0;
}