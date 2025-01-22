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
#define log2 31

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

int N, T, K, M;
vector<pii > tree[100001];
vector<pii > arr[100001];
int parents[log2 + 1][100001];
int student[100001];
int temp;

int new_min(int a, int b) {
    if (!min(a, b)) {
        //min값이 0이면 되도록 0이 아닌 값을 반환하도록
        return max(a, b);
    }
    return min(a, b);
}

int func_query(int n, int x) {
    int ans = x;

    for (int i = 0; i < log2; i++) {
        if (n & (1 << i))
            ans = arr[i][ans].first;
    }

    return ans;
}

int main() {
    fastIo();

    int p;

    //각 학생마다 M번만큼 사이클을 돈다
    cin >> N >> K >> M; //N은 학생, K는 동영상, M은 남은 수업시간

    for (int i = 1;i <=N;i++) {
        cin >> student[i];
    }

    for (int i = 1;i<=K;i++) {
        cin >> parents[0][i];
    }

    for (int i = 1;i<=log2;i++) {
        for (int j = 1;j<=K;j++) {
            int temp = parents[i-1][j];
            parents[i][j] = parents[i-1][temp];
        }
    }

    for (int i = 1;i<=N;i++) {
        int a = student[i];
        for (int j = 0;j<log2;j++) {
            if ((M-1) & (1 << j)) {
                a = parents[j][a];
            }
        }
        cout << a << " ";
    }

    return 0;
}