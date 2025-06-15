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

    string s;

    while (getline(cin, s)) {
        if (s == ".")
            return 0;

        bool flag = false;

        stack<char> brackets;

        for (auto i: s) {
            if (i == ')' || i == ']') {
                if (brackets.empty()) {
                    cout << "no" << endl;
                    flag = true;
                    break;
                }
                else {
                    if (i == ')') {
                        if (const char top = brackets.top(); top == '(')
                            brackets.pop();
                        else {
                            cout << "no" << endl;
                            flag = true;
                            break;
                        }
                    }
                    else if (i == ']'){
                        if (const char top = brackets.top(); top == '[')
                            brackets.pop();
                        else {
                            cout << "no" << endl;
                            flag = true;
                            break;
                        }
                    }
                }
            }

            if (i == '(') {
                brackets.push('(');
            } else if (i == '[') {
                brackets.push('[');
            }
        }

        if (flag) continue;

        if (brackets.empty()) {
            cout << "yes" << endl;
        } else
            cout << "no" << endl;
    }

    return 0;
}
