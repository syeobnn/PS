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


int n, m;
int parents[500010];

int ufind(int a) {
    if (parents[a] == a)
        return a;
    else
        return parents[a] = ufind(parents[a]);
}

int mkunion(int a, int b) {
    a = ufind(a); //a의 parents
    b = ufind(b); //b의 parents

    if (a > b) {
        return parents[b] = a; //a가 더 크니까 a를 b의 부모로
    }
    return parents[a] = b;
}

int main() {
    fastIo();

    cin >> n >> m;

    for (int i=0;i<n;i++) {
        parents[i] = i;
    }

    for (int i =0;i<m;i++) {
        int a, b;
        cin >> a >> b;

        if (ufind(a) == ufind(b)) {
            cout << i + 1 << "\n";
            return 0;
        }

        mkunion(a, b);
    }

    cout << 0 << "\n";

    return 0;
}
