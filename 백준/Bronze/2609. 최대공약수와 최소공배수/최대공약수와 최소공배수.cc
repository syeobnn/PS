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

int GCD(int a, int b){
    return b ? GCD(b, a % b) : a;
}

int a, b;

int main() {
    fastIo();

    cin >> a >> b;

    int big = max(a, b);
    int small = min(a, b);

    int gcdAns = GCD(big, small);
    int lcmAns = (a * b) / gcdAns;

    cout << gcdAns << "\n";
    cout << lcmAns << "\n";

    return 0;
}