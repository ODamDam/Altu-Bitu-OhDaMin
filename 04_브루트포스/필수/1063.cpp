#include <bits/stdc++.h>
using namespace std;

// 좌표가 체스보드의 범위 내에 있는지 확인 <- 킹, 돌의 좌표가 체스보드 범위 내에 있어야 하므로
bool isWithinBounds(int row, int col) {
    return (row >= 0) && (row < 8) && (col >= 0) && (col < 8);
}

// 방향에 따라 위치를 업데이트하는 함수 <- 주어진 조건에 따라
pair<int, int> movePosition(pair<int, int> pos, string direction) {
    if (direction == "R") return {pos.first, pos.second + 1};       // 오른쪽 이동
    if (direction == "L") return {pos.first, pos.second - 1};       // 왼쪽 이동
    if (direction == "B") return {pos.first - 1, pos.second};       // 아래 이동
    if (direction == "T") return {pos.first + 1, pos.second};       // 위 이동
    if (direction == "RT") return {pos.first + 1, pos.second + 1};  // 오른쪽 위 이동
    if (direction == "LT") return {pos.first + 1, pos.second - 1};  // 왼쪽 위 이동
    if (direction == "RB") return {pos.first - 1, pos.second + 1};  // 오른쪽 아래 이동
    if (direction == "LB") return {pos.first - 1, pos.second - 1};  // 왼쪽 아래 이동
    return pos; // 방향이 유효하지 않을 경우 위치 변경 X.
}

// 체스 -> 8x8 보드 좌표로 변환
pair<int, int> notationToCoords(string pos) {
    return {pos[1] - '1', pos[0] - 'A'};
}

// 8x8 보드 -> 체스 좌표로 변환
string coordsToNotation(pair<int, int> pos) {
    return string(1, pos.second + 'A') + to_string(pos.first + 1);
}

int main() {
    string king, stone;
    int moveCount;

    // 킹과 돌의 초기 위치와 이동 횟수를 입력받음
    cin >> king >> stone >> moveCount;

    pair<int, int> kingPos = notationToCoords(king); // 킹의 좌표 변환
    pair<int, int> stonePos = notationToCoords(stone); // 돌의 좌표 변환

    while (moveCount--) {
        string moveDirection;
        cin >> moveDirection;

        // 방향에 따라 킹의 다음 위치 계산
        pair<int, int> nextKingPos = movePosition(kingPos, moveDirection);

        // 킹의 다음 위치가 보드 범위를 벗어나면 이동 무시
        if (!isWithinBounds(nextKingPos.first, nextKingPos.second)) continue;

        // 킹의 다음 위치가 돌의 위치와 같을 경우
        if (nextKingPos == stonePos) {
            // 동일한 방향으로 돌의 다음 위치 계산 (돌이 같은 방향으로 한 칸 이동)
            pair<int, int> nextStonePos = movePosition(stonePos, moveDirection);

            // 돌의 다음 위치가 보드 범위를 벗어난다면 -> 이동 X.
            if (!isWithinBounds(nextStonePos.first, nextStonePos.second)) continue;

            // 돌_위치 업데이트
            stonePos = nextStonePos;
        }

        // 킹_위치 업데이트
        kingPos = nextKingPos;
    }

    // 최종적으로 킹과 돌의 위치를 체스 좌표로 출력
    cout << coordsToNotation(kingPos) << '\n' << coordsToNotation(stonePos) << '\n';
}
