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

bool check_fizzbuzz(const string& s) {
    if (s == "Fizz" || s == "Buzz" || s == "FizzBuzz")
        return true;
    return false;
}

int main() {
    fastIo();

    int num = INF;
    string s_num;

    for (int i =0;i<3;i++) {
        string s;
        cin >> s;
        if (!check_fizzbuzz(s)) {
            num = i;
            s_num = s;
        }
    }

    int nextNum = stoi(s_num) + (3 - num);

    if (!(nextNum % 3) && !(nextNum % 5)) {
        cout << "FizzBuzz\n";
    }
    else if (!(nextNum % 3)) {
        cout << "Fizz\n";
    }
    else if (!(nextNum % 5)) {
        cout << "Buzz\n";
    }
    else {
        cout << nextNum << "\n";
    }

    return 0;
}
