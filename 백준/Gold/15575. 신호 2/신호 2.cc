#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>

#define ll long long
#define pii pair<int, int>
#define MAX 1e9
#define log2 18

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

double dp[1000010][2];
vector<pii > arr;
vector<long long> cor;
map<long long, int> arm;
vector<long long> arrc[1000010];
vector<long long> hi;
long long temp;

int main() {
    fastIo();

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        arr.emplace_back(a, b);
        hi.push_back(a);
    }

    sort(arr.begin(), arr.end());
    sort(hi.begin(), hi.end());
    hi.erase(unique(hi.begin(), hi.end()), hi.end());

    int ccnt = 0;

    for (int i = 0; i < hi.size(); i++) {
        for (int j = ccnt; j < 1000010; j++, ccnt = j) {
            if (arr[j].first != hi[i]) {
                break;
            }
            arrc[i].push_back(arr[j].second);
        }
        sort(arrc[i].begin(), arrc[i].end());
    }

    temp = 0; //x좌표 구하기
    long long templ = 0;
    long long tempr = 0; //l은 x중에서 가장 작은 y, r은 x중에서 가장 큰 y

    for (int i = 0; i < hi.size(); i++) {
        if (i == 0) {
            temp = hi[i];
            templ = arrc[0][0];
            tempr = arrc[0][arrc[0].size() - 1];
            continue;
        }

        long long mmax1 = 0;
        long long mmax2 = 0;

        long long x = abs(hi[i] - temp);

        long long y = abs(arrc[i][0] - templ);
        mmax1 = max(mmax1, x * x + y * y);
        y = abs(arrc[i][0] - tempr);
        mmax2 = max(mmax2, x * x + y * y);

        dp[i][0] = max(dp[i-1][0] + sqrt(mmax1), dp[i-1][1]+ sqrt(mmax2));

        mmax1 = 0, mmax2 = 0;

        y = abs(arrc[i][arrc[i].size() - 1] - templ);
        mmax1 = max(mmax1, x * x + y * y);
        y = abs(arrc[i][arrc[i].size() - 1] - tempr);
        mmax2 = max(mmax2, x * x + y * y);

        dp[i][1] = max(dp[i-1][0] + sqrt(mmax1), dp[i-1][1]+ sqrt(mmax2));

        temp = hi[i];
        templ = arrc[i][0];
        tempr = arrc[i][arrc[i].size() - 1];
    }

    cout << fixed;
    cout.precision(7);
    cout << max(dp[hi.size() - 1][0], dp[hi.size() - 1][1]) << "\n";

    return 0;
}
