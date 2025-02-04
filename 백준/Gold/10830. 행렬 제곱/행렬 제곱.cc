#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define pii pair<int, int>
#define MAX 1e9
#define log2 18

using namespace std;
using ll = long long;
using vvi = vector<vector <int>>;

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

long long n, b;

vvi arr;

vvi multipl2(vvi x) { //정상 작동

    vvi ret;
    ret.resize(n,vector<int> (n));

    for (int i =0;i<n;i++) {
        for (int j=0;j<n;j++) {
            for (int k=0;k<n;k++) {
                ret[i][j] += (x[i][k] * x[k][j]) % 1000;
            }
        }
    }

    return ret;
}

vvi multipl1(vvi x, vvi y) { //정상 작동

    vvi ret;
    ret.resize(n,vector<int> (n));

    for (int i =0;i<n;i++) {
        for (int j=0;j<n;j++) {
            for (int k=0;k<n;k++) {
                ret[i][j] += (x[i][k] * y[k][j]) % 1000;
            }
            ret[i][j] %= 1000;
        }
    }

    return ret;
}

int main() {
    fastIo();

    cin >> n >> b;

    arr.resize(n, vector<int> (n));

    for (int i =0;i<n;i++) {
        for (int j =0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    vvi ans = arr;

    b--;//ans에 이미 arr이 대입되어 있으니까 하나를 빼줘서 밑에서 곱할 때

    for (long long i =0;i<40;i++) {
        if (b & 1LL << i) { //1LL을 사용하지 않으면 1은 기본 타입이 int기 때문에 32bit에서 문제가 발생한다.
            vvi temp = arr;
            for (int j = 0;j<i;j++) {
                temp = multipl2(temp);
            }

            ans = multipl1(ans, temp);
        }
    }

    for (int i =0;i<n;i++) {
        for (int j =0;j<n;j++) {
            cout << ans[i][j] % 1000 << " ";
        }
        cout << "\n";
    }

    return 0;
}
