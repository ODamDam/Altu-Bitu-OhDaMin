#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num_nephews, num_snacks;
    cin >> num_nephews >> num_snacks;

    vector<int> snack_lengths(num_snacks);
    int max_length = 0;

    for (int i = 0; i < num_snacks; ++i) {
        cin >> snack_lengths[i];
        max_length = max(max_length, snack_lengths[i]);
    }

    int low = 1, high = max_length, result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        long long total_pieces = 0;

        // 각 과자를 길이 mid로 나누어 얻을 수 있는 조각 수 계산
        for (int length : snack_lengths) {
            total_pieces += length / mid;
        }

        // 필요한 조각 수와 비교
        if (total_pieces >= num_nephews) {
            result = mid;    // 가능한 최대 길이 갱신
            low = mid + 1;   // 더 긴 길이 시도
        } else {
            high = mid - 1;  // 더 짧은 길이 시도
        }
    }

    // 결과 출력
    cout << result << "\n";

    return 0;
}
