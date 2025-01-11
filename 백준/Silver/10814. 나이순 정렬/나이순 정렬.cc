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

struct old_name {
    int old;
    string name;
    int index;
};

bool compare_old(const old_name& a, const old_name& b) {
    if (a.old == b.old)
        return a.index < b.index;
    return a.old < b.old;
}

int N, T;
vector<old_name> arr;

int main() {
    fastIo();

    cin >> N;

    arr.resize(N);

    for (int i =0;i<N;i++) {
        cin >> arr[i].old >> arr[i].name;
        arr[i].index = i;
    }

    sort(arr.begin(), arr.begin()+N, compare_old);

    for (int i =0;i<N;i++) {
        cout << arr[i].old << " " << arr[i].name << "\n";
    }

    return 0;
}
