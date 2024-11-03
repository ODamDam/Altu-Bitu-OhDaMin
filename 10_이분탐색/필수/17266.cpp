#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int tunnel_length, lamp_count;
    cin >> tunnel_length >> lamp_count;

    vector<int> lamp_positions(lamp_count);
    for (int i = 0; i < lamp_count; ++i) {
        cin >> lamp_positions[i];
    }

    // 가로등 위치를 오름차순으로 정렬
    sort(lamp_positions.begin(), lamp_positions.end());

    // 가로등 간 최대 간격을 찾기 위해 초기화
    int max_gap = 0;

    // 가로등 위치 간의 간격을 계산하여 최대 간격을 찾음
    for (int i = 1; i < lamp_count; ++i) {
        max_gap = max(max_gap, lamp_positions[i] - lamp_positions[i - 1]);
    }

    // 시작 지점과 첫 번째 가로등, 마지막 가로등과 끝 지점 간의 간격을 고려
    int start_gap = lamp_positions[0] - 0;
    int end_gap = tunnel_length - lamp_positions[lamp_count - 1];

    // 최소 높이는 모든 구간에서 최대 요구되는 높이 중 가장 큰 값
    int min_height = max({(max_gap + 1) / 2, start_gap, end_gap});

    // 결과 출력
    cout << min_height << "\n";

    return 0;
}
