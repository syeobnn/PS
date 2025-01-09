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

int N, T;

vector<int> arr[50001];
vector<int> tree[50001];
int parents[50001];
int level[50001];

void mktree(int par, int cur){
    parents[cur] = par;
    level[cur] = level[par] + 1;
    for(auto child : arr[cur]){
        if(child == par) continue;
        //여기다 parents 코드를 집어넣으면 가장 끝단의 child들은 child node가 없어서 이 코드 못막음
        tree[cur].push_back(child);
        mktree(cur, child);
    }
}

int lca(int a, int b){

    while(level[a] != level[b]){
        if(level[a] > level[b]){
            a = parents[a];
        }
        else{
            b = parents[b];
        }
    }

    while(a != b){
        a = parents[a];
        b = parents[b];
    }

    return a;
}

int main() {
    fastIo();

    cin >> N;

    parents[1] = 1;

    for(int i =0;i<N - 1;i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    mktree(1, 1);

    cin >> T;

    while(T--){
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    return 0;
}
