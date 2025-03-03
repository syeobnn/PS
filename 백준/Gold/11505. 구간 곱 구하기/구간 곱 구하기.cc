#include <bits/stdc++.h>
#include <iostream>

#define MAX (50000 + 32767)
#define MIN (50000 - 32768)
#define log2 18
#define divisor 1000000007
#define multiplier 31

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll> >;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int ddx[] = {0, 0, 1, -1, 0, 0};
const int ddy[] = {0, 0, 0, 0, -1, 1};
const int ddz[] = {1, -1, 0, 0, 0, 0};
const int INF = 0x3f3f3f3f;
const ll LINF = 3123372036854775807;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vll arr;
vll tree;

ll init(int node, int start, int end) {
    if (start == end) {
        //리프 노드인 경우
        return tree[node] = arr[start];
    }
    return tree[node] = (init(node * 2, start, (start + end) / 2) % divisor) * (init(node * 2 + 1,
                                (start + end) / 2 + 1, end) % divisor) % divisor;
    //리프 노드가 아니면 자식들의 합 저장
}

ll mul(int node, int start, int end, int left, ll right) {
    if (left > end || right < start) {
        //겹치는 구간이 없는 경우
        return 1;
    }
    if (left <= start && end <= right) {
        //[left, right]가 [start, end]를 완전히 포함하는 경우
        return tree[node];
    }
    return ((mul(node * 2, start, (start + end) / 2, left, right) % divisor)
            * (mul(node * 2 + 1, (start + end) / 2 + 1, end, left, right) % divisor) % divisor);
    //[start, end]가 [left, right]를 완전히 포함하거나
    //두 구간이 겹쳐 있는 경우
    //왼쪽 서브 트리와 오른쪽 서브 트리에서 다시 탐색 시작
}

void update(int node, int start, int end, int idx, ll diff) {
    if (idx < start || idx > end) return; //범위를 벗어남
    if (start == end) {
        tree[node] = diff;
        return;
    }
    update(node * 2, start, (start + end) / 2, idx, diff); //왼쪽 자식도 탐색
    update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff); //오른쪽 자식도 탐색
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % divisor;
}

int main() {
    fastIo();

    int N, M, K;

    cin >> N >> M >> K;

    arr.resize(N + 1);
    tree.resize(N * 4);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    init(1, 1, N);

    for (int i = 0; i < M + K; i++) {
        int a, s;
        ll e;
        cin >> a >> s >> e;
        if (a == 1) {
            //구간 업데이트
            update(1, 1, N, s, e);
            arr[s] = e;
        } else if (a == 2) {
            //구간 곱
            cout << mul(1, 1, N, s, e) << "\n";
        }
    }

    return 0;
}
