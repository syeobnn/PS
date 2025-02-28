#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char arr[52][52][52];

int ddx[] = {0, 0, 1, -1, 0, 0};   // x축: 오른쪽, 왼쪽
int ddy[] = {0, 0, 0, 0, -1, 1};    // y축: 위, 아래 (출력 시 행)
int ddz[] = {1, -1, 0, 0, 0, 0};    // z축: 위쪽, 아래쪽 (slice)

void bfs(int fuel) {
    // 큐브의 크기는 (2*fuel+1)³
    int cubeSize = 2 * fuel + 1;
    
    // cube 영역만 '.'으로 초기화
    for (int z = 0; z < cubeSize; z++)
        for (int y = 0; y < cubeSize; y++)
            for (int x = 0; x < cubeSize; x++)
                arr[z][y][x] = '.';
    
    // 지역 큐를 사용
    queue<tuple<int, int, int>> q;
    int start = fuel; // 시작 좌표는 중앙: (fuel, fuel, fuel)
    q.push({start, start, start});
    arr[start][start][start] = '0';
    
    // 최대 연료를 문자로 저장 ('0'부터 시작하므로)
    char maxCost = fuel + '0';
    
    while (!q.empty()) {
        int z, y, x;
        tie(z, y, x) = q.front();
        q.pop();
        
        // 이미 최대 연료 소모한 셀은 더 진행하지 않음
        if (arr[z][y][x] == maxCost)
            continue;
        
        // 6방향 이동
        for (int i = 0; i < 6; i++) {
            int nz = z + ddz[i];
            int ny = y + ddy[i];
            int nx = x + ddx[i];
            
            // 경계 검사 (큐브 크기: 0 ~ cubeSize-1)
            if (nz < 0 || nz >= cubeSize || ny < 0 || ny >= cubeSize || nx < 0 || nx >= cubeSize)
                continue;
            
            // 아직 방문하지 않은 셀이면
            if (arr[nz][ny][nx] == '.') {
                arr[nz][ny][nx] = arr[z][y][x] + 1; // 비용 1 증가
                q.push({nz, ny, nx});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for (int scenario = 1; scenario <= t; scenario++) {
        int fuel;
        cin >> fuel;
        int cubeSize = 2 * fuel + 1;
        
        bfs(fuel);
        
        cout << "Scenario #" << scenario << ":\n";
        for (int z = 0; z < cubeSize; z++) {
            cout << "slice #" << z + 1 << ":\n";
            for (int y = 0; y < cubeSize; y++) {
                for (int x = 0; x < cubeSize; x++) {
                    cout << arr[z][y][x];
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }
    
    return 0;
}
