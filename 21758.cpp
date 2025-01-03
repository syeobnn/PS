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

int N;
int arr[100001];
long long mmax = 0;

void first() {//꿀통이 사이에
    int temp = 0, idx;
    long long tempMax = 0;
    for (int i = 1; i < N - 1; i++) {
        if (temp < arr[i]) {
            temp = arr[i];
            idx = i;
        }
        tempMax += arr[i];
    }

    tempMax += temp;

    if (mmax < tempMax) {
        mmax = tempMax;
    }
}

void second() {//꿀통이 오른쪽
    long long temp = 0, idx;
    long long tempMax = 0;
    long long sumArr[100001] = {0, arr[1]};
    for (int i = 2; i < N; i++) {
        sumArr[i] = sumArr[i - 1] + arr[i];
    }

    for(int i = 1; i < N;i++){
        temp = 0;

        temp += sumArr[N-1] - arr[i];//벌 1(맨 왼쪽)
        temp += sumArr[N-1] - sumArr[i];//벌 2(움직임)

        if(tempMax < temp){
            tempMax = temp;
        }
    }

    if (mmax < tempMax) {
        mmax = tempMax;
    }
}

void third() {//꿀통이 왼쪽
    long long temp = 0, idx;
    long long tempMax = 0;
    long long sumArr[100001] = {0, arr[1]};
    for (int i = 2; i < N; i++) {
        sumArr[i] = sumArr[i - 1] + arr[i];
    }

    for(int i = 1; i < N;i++){
        temp = 0;

        temp += sumArr[N-1] - arr[i];//벌 1(맨 왼쪽)
        temp += sumArr[N-1] - sumArr[i];//벌 2(움직임)

        if(tempMax < temp){
            tempMax = temp;
        }
    }

    if (mmax < tempMax) {
        mmax = tempMax;
    }
}

int main() {
    fastIo();

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    first();
    second();
    reverse(arr,arr+N);
    third();

    cout << mmax;

    return 0;
}
