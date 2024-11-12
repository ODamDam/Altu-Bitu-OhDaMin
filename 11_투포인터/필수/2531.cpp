#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int calcMaxSushi(const vector<int>& belt, int n, int d, int k, int c) {
    unordered_map<int, int> sushi_count; // 각 초밥의 등장 횟수를 저장하는 해시 맵
    int distinct_sushi = 0, max_sushi = 0;

    // 초기 k개의 초밥에 대해 처리
    for (int i = 0; i < k; i++) {
        if (sushi_count[belt[i]] == 0) distinct_sushi++;
        sushi_count[belt[i]]++;
    }

    max_sushi = distinct_sushi;
    if (sushi_count[c] == 0) max_sushi++; // 쿠폰 초밥 추가

    // 슬라이딩 윈도우로 나머지 경우 탐색
    for (int i = 1; i < n; i++) {
        int remove_idx = i - 1;
        int add_idx = (i + k - 1) % n;

        // 이전 초밥 제거
        if (--sushi_count[belt[remove_idx]] == 0) distinct_sushi--;

        // 새 초밥 추가
        if (sushi_count[belt[add_idx]]++ == 0) distinct_sushi++;

        int current_max = distinct_sushi;

        if (sushi_count[c] == 0) current_max++; // 쿠폰 초밥 추가

        max_sushi = max(max_sushi, current_max);
    }

    return max_sushi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 회전 초밥 벨트에 놓인 접시의 수 n, 초밥 가짓수 d, 연속해서 먹는 접시 수 k, 쿠폰 번호 c
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> belt(n);
    for (int i = 0; i < n; i++) {
        cin >> belt[i];
    }

    cout << calcMaxSushi(belt, n, d, k, c) << '\n';
    return 0;
}
