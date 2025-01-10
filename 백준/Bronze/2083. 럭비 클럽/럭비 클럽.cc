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

int N, T, M;

vector<int> arr;
vector<int> tree[50001];
int parents[50001];
int level[50001];

int main() {
    fastIo();

    while(1){
        string name;
        int old, weight;

        cin >> name >> old >> weight;

        if(name == "#" && old == 0 && weight == 0)
            break;

        if(old > 17 || weight >= 80){
            cout << name << " " << "Senior\n";
        }
        else{
            cout << name << " " << "Junior\n";
        }
    }

    return 0;
}
