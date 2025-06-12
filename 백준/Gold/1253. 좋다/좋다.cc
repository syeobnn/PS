#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define ll long long

using namespace std;

int N;
int cnt = 0;
vector<ll> arr;
unordered_set<ll> check_num;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fastIo();

    cin >> N;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int l = 0, r = N - 1;
            ll val = arr[i] + arr[j];

            while (l <= r) {
                int mid = (l + r) / 2;
                if (arr[mid] == val) {
                    if (mid != i && mid != j) {
                        check_num.insert(val);
                    }
                    break;
                }
                else if (arr[mid] > val)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
    }

    for (int k = 0; k < N; k++) {
        if (check_num.count(arr[k]))
            cnt++;
    }

    cout << cnt << "\n";
    return 0;
}
