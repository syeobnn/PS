#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
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

int N;
multiset<int> ss;

int main() {
    fastIo();

    int cnt = -1;
    auto it = ss.begin();
    cin >> N;

    while (N--) {
        int temp;
        cin >> temp;
        ss.insert(temp);
        cnt++;

        if (cnt == 0) {
            it = ss.begin();
            cout << *it << "\n";
            continue;
        }

        if (*it > temp) {
            //만약 같은 원소가 들어오면 얘는 왼쪽으로 들어오나 오른쪽으로 들어오나?
            //작은게 들어오면 옆으로 한 칸씩 땡기는 느낌으로 접근하면 문제를 해결할 수 있을 것이다.
            --it;
        }

        if (cnt & 1)
            cout << *it << "\n";
        else
            cout << *(++it) << "\n";
    }

}