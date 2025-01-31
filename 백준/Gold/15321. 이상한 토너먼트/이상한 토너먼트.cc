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
#define log2 18

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

vector<int> arr;
priority_queue<int, vector<int>, greater<>> pq;

int find(int va) {
    int idx = -1;

    for (int i=0;i<arr.size();i++) {
        if (arr[i] == va) {
            idx = i;
            break;
        }
    }

    return idx;
}

int main() {
    fastIo();
    int N;
    int sum =0;

    cin >> N;

    for (int i =0;i<N;i++) {
        int a;
        cin >> a;
        arr.push_back(a);
        pq.push(a);
    }

    while (pq.size()>1) {
        int cur = pq.top(); pq.pop();

        int idx = find(cur);
        int gap;

        if (idx == -1) {
            cout << "it's something wrong\n";
        }
        if (idx == 0) {
            gap = abs(arr[idx] - arr[idx+1]);
            arr.erase(arr.begin()+idx);
            sum += gap;
            continue;
        }
        if (idx == pq.size()) {
            gap = abs(arr[idx] - arr[idx-1]);
            arr.erase(arr.begin()+idx);
            sum += gap;
            continue;
        }

        if (abs(arr[idx] - arr[idx+1]) < abs(arr[idx] - arr[idx-1])) {
            gap = abs(arr[idx] - arr[idx+1]);
        }
        else {
            gap = abs(arr[idx] - arr[idx-1]);
        }

        arr.erase(arr.begin() + idx);
        sum += gap;
    }

    cout << sum << "\n";

    return 0;
}
