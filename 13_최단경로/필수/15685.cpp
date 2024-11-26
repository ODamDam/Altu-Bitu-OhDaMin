#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 방향 배열: 0 →, 1 ↑, 2 ←, 3 ↓
const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, -1, 0, 1};
const int MAX_GRID = 101;

int grid[MAX_GRID][MAX_GRID]; // 격자 상태를 저장

// 드래곤 커브 생성 함수
void generateDragonCurve(int x, int y, int d, int g) {
    vector<int> directions; // 드래곤 커브의 방향 저장
    directions.push_back(d); // 0세대 방향 추가

    // g세대 방향 계산
    for (int gen = 1; gen <= g; gen++) {
        int size = directions.size();
        for (int i = size - 1; i >= 0; i--) {
            directions.push_back((directions[i] + 1) % 4); // 90도 회전
        }
    }

    // 드래곤 커브 격자에 기록
    grid[y][x] = 1; // 시작 점 표시
    for (int dir : directions) {
        x += DX[dir];
        y += DY[dir];
        grid[y][x] = 1; // 이동한 점 표시
    }
}

// 1x1 정사각형 개수 계산 함수
int countSquares() {
    int count = 0;
    for (int y = 0; y < MAX_GRID - 1; y++) {
        for (int x = 0; x < MAX_GRID - 1; x++) {
            // 1x1 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인지 확인
            if (grid[y][x] && grid[y + 1][x] && grid[y][x + 1] && grid[y + 1][x + 1]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n; // 드래곤 커브의 개수
    cin >> n;

    // 입력 받고 드래곤 커브 생성
    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        generateDragonCurve(x, y, d, g);
    }

    // 1x1 정사각형 개수 계산
    int result = countSquares();

    // 결과 출력
    cout << result << "\n";

    return 0;
}
