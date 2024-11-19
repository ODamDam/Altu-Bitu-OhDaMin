#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
using namespace std;

// 방향 이동 정의 (우, 하, 좌, 상)
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

// 게임에 필요한 상수 정의
const int EMPTY = 0;   // 빈 칸
const int APPLE = 1;   // 사과가 있는 칸

// 방향 전환 정보를 저장하기 위한 구조체
struct DirectionChange {
    int time;       // 시간 (몇 초 뒤에 방향을 전환할지)
    char direction; // 방향 ('L': 왼쪽, 'D': 오른쪽)
};

// 게임 진행 함수
int playGame(int board_size, vector<vector<int>> &board, queue<DirectionChange> &direction_changes) {
    deque<pair<int, int>> snake; // 뱀의 위치를 저장하는 덱 (머리와 꼬리 관리)
    snake.push_back({0, 0});     // 뱀의 초기 위치 (맨 위 맨 좌측)
    board[0][0] = -1;            // 뱀이 위치한 칸은 -1로 표시

    int time = 0;       // 현재 게임 시간
    int direction = 0;  // 초기 방향 (오른쪽)

    while (true) {
        time++; // 매 초 증가

        // 뱀의 머리 위치 계산
        int head_x = snake.front().first;
        int head_y = snake.front().second;
        int new_x = head_x + dx[direction];
        int new_y = head_y + dy[direction];

        // 벽이나 자기 몸과 충돌하면 게임 종료
        if (new_x < 0 || new_y < 0 || new_x >= board_size || new_y >= board_size || board[new_x][new_y] == -1) {
            break;
        }

        // 사과가 있는 칸으로 이동한 경우
        if (board[new_x][new_y] == APPLE) {
            board[new_x][new_y] = -1; // 사과를 먹었으므로 해당 칸은 뱀으로 표시
            snake.push_front({new_x, new_y}); // 머리를 새 위치로 이동
        } else { // 빈 칸으로 이동한 경우
            board[new_x][new_y] = -1; // 새 위치를 뱀으로 표시
            snake.push_front({new_x, new_y}); // 머리를 새 위치로 이동

            // 꼬리를 줄여야 하므로 꼬리가 있던 칸을 비운다
            auto tail = snake.back();
            snake.pop_back();
            board[tail.first][tail.second] = EMPTY;
        }

        // 방향 전환 처리
        if (!direction_changes.empty() && direction_changes.front().time == time) {
            char turn = direction_changes.front().direction;
            direction_changes.pop();
            if (turn == 'L') {
                direction = (direction + 3) % 4; // 왼쪽으로 90도 회전
            } else if (turn == 'D') {
                direction = (direction + 1) % 4; // 오른쪽으로 90도 회전
            }
        }
    }

    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int board_size, apple_count;
    cin >> board_size >> apple_count;

    // 보드 초기화
    vector<vector<int>> board(board_size, vector<int>(board_size, EMPTY));

    // 사과 위치 입력
    for (int i = 0; i < apple_count; i++) {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = APPLE; // 입력은 1-based, 내부 보드는 0-based
    }

    // 방향 전환 정보 입력
    int direction_change_count;
    cin >> direction_change_count;
    queue<DirectionChange> direction_changes;
    for (int i = 0; i < direction_change_count; i++) {
        int time;
        char direction;
        cin >> time >> direction;
        direction_changes.push({time, direction});
    }

    // 게임 실행 및 결과 출력
    cout << playGame(board_size, board, direction_changes) << "\n";

    return 0;
}
