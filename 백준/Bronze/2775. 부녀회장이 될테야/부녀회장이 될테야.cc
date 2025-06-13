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

int T, n, k;

int main() {
    fastIo();

    cin >> T;

    while (T--) {
        cin >> k >> n; //k층 n호

        vector<ll> arr;
        arr.resize(n+1);

        for (int i =1;i<=n;i++) {
            arr[i] = i;
        }

        for (int i =0;i<k;i++) {
            for (int j = 1;j<=n;j++) {
                arr[j] = arr[j] + arr[j-1];
            }
        }

        cout << arr[n] << "\n";
    }

    return 0;
}
