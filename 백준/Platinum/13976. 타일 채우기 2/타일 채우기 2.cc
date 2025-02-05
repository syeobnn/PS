#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define MAX 1e9
#define log2 18
#define divisor 1000000007

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector <ll>>;
using pii = pair<int, int>;

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

vvl operator * (vvl &a, vvl &b) {
    vvl ret;
    ret.resize(2,vl(2));

    for (int i =0;i<2;i++) {
        for (int j=0;j<2;j++) {
            for (int k = 0;k<2;k++) {
                ret[i][j] += a[i][k] * b[k][j] % divisor;
                ret[i][j] = (ret[i][j] + divisor) % divisor; //음수 처리
            }
        }
    }

    return ret;
}

vl operator * (vvl &a, vl &b) {
    vl ret;
    ret.resize(2,static_cast<ll>(0));

    for (int i =0;i<2;i++) {
        for (int j=0;j<2;j++) {
            ret[i] += a[i][j] * b[j] % divisor;
            ret[i] = (ret[i] + divisor) % divisor; //음수 처리
        }
    }

    return ret;
}

int main() {
    fastIo();

    ll n;

    cin >> n;

    vvl arr = {{4, -1}, {1, 0}};
    vl to_ans = {3, 1};//열이 하나인 행렬, 연산자 오버로딩하면 여기서 문제가 되는줄
    vvl initial = {{1,0},{0,1}};

    if (n&1) {
        cout << 0 << "\n";
    }
    else {
        n = n >> 1;
        n--;
        while (n) {
            if (n & 1) { //1은 0000 0000 ... 0001 이므로 작동함
                initial = initial * arr;//오버라이딩
            }
            arr = arr * arr;
            n = n >> 1;
        }
        auto ans = initial * to_ans;
        cout << ans[0] << "\n";
    }

    return 0;
}
