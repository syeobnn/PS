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

vector<int> arr;

int main() {
    fastIo();

    int n, k;

    cin >> n >> k;

    for (int i =1;i<=n;i++) {
        if (!(n%i)) {
            arr.push_back(i);
        }
    }

    if (arr.size()<k) {
        cout << 0 << "\n";
    }
    else {
        cout << arr[k-1] << "\n";
    }

    return 0;
}
