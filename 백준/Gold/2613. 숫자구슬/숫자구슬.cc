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

int N, M;
vector<int> arr;

int divBead(int maxSum) {
    int groupCount = 1, beadCount = 0;
    for (auto i: arr) {
        if (beadCount + i > maxSum) {
            groupCount++;
            beadCount = i;
            if (groupCount > M)
                return 0;
        } else {
            beadCount += i;
        }
    }
    return 1;
}

int main() {
    fastIo();

    cin >> N >> M;
    arr.resize(N);
    int low = 0, high = 0;
    int sum;
    int lin;
    vector<pii > groups;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        low = max(low, arr[i]);
        high += arr[i];
    }

    sum = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (divBead(mid)) {
            sum = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    int groupCnt = 0, beadCnt = 0;
    int flag = 1;
    for (auto i: arr) {
        if (beadCnt + i > sum) {
            if (beadCnt == sum && flag) {
                groups.emplace_back(groupCnt, 1);
                flag = 0;
            } else {
                groups.emplace_back(groupCnt, 0);
            }
            groupCnt = 0;
            beadCnt = 0;
        }
        beadCnt += i;
        groupCnt++;
    }
    groups.emplace_back(groupCnt, 0);

    if (groups.size() < M) {
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i].second)
                continue;
            if (groups[i].first > 1){
                groups[i].first--;
                groups.insert(groups.begin() + i, {1, 0});
            }
            if(groups.size() == M)
                break;
        }
    }

    if(groups.size()<M){
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i].second){
                groups[i].first--;
                groups.insert(groups.begin() + i, {1, 0});
            }
            if(groups.size() == M)
                break;
        }
    }

    cout << sum << '\n';
    for (auto i: groups) {
        cout << i.first << " ";
    }
    //cout << "\n" << lin;

    return 0;
}
