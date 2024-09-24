#include <iostream>
#include <vector>
using namespace std;

int t, k, answer = 0;
vector<vector<int>> gear;

void rotate_right(vector<int> &lst) { // 시계 방향으로 회전시키는 함수
    int last = lst.back(); // 마지막 요소를 가져옴
    lst.pop_back(); // 마지막 요소 제거
    lst.insert(lst.begin(), last); // 첫 번째 위치에 마지막 요소 삽입
}

void rotate_left(vector<int> &lst) { // 반시계 방향으로 회전시키는 함수
    int first = lst.front(); // 첫 번째 요소를 가져옴
    lst.erase(lst.begin()); // 첫 번째 요소 제거
    lst.push_back(first); // 마지막 위치에 첫 번째 요소 삽입
}

void rotate(int index, int d) { // 주어진 방향으로 회전시키는 함수
    if (d == 1) {
        rotate_right(gear[index]); // 시계 방향으로 회전
    } else if (d == -1) {
        rotate_left(gear[index]); // 반시계 방향으로 회전
    }
}

void propagation(int n, int direct, string prop_direct) { // 회전 전파시키는 함수
    if (prop_direct == "both") { // 양쪽으로 회전 전파
        if (n - 1 >= 0 && gear[n][6] != gear[n - 1][2]) { // 왼쪽 기어 회전 조건
            propagation(n - 1, -direct, "left"); // 왼쪽으로 전파
        }
        if (n + 1 < t && gear[n][2] != gear[n + 1][6]) { // 오른쪽 기어 회전 조건
            propagation(n + 1, -direct, "right"); // 오른쪽으로 전파
        }
    } else if (prop_direct == "left") { // 왼쪽으로만 회전 전파
        if (n - 1 >= 0 && gear[n][6] != gear[n - 1][2]) {
            propagation(n - 1, -direct, "left"); // 왼쪽으로 전파
        }
    } else if (prop_direct == "right") { // 오른쪽으로만 회전 전파
        if (n + 1 < t && gear[n][2] != gear[n + 1][6]) {
            propagation(n + 1, -direct, "right"); // 오른쪽으로 전파
        }
    }
    rotate(n, direct); // 주어진 기어를 회전시킴
}

int main() {
    ios_base::sync_with_stdio(false); // C++ 입출력 성능 향상
    cin.tie(NULL); // 입출력 동기화 해제

    cin >> t;
    gear.resize(t, vector<int>(8, 0)); // 기어 상태 초기화

    for (int i = 0; i < t; ++i) {
        string input;
        cin >> input;
        for (int j = 0; j < 8; ++j) {
            gear[i][j] = input[j] - '0'; // 기어 상태 입력
        }
    }

    cin >> k;
    for (int i = 0; i < k; ++i) {
        int number, direction;
        cin >> number >> direction;
        propagation(number - 1, direction, "both"); // 회전 전파
    }

    for (int i = 0; i < t; ++i) { // 점수 계산
        if (gear[i][0] == 1) { // 첫 번째 톱니가 S극일 경우
            answer++;
        }
    }

    cout << answer << '\n'; // 최종 점수 출력

    return 0;
}
