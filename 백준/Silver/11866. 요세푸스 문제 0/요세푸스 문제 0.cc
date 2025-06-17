#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>

#define ll long long
#define pii pair<int, int>
#define MAX 1e9
#define log2 18

using namespace std;

const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int ddx[] = {1, -1, 0, 0};
const int ddy[] = {0, 0, -1, 1};
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int n, k;

vector<int> arr;
vector<int> yose_arr;

int counter(int index) {
    int cnt = k;
    while (cnt--) {
        index++;
        if (index > n)  index %= n;

        while (arr[index] == -1) {
            index++;
            if (index > n)  index %= n;
        }
    }
    return index;
}

int main() {
    fastIo();

    cin >> n >> k;

    int index = 0;
    int cnt = n;
    arr.resize(n + 1);
    arr[0] = -1;

    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }

    while (cnt--) {
        index = counter(index);

        yose_arr.push_back(arr[index]);
        arr[index] = -1;
    }

    cout << "<";
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << yose_arr[i];
            continue;
        }
        cout << yose_arr[i] << ", ";
    }

    cout << ">" << "\n";

    return 0;
}
