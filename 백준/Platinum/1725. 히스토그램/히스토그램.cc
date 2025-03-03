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
vll tree;
int N;
ll ans;

ll init(int node, int start, int end){
    if(start == end){ //리프 노드인 경우
        return tree[node] = start;
    }
    int mid = (start + end) / 2;

    ll l_i = init(node*2, start, mid);
    ll r_i = init(node*2 + 1, mid + 1, end);

    if (arr[l_i] < arr[r_i])
        return tree[node] = l_i;
    else
        return tree[node] = r_i;
}

ll find_i(int node, int start, int end, int left, int right){
    if(left>end || right<start){ //겹치는 구간이 없는 경우
        return -1;
    }

    if(left<=start && end<=right){ //[left, right]가 [start, end]를 완전히 포함하는 경우
        return tree[node];
    }

    int mid = (start+end) /2 ;
    int idx1 = find_i(node * 2, start, mid, left, right);
    int idx2 = find_i(node * 2 + 1, mid + 1, end, left, right);

    if(idx1 == -1) return idx2;
    if(idx2 == -1) return idx1;
    return (arr[idx1] <= arr[idx2]) ? idx1 : idx2;
}

void div_con(ll l, ll r) {

    if (l > r)
        return;

    ll idx = find_i(1, 1, N, l, r);

    ans = max(ans, (r-l+1) * arr[idx]);

    div_con(l, idx -1);
    div_con(idx+1, r);;
}

int main() {
    fastIo();

    cin >> N;

    arr.resize(N+1);
    tree.resize(N*4);

    for (int i =1;i<=N;i++) {
        cin >> arr[i];
    }

    init(1, 1, N);
    div_con(1, N);

    cout << ans << "\n";

    return 0;
}