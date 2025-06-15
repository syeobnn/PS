#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
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

int main() {
    fastIo();

    int T;

    cin >> T;
    cin.ignore();

    while (T--) {
        string s;
        getline(cin, s);

        stack<int> brackets;
        bool flag = false;
        for (auto i : s) {
            if (i == '(') {
                brackets.push('(');
            }
            else {
                // ')'
                if (brackets.empty()) {
                    flag = true;
                    cout << "NO" << endl;
                    break;
                }
                if (brackets.top() == '(') {
                    brackets.pop();
                }
                else {
                    flag = true;
                    cout << "NO" << endl;
                    break;
                }
            }
        }

        if (flag) continue;

        if (brackets.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
