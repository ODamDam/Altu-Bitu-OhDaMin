#include <iostream>
#include <vector>

using namespace std;

int n, m; // 방의 크기 N x M
int r, c, d;

vector<vector<int>> room; // 방의 상태를 나타내는 2차원 벡터
vector<vector<bool>> cleaned; // 청소 여부를 표시하는 2차원 벡터

// 북, 동, 남, 서 방향에 대한 행/열 이동값 설정
const int DR[4] = {-1, 0, 1, 0}; // 방향에 따른 행 이동
const int DC[4] = {0, 1, 0, -1}; // 방향에 따른 열 이동

// 방향을 반시계 방향으로 회전시키는 함수
int rotateLeft(int direction) {
    return (direction + 3) % 4; // 왼쪽으로 90도 회전
}

// 현재 방향에서 후진할 위치를 계산하는 함수
pair<int, int> moveBackward(int row, int col, int direction) {
    int back_dir = (direction + 2) % 4; // 현재 방향에서 뒤쪽 방향 계산
    return {row + DR[back_dir], col + DC[back_dir]}; // 후진 위치 반환
}

// 방을 청소하고, 청소한 칸의 개수를 반환하는 함수
int cleanRoom() {
    int cleaned_count = 0; // 청소한 칸의 개수를 저장할 변수

    while (true) {
        // 1. 현재 위치를 청소
        if (!cleaned[r][c]) { // 현재 칸이 청소되지 않았으면
            cleaned[r][c] = true; // 청소 상태로 변경
            cleaned_count++; // 청소한 칸 개수 증가
        }

        bool found_cleanable = false; // 청소 가능한 칸을 찾았는지 여부

        // 2. 주변 4칸을 확인하며 청소할 칸을 탐색
        for (int i = 0; i < 4; i++) {
            d = rotateLeft(d);
            int new_row = r + DR[d];
            int new_col = c + DC[d];

            // 청소되지 않은 빈 칸이 있는 경우 이동
            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !cleaned[new_row][new_col] && room[new_row][new_col] == 0) {
                r = new_row; // 청소 가능한 위치로 이동
                c = new_col;
                found_cleanable = true;
                break; // 청소 가능한 칸을 찾았으므로 4방향 탐색 종료
            }
        }

        // 3. 주변에 청소할 빈 칸이 없는 경우
        if (!found_cleanable) {
            auto [back_row, back_col] = moveBackward(r, c, d);
            if (room[back_row][back_col] == 1) { // 후진하려는 위치가 벽인 경우
                break;
            }
            r = back_row; // 후진 가능하면 후진
            c = back_col;
        }
    }
    return cleaned_count; // 청소한 칸의 개수 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 방의 크기를 입력 받는다.
    cin >> n >> m;
    // 처음에 로봇 청소기가 있는 칸의 좌표 (r,c), 방향 d
    cin >> r >> c >> d;
	
    room.resize(n, vector<int>(m)); // 방 상태를 저장할 벡터 크기 설정
    cleaned.resize(n, vector<bool>(m, false)); // 청소 여부를 저장할 벡터 설정

    // 방의 상태 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    cout << cleanRoom() << '\n'; // 청소한 칸의 개수 출력
    return 0;
}
