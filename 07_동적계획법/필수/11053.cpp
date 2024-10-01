#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 입출력 시간 단축 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n; // 수열의 크기 입력

    vector<int> arr(n); // 수열을 저장할 배열
    vector<int> dp(n, 1); // 각 인덱스에서의 LIS 길이를 저장하는 DP 배열 (초기값 1)

    // 수열 입력
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 동적 프로그래밍을 이용하여 LIS 계산
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1); // 이전 값들 중에서 더 큰 값을 선택
            }
        }
    }

    // dp 배열에서 가장 큰 값이 가장 긴 증가하는 부분 수열의 길이
    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}
