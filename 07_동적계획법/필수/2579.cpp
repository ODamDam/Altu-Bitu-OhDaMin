#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 입출력 시간 단축을 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int numOfStairs; // 계단 수
    cin >> numOfStairs;

    int stairs[301] = {0}; // 계단 점수 배열 (최대 300)
    int maxScore[301] = {0}; // 각 계단까지의 최댓값을 저장할 배열

    // 계단 점수 입력
    for (int i = 1; i <= numOfStairs; i++) {
        cin >> stairs[i];
    }

    // 첫 번째 계단 초기화
    maxScore[1] = stairs[1];
    
    // 두 번째 계단 초기화
    if (numOfStairs > 1) {
        maxScore[2] = stairs[1] + stairs[2];
    }

    // 세 번째 계단부터는 규칙에 따라 계산
    for (int i = 3; i <= numOfStairs; i++) {
        // 세 개 연속 밟는 것을 피하기 위해 maxScore[i-2]에서 오는 경우와
        // maxScore[i-3]에서 두 개 연속 밟는 경우 중 큰 값 선택
        maxScore[i] = max(maxScore[i-2] + stairs[i], maxScore[i-3] + stairs[i-1] + stairs[i]);
    }

    // 마지막 계단까지의 최댓값 출력
    cout << maxScore[numOfStairs] << '\n';

    return 0;
}
