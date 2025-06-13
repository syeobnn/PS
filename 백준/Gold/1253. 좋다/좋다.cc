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

int N;
int cnt = 0;
vector<ll> arr;
unordered_set<ll> check_num;
vector<bool> check_arr;

int main() {
    fastIo();

    cin >> N;
    arr.resize(N);
    check_arr.resize(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i =0;i<N;i++) {
        int l = 0, r = N -1;
        while (l < r) {
            if (i == l) {l++; continue;}
            if (i == r) {r--; continue;}
            ll sum = arr[l] + arr[r];

            if (sum == arr[i]) {cnt++; break;}
            else if (sum > arr[i]) {r--;}
            else l++;
        }
    }

    cout << cnt << "\n";

    return 0;
}
