#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 벽을 세우기 위한 모든 경우의 수를 탐색. 빈칸 중 3개의 칸을 선택하여 벽을 세우는 조합을 구해야 한다.
// DFS, BFS 함께 사용하는 백트래킹 문제.

const int MAX = 8;
int n, m;
int lab[MAX][MAX];         // 연구소 지도
int temp_lab[MAX][MAX];     // 벽을 세운 후의 임시 지도
int dx[] = {0, 0, 1, -1};  // 방향 벡터 (상, 하, 좌, 우)
int dy[] = {1, -1, 0, 0};
int max_safe_area = 0;       // 최대 안전 영역 크기

// 바이러스를 퍼뜨리기 (BFS 사용)
void spread_virus() {
    int spread_lab[MAX][MAX];
    queue<pair<int, int>> q;

    // temp_lab을 복사해서 spread_lab에 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            spread_lab[i][j] = temp_lab[i][j];
            if (spread_lab[i][j] == 2) {
                q.push({i, j}); // 바이러스가 있는 위치 저장
            }
        }
    }

    // BFS로 바이러스를 퍼뜨리기
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 지도 범위 안에 있는 경우 && 빈 칸인 경우 -> 바이러스를 퍼뜨림
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && spread_lab[nx][ny] == 0) {
                spread_lab[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }

    // 크기 계산
    int safe_area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spread_lab[i][j] == 0) {
                safe_area++;
            }
        }
    }

    // 갱신
    max_safe_area = max(max_safe_area, safe_area);
}

// 벽 세우기 (백트래킹)
void build_wall(int count) {
    // 벽 3개를 다 세운 경우, 바이러스를 퍼뜨림
    if (count == 3) {
        spread_virus();
        return;
    }

    // 빈 칸에 벽 세우기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp_lab[i][j] == 0) {
                temp_lab[i][j] = 1;  // 벽을 세움
                build_wall(count + 1); // 다음 벽 세우기
                temp_lab[i][j] = 0;  // 원상 복구
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    // 연구소 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
        }
    }

    // 연구소 상태를 복사해둔다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp_lab[i][j] = lab[i][j];
        }
    }

    // 벽 세우기 시작
    build_wall(0);

    // 최대 안전 영역 출력
    cout << max_safe_area << '\n';

    return 0;
}
