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

int main() {
    fastIo();

    cin >> n >> k;

    int index = 0;
    arr.resize(n);

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    while (!arr.empty()) {
        index = (index + k - 1) % arr.size();
        yose_arr.push_back(arr[index]);
        arr.erase(arr.begin() + index);
    }

    cout << "<";
    for (int i = 0; i < n; i++) {
        cout << yose_arr[i] << (i < n - 1 ? ", " : "");
    }
    cout << ">" << "\n";

    return 0;
}
