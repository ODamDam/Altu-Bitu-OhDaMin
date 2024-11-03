#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> times(n);
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }

    // 이분 탐색 범위 설정
    long long low = 1;
    long long high = *max_element(times.begin(), times.end()) * m;
    long long result = high;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long people_processed = 0;

        // 각 심사대가 mid 시간 동안 처리할 수 있는 인원 계산
        for (long long time : times) {
            people_processed += mid / time;
            if (people_processed >= m) break; // 필요한 인원 이상 처리할 수 있으면 종료
        }

        // M명 이상을 처리할 수 있는 경우, 시간 줄이기 시도
        if (people_processed >= m) {
            result = mid;
            high = mid - 1;
        } else { // M명 미만인 경우, 시간을 늘려야 함
            low = mid + 1;
        }
    }

    // 결과 출력
    cout << result << "\n";

    return 0;
}
