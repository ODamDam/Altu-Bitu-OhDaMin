// 적록색약 x: 빨, 초, 파 구분
// 적록색약 o: 빨=초, 파 구분
// 구역 탐색에 DFS 이용.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;
char grid[MAX][MAX];       // 원본 그리드
bool visited[MAX][MAX];    // 방문 여부 체크
int dx[] = {-1, 1, 0, 0};  // 상하좌우 탐색을 위한 방향 벡터
int dy[] = {0, 0, -1, 1};
int n;

// DFS로 구역을 탐색하는 함수
void dfs(int x, int y, char color) {
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 지도 범위를 벗어나지 않고, 같은 색상인 경우 DFS 계속 진행
        if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && grid[nx][ny] == color) {
            dfs(nx, ny, color);
        }
    }
}

// 적록색약 처리: R -> G 변환
void convert() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'R') {
                grid[i][j] = 'G';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력 받기
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // 적록색약 x 경우
    int normal_count = 0;
    fill(&visited[0][0], &visited[0][0] + MAX * MAX, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j, grid[i][j]);
                normal_count++;
            }
        }
    }

    // 적록색약 o 경우
    int color_blind_count = 0;
    convert();  // 적록색약 처리를 위해 변환
    fill(&visited[0][0], &visited[0][0] + MAX * MAX, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j, grid[i][j]);
                color_blind_count++;
            }
        }
    }

    // 결과 출력
    cout << normal_count << ' ' << color_blind_count << '\n';

    return 0;
}
