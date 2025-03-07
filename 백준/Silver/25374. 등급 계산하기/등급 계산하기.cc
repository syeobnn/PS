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
#define log2 51

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
vector<int> grade;
vector<int> ans;
int N;

int main() {
    fastIo();

    cin >> N;

    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), [](const int &first,const int &second) {
             return first > second;
         }
    );

    grade.resize(10);
    ans.resize(10);
    int percent[10] = {0, 4, 11, 23, 40, 60, 77, 89, 96, 100};
    int cnt = 0;
    int cnt_b = 0;

    for (int i =1;i<10;i++) {
        int students = N;
        grade[i] = (N * percent[i] + 99) / 100; //백분위 인원수 계산
    }

    int temp = arr[cnt];

    for (int i =1;i<10;i++) {
        if (cnt > grade[i]) {
            continue;
        }
        while (true) {
            if (cnt >= N || temp != arr[cnt] && grade[i] <= cnt) break; //백분위까지거나 이전 값과 동일하면 괜찮다.
            temp = arr[cnt];
            cnt++;
        }
        ans[i] = cnt - cnt_b;
        cnt_b = cnt;
        if (cnt >= N)
            break;
    }

    for (int i =1;i<10;i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
