#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> // math.h 대신 cmath 사용

using namespace std;

vector<long long> findClosestToZero(const vector<long long>& arr, int num) {
    long long result = 3000000001; // 초기값 설정 (0에 가까운 값을 찾기 위해)
    vector<long long> ans(3); // 결과를 저장할 벡터

    // 배열을 오름차순으로 정렬
    vector<long long> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    // 첫 번째 포인터(k)를 고정하고, 두 번째 포인터(l)와 세 번째 포인터(r)를 사용해 탐색
    for (int k = 0; k < num - 2; k++) {
        int l = k + 1;
        int r = num - 1;

        while (l < r) {
            long long val = sorted_arr[k] + sorted_arr[l] + sorted_arr[r];

            // 절대값을 비교하여 0에 더 가까운 값을 찾으면 결과 갱신
            if (abs(val) < result) {
                result = abs(val);
                ans[0] = sorted_arr[k];
                ans[1] = sorted_arr[l];
                ans[2] = sorted_arr[r];
            }

            // 합이 0 미만: 왼쪽 포인터 이동
            if (val < 0) {
                l++;
            }
            // 합이 0 이상: 오른쪽 포인터 이동
            else {
                r--;
            }
        }
    }

    return ans; // 최종 결과 반환
}

int main() {
    
    int num;
    cin >> num;

    vector<long long> arr(num);
    for (int i = 0; i < num; i++)
        cin >> arr[i];

    // findClosestToZero 함수를 호출
    vector<long long> result = findClosestToZero(arr, num);

    // 오름차순 정렬된 결과만 출력
    cout << result[0] << " " << result[1] << " " << result[2] << '\n';

    return 0;
}
