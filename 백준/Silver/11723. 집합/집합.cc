#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
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

int n;
vector<int> arr;

int check_in_arr(int find_num) { //선형적으로 탐색하고 값이 있으면 값의 index를 반환
    bool flag = false;
    int index = 0;
    for (int i =0;i<arr.size();i++) {
        if (arr[i] == find_num) {
            flag = true;
            index = i;
            break;
        }
    }

    if (flag)
        return index;

    return -1;
}

int main() {
    fastIo();

    cin >> n;

    while (n--) {
        string com;//command
        int com_num;
        cin >> com;

        if (com == "add") {
            cin >> com_num;
            if (int index = check_in_arr(com_num); index == -1) {
                arr.push_back(com_num);
            }
        }
        else if (com == "remove") {
            cin >> com_num;
            if (int index = check_in_arr(com_num); index != -1) {
                arr.erase(arr.begin()+index);
            }
        }
        else if (com == "check") {
            cin >> com_num;
            if (check_in_arr(com_num) != -1)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (com == "toggle") {
            cin >> com_num;
            if (int index = check_in_arr(com_num); index != -1) {
                arr.erase(arr.begin()+index);
            }
            else {
                arr.push_back(com_num);
            }
        }
        else if (com == "all") {
            arr.resize(20);
            for (int i=0;i<20;i++) {
                arr[i] = i+1;
            }
        }
        else if (com == "empty") {
            while (!arr.empty()) {
                arr.pop_back();
            }
        }
    }

    return 0;
}