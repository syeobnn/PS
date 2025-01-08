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

vector<pii> arr;

int main() {
    fastIo();

    int N;

    cin >> N;
    arr.resize(N);

    for(int i =0;i<N;i++){
        int a, b;
        cin >> a >> b;
        arr[i].first = a;
        arr[i].second = b;
    }

    sort(arr.begin(), arr.begin()+N);

    for(int i =0;i<N;i++){
        cout << arr[i].first << " " << arr[i].second << "\n";
    }

    return 0;
}