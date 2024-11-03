#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 현재 블루레이 크기로 모든 강의를 M개의 블루레이에 담을 수 있는지 확인하는 함수
bool can_record(const vector<int>& lectures, int blu_ray_size, int m) {
    int count = 1;  // 필요한 블루레이 개수
    int current_sum = 0;

    for (int length : lectures) {
        if (current_sum + length > blu_ray_size) {
            // 현재 블루레이에 담을 수 없으므로 새로운 블루레이 시작
            count++;
            current_sum = length;
            if (count > m) {
                return false;  // 블루레이 개수 초과 시 불가능
            }
        } else {
            current_sum += length;
        }
    }

    return true;  // M개의 블루레이에 담을 수 있음
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> lectures(n);
    int max_length = 0, total_length = 0;

    for (int i = 0; i < n; ++i) {
        cin >> lectures[i];
        max_length = max(max_length, lectures[i]);
        total_length += lectures[i];
    }

    // 이분 탐색 범위 설정
    int low = max_length, high = total_length, result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (can_record(lectures, mid, m)) {
            result = mid;  // 가능한 경우, 더 작은 크기를 시도
            high = mid - 1;
        } else {
            low = mid + 1;  // 불가능한 경우, 더 큰 크기를 시도
        }
    }

    // 결과 출력
    cout << result << "\n";

    return 0;
}
