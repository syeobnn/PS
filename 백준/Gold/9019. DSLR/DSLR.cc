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

namespace DSLR {
    inline int funcD(int n) {
        return (n * 2) % 10000;
    }

    inline int funcS(int n) {
        return n ? n - 1 : 9999;
    }

    inline int funcL(int n) {
        return (n % 1000) * 10 + n / 1000;
    }

    inline int funcR(int n) {
        return n / 10 + (n % 10) * 1000;
    }
}


using namespace DSLR;
int from, to;
bool visited[10000] = {false};
int parents[10000] = {0};
char oper[10000] = {""};

void push(int nxt, char op, int cur) {
    visited[nxt] = true;
    parents[nxt] = cur;
    oper[nxt] = op;
}

string bfs() {
    queue<int> q;
    memset(visited, 0, sizeof(visited));
    memset(parents, -1, sizeof(parents));
    memset(oper, 0, sizeof(oper));

    q.push(from);
    visited[from] = true;
    parents[from] = -1;

    if (from == to)
        return "";

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (to == cur) {
            break;
        }

        if (int d = funcD(cur); !visited[d]) {
            push(d,'D',cur);
            q.push(d);
        }

        if (int s = funcS(cur); !visited[s]) {
            push(s,'S',cur);
            q.push(s);
        }

        if (int l = funcL(cur); !visited[l]) {
            push(l,'L',cur);
            q.push(l);
        }

        if (int r = funcR(cur); !visited[r]) {
            push(r,'R',cur);
            q.push(r);
        }
    }

    string temp_arr;
    for (int i = to; parents[i] != -1; i = parents[i]) {
        temp_arr.push_back(oper[i]);
    }
    reverse(temp_arr.begin(), temp_arr.end());

    return temp_arr;
}

int main() {
    fastIo();

    int T;

    cin >> T;

    while (T--) {
        cin >> from >> to;

        cout << bfs() << "\n";
    }

    return 0;
}
