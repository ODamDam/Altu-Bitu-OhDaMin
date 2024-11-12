#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

pair<int, int> findMinMaxLengths(const string& w, int k) {
    int min_length = INT_MAX;
    int max_length = -1;

    // 각 문자의 위치를 저장
    vector<vector<int>> char_positions(26);

    // 각 문자의 위치를 char_positions에 저장
    for (int i = 0; i < w.size(); i++) {
        char_positions[w[i] - 'a'].push_back(i);
    }

    // 각 문자별 위치 리스트에서 K개씩 연속한 위치 간의 거리 계산
    for (int i = 0; i < 26; i++) {
        if (char_positions[i].size() < k) continue; // 해당 문자가 K번 미만 등장 시 건너뜀

        // 해당 문자의 위치에서 K개 연속 부분 문자열의 길이 계산
        for (int j = 0; j <= char_positions[i].size() - k; j++) {
            int length = char_positions[i][j + k - 1] - char_positions[i][j] + 1;

            min_length = min(min_length, length);
            max_length = max(max_length, length);
        }
    }

    // 가능한 문자열이 없을 경우 -1 반환
    if (min_length == INT_MAX) min_length = -1;
    if (max_length == -1) max_length = -1;

    return {min_length, max_length};
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string w;
        int k;
        cin >> w >> k;

        pair<int, int> result = findMinMaxLengths(w, k);

        // 둘 다 -1일 경우 단일 -1만 출력
        if (result.first == -1 && result.second == -1) {
            cout << -1 << '\n';
        } else {
            cout << result.first << " " << result.second << '\n';
        }
    }

    return 0;
}
