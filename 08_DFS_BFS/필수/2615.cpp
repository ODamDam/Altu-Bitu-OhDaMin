#include <iostream>
using namespace std;

const int board_size = 19; // 바둑판 크기
int board[board_size][board_size];

// 방향: 오른쪽, 아래, 대각선 오른쪽 아래, 대각선 왼쪽 아래
int dx[4] = {0, 1, 1, -1};
int dy[4] = {1, 0, 1, 1};

// 좌표가 유효한지 확인
bool is_valid(int x, int y) {
    return x >= 0 && x < board_size && y >= 0 && y < board_size;
}

// 승리 여부를 확인
bool check_win(int x, int y, int color) {
    // 4방향 확인
    for (int dir = 0; dir < 4; ++dir) {
        int count = 1; // 현재 바둑알 포함
        int nx = x + dx[dir], ny = y + dy[dir];

        // 동일한 색의 바둑알이 연속으로 있는지 확인
        while (is_valid(nx, ny) && board[nx][ny] == color) {
            count++;
            nx += dx[dir];
            ny += dy[dir];
        }

        // 반대 방향 확인
        nx = x - dx[dir], ny = y - dy[dir];
        while (is_valid(nx, ny) && board[nx][ny] == color) {
            count++;
            nx -= dx[dir];
            ny -= dy[dir];
        }

        // 5개의 바둑알이 연속된 경우
        if (count == 5) {
            // 이전 좌표가 유효하지 않거나 다른 색인 경우만 승리 인정
            int prev_x = x - dx[dir], prev_y = y - dy[dir];
            if (!is_valid(prev_x, prev_y) || board[prev_x][prev_y] != color) {
                cout << color << '\n';
                cout << x + 1 << ' ' << y + 1 << '\n'; // 1-based index로 출력
                return true;
            }
        }
    }
    return false;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 바둑판 입력
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            cin >> board[i][j];
        }
    }

    // 바둑판에서 승리 여부 확인
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            if (board[i][j] != 0) {
                // 현재 위치에서 승리 확인
                if (check_win(i, j, board[i][j])) {
                    return 0;
                }
            }
        }
    }

    // 승부가 나지 않았을 경우
    cout << 0 << '\n';
    return 0;
}
