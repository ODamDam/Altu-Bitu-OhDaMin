#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
vector<int> numbers;
vector<int> sequence;
set<vector<int>> result_set;  // 중복을 방지하기 위한 set

// 중복을 허용하여 M개의 수를 고른 수열을 저장하는 백트래킹 함수
void generate_sequence(int depth) {
    if (depth == m) {
        result_set.insert(sequence);  // 중복이 없도록 set에 저장
        return;
    }

    for (int i = 0; i < n; i++) {
        sequence[depth] = numbers[i];
        generate_sequence(depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);  // 입출력 성능 최적화
    cin.tie(nullptr);                  // 입출력 성능 최적화

    cin >> n >> m;
    numbers.resize(n);
    sequence.resize(m);

    // 수 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // 사전 순 출력을 위해 정렬
    sort(numbers.begin(), numbers.end());

    // 수열 생성 시작
    generate_sequence(0);

    // 저장된 결과를 출력
    for (const auto& seq : result_set) {
        for (int num : seq) {
            cout << num << ' ';
        }
        cout << '\n';
    }

    return 0;
}
