#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findLongestSubarray(const vector<int>& sequence, int n, int k) {
    unordered_map<int, int> count_map; // 각 원소의 등장 횟수를 저장하는 해시 맵
    int left = 0, max_length = 0; // 투 포인터의 왼쪽(left)과 최대 길이(max_length)

    // 오른쪽 포인터를 이동하면서 조건을 만족하는 부분 수열의 길이 계산
    for (int right = 0; right < n; right++) {
        int num = sequence[right];
        count_map[num]++; // 현재 원소의 등장 횟수 증가

        // 현재 원소가 K번 초과로 등장할 경우 왼쪽 포인터 이동
        while (count_map[num] > k) {
            count_map[sequence[left]]--; // 왼쪽 포인터가 가리키는 원소의 등장 횟수 감소
            left++; // 왼쪽 포인터 오른쪽으로 이동
        }

        // 조건을 만족하는 부분 수열의 길이 갱신
        max_length = max(max_length, right - left + 1);
    }

    return max_length;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    cout << findLongestSubarray(sequence, n, k) << '\n';

    return 0;
}
