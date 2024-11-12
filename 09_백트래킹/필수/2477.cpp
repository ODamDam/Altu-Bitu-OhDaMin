#include <iostream>
using namespace std;

// 참외밭 면적을 계산하는 함수
int calculate_area(int k, int directions[], int lengths[]) {
    int max_width = 0, max_height = 0;  // 최대 가로, 세로 길이
    int width_idx = 0, height_idx = 0;  // 최대 길이의 인덱스 저장

    // 가장 긴 가로와 세로 변 찾기
    for (int i = 0; i < 6; i++) {
        // 동쪽(1)과 서쪽(2) 방향 (==가로)
        if (directions[i] == 1 || directions[i] == 2) {
            if (lengths[i] > max_width) {
                max_width = lengths[i];  // 최대 가로 길이 갱신
                width_idx = i;           // 가로 길이 인덱스 저장
            }
        }
        // 남쪽(3)과 북쪽(4) 방향 (==세로)
        else if (directions[i] == 3 || directions[i] == 4) {
            if (lengths[i] > max_height) {
                max_height = lengths[i];  // 최대 세로 길이 갱신
                height_idx = i;           // 세로 길이 인덱스 저장
            }
        }
    }

    // 작은 사각형의 너비와 높이 계산 (현재 최대 길이의 대칭 변)
    int small_width = lengths[(width_idx + 3) % 6];  // 가로 길이의 대칭 변
    int small_height = lengths[(height_idx + 3) % 6]; // 세로 길이의 대칭 변

    // (총 면적) = 가장 큰 사각형) - (안의 작은 사각형)
    int area = (max_width * max_height) - (small_width * small_height);

    // 최종 참외 개수 계산
    return area * k; // 총 참외 개수 반환
}

int main() {
    int k;  // 1m²당 참외 개수
    cin >> k;

    int directions[6];  // 방향을 저장할 배열
    int lengths[6];     // 길이를 저장할 배열

    // 방향과 길이 입력 받기
    for (int i = 0; i < 6; i++) {
        cin >> directions[i] >> lengths[i];
    }

    // 면적 계산 및 결과 출력
    cout << calculate_area(k, directions, lengths) << "\n";

    return 0;
}
