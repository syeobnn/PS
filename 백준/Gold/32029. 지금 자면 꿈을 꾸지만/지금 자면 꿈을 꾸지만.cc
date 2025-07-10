#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

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

vector<int> arr;

int main() {
    fastIo();

    int n, a, b;
    int ans = 0;

    cin >> n >> a >> b;

    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < a; i++) {
        // i는 정수 X
        int sleep_a = a - i;
        int sleep_b = b * i;

        for (int j = 0; j <= n; j++) {
            // 잠을 언제 잘건지
            int temp_a = a;
            int time_cnt = 0, temp_ans = 0;

            for (int k = 0; k < n; k++) {
                if (k == j) {
                    //잠자는 시간
                    temp_a = sleep_a;
                    time_cnt += sleep_b;
                }

                if (time_cnt + temp_a > arr[k]) {
                    continue;
                }

                time_cnt += temp_a;
                temp_ans++;
            }

            ans = max(temp_ans, ans);
        }
    }

    cout << ans << "\n";

    return 0;
}