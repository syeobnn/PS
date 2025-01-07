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
#define MAX 100001

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

int N;
int dpb[3];
int dps[3];
int arr[3];

int main() {
    fastIo();

    cin >> N;
    int ansb = 0;
    int anss = MAX * 10;
    int tab = 0, tbb = 0, tcb = 0;
    int tas = 0, tbs = 0, tcs = 0;

    for (int i = 1; i <= N; i++) {

        int a, b, c;

        cin >> a >> b >> c;

        dpb[0] = a + max(tab, tbb);
        dps[0] = a + min(tas, tbs);

        dps[1] = b + min(tas, min(tbs, tcs));
        dpb[1] = b + max(tab, max(tbb, tcb));

        dpb[2] = c + max(tcb, tbb);
        dps[2] = c + min(tcs, tbs);

        tab = dpb[0];
        tbb = dpb[1];
        tcb = dpb[2];
        tas = dps[0];
        tbs = dps[1];
        tcs = dps[2];
    }

    for (int i = 0; i < 3; i++) {
        if (ansb < dpb[i]) {
            ansb = dpb[i];
        }
        if (anss > dps[i]) {
            anss = dps[i];
        }
    }

    cout << ansb << " " << anss;

    return 0;
}
