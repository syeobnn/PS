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

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            ll l = 0, r = N - 1;
            ll val = arr[i] + arr[j];

            while (l <= r) {
                int mid = (l + r) / 2;
                if (arr[mid] == val) {
                    if (mid == i || mid == j)
                        break;
                    int temp_l = mid, temp_r = mid;

                    if (!check_arr[mid]) {
                        while (temp_l >= 0 && arr[temp_l] == val) {
                            check_arr[temp_l] = true;
                            temp_l--;
                        }

                        while (temp_r < N && arr[temp_r] == val) {
                            check_arr[temp_r] = true;
                            temp_r++;
                        }
                    }
                    break;
                } else if (arr[mid] > val)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
    }

    for (auto i: check_arr) {
        if (i)
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
