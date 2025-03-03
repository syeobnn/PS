#include <bits/stdc++.h>
#include <iostream>

#define MAX (50000 + 32767)
#define MIN (50000 - 32768)
#define log2 18
#define divisor 1000000000
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
vector<pll> tree; //first = 최대, second = 최소

ll init_s(int node, int start, int end){
    if(start == end){ //리프 노드인 경우
        return tree[node].second = arr[start];
    }
    return tree[node].second = min(init_s(node*2, start, (start+end)/2) , init_s(node*2+1, (start+end)/2+1, end));
    //리프 노드가 아니면 자식들의 합 저장
}

ll init_l(int node, int start, int end){
    if(start == end){ //리프 노드인 경우
        return tree[node].first = arr[start];
    }
    return tree[node].first = max(init_l(node*2, start, (start+end)/2) , init_l(node*2+1, (start+end)/2+1, end));
    //리프 노드가 아니면 자식들의 합 저장
}

ll mMin(int node, int start, int end, int left, int right){
    if(left>end || right<start){ //겹치는 구간이 없는 경우
        return INF;
    }
    if(left<=start && end<=right){ //[left, right]가 [start, end]를 완전히 포함하는 경우
        return tree[node].second;
    }
    return min(mMin(node*2, start, (start+end)/2, left, right)
           ,mMin(node*2+1, (start+end)/2+1, end, left, right));
}

ll mMax(int node, int start, int end, int left, int right){
    if(left>end || right<start){ //겹치는 구간이 없는 경우
        return 0;
    }
    if(left<=start && end<=right){ //[left, right]가 [start, end]를 완전히 포함하는 경우
        return tree[node].first;
    }
    return max(mMax(node*2, start, (start+end)/2, left, right)
           ,mMax(node*2+1, (start+end)/2+1, end, left, right));
}

// void update(int node, int start, int end, int idx, ll diff){
//     if(idx<start || idx>end) return; //범위를 벗어남
//     tree[node] += diff; //범위에 포함된다면 diff 더함
//     if(start != end){ //리프 노드가 아니면
//         update(node*2, start, (start+end)/2, idx, diff); //왼쪽 자식도 탐색
//         update(node*2+1, (start+end)/2+1, end, idx, diff); //오른쪽 자식도 탐색
//     }
// }

int main() {
    fastIo();

    int N, M;

    cin >> N >> M;

    arr.resize(N+1);
    tree.resize(N*4);

    for (int i =1;i<=N;i++) {
        cin >> arr[i];
    }

    init_s(1, 1, N);
    init_l(1, 1, N);

    while (M--) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        cout << mMin(1, 1, N, a, b) << " " << mMax(1, 1, N, a, b)  << "\n";
    }

    return 0;
}