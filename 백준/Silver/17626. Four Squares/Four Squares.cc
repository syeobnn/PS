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

    int n;

    cin >> n;

    arr.resize(200001);

    for (int i = 1; i <= 224; i++) {
        int lag = i * i;
        if (!arr[lag])
            arr[lag] = 1;
    }

    for (int i = 1; i <= 224; i++) {
        for (int j = 1; i <= 224; j++) {
            int lag = i * i + j * j;
            if (lag > 50000)
                break;
            if (!arr[lag])
                arr[lag] = 2;
        }
    }

    for (int i = 1; i <= 224; i++) {
        for (int j = 1; j <= 224; j++) {
            for (int k = 1; k <= 224; k++) {
                int lag = i * i + j * j + k * k;
                if (lag > 50000)
                    break;
                if (!arr[lag])
                    arr[lag] = 3;
            }
        }
    }

    cout << (arr[n] ? arr[n] : 4) << "\n";

    return 0;
}
