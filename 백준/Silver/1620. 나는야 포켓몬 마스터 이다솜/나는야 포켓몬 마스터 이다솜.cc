#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
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

int n, m;
unordered_map<string, int> hash_string_key;
unordered_map<int, string> hash_int_key;

int main() {
    fastIo();

    cin >> n >> m;
    string temp;

    for (int i = 0;i <n;i++) {
        cin >> temp;
        hash_string_key[temp] = i + 1;
        hash_int_key[i+1] = temp;
    }

    while (m--) {
        string query_input;

        cin >> query_input;

        if (query_input[0] >= '0' && query_input[0] <= '9') {
            int string_to_int = stoi(query_input);
            cout << hash_int_key[string_to_int] <<"\n";
        }
        else {
            cout << hash_string_key[query_input] <<"\n";
        }
    }

    return 0;
}