#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 최대값과 최소값을 저장할 변수
int max_result = -1e9;  // -10억
int min_result = 1e9;   // 10억

// 백트래킹을 위한 함수
void calculate(int idx, int current_value, vector<int>& numbers, vector<int>& operators) {
    // 모든 숫자를 다 사용한 경우, 최댓값과 최솟값 갱신
    if (idx == numbers.size()) {
        max_result = max(max_result, current_value);
        min_result = min(min_result, current_value);
        return;
    }


    // 4개의 연산자에 대해 반복문으로 처리
    for (int i = 0; i < 4; ++i) {
        if (operators[i] > 0) {  // 해당 연산자가 남아 있는 경우에만 수행
            operators[i]--;  // 연산자 사용

            // 연산에 따른 계산 수행
            if (i == 0) {
                // 덧셈
                calculate(idx + 1, current_value + numbers[idx], numbers, operators);
            } else if (i == 1) {
                // 뺄셈
                calculate(idx + 1, current_value - numbers[idx], numbers, operators);
            } else if (i == 2) {
                // 곱셈
                calculate(idx + 1, current_value * numbers[idx], numbers, operators);
            } else if (i == 3) {
                // 나눗셈 (C++14의 음수 나눗셈 처리 포함)
                if (current_value < 0) {
                    calculate(idx + 1, -(-current_value / numbers[idx]), numbers, operators);
                } else {
                    calculate(idx + 1, current_value / numbers[idx], numbers, operators);
                }
            }

            operators[i]++;  // 백트래킹 후 연산자 복구
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);  // 입출력 성능 최적화
    cin.tie(nullptr);                  // 입출력 성능 최적화

    int n;  // 숫자의 개수
    cin >> n;

    vector<int> numbers(n);  // 숫자들을 저장하는 벡터
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    vector<int> operators(4);  // 연산자들의 개수: 덧셈, 뺄셈, 곱셈, 나눗셈 순
    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    // 백트래킹 시작
    calculate(1, numbers[0], numbers, operators);

    // 결과 출력
    cout << max_result << '\n' << min_result << '\n';

    return 0;
}
