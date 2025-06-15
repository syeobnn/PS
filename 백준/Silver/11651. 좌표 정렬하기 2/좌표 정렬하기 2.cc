#include <iostream>
#include <vector>
#include <algorithm>
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

vector<pii> arr;

int main() {
    fastIo();

    int N;

    cin >> N;

    arr.resize(N);

    for (int i =0;i<N;i++) {
        cin >> arr[i].second >> arr[i].first; //first가 y, second가 x
    }

    sort(arr.begin(), arr.end());

    for (auto &[y, x] : arr) {
        cout << x << " " << y << "\n";
    }

    return 0;
}
