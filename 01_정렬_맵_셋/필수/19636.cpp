#include <iostream>
#include <cmath>
using namespace std;

typedef pair<int, int> ci;

// 다이어트 진행 시 체중과 기초 대사량을 계산하는 함수
ci diet(int D, int W0, int I, int I0, int T, int A) {
    while (D--) {
        int dailyEnergyExpenditure = I0 + A; // 일일 에너지 소비량
        W0 += (I - dailyEnergyExpenditure); // 체중 변화

        // 기초 대사량 변화 계산
        if (abs(I - dailyEnergyExpenditure) > T) {
            I0 += floor((double)(I - dailyEnergyExpenditure) / 2);
        }

        // 사망 조건 확인
        if (W0 <= 0 || I0 <= 0) {
            return ci(0, 0);
        }
    }
    return ci(W0, I0);
}

int main() {
    int W0, I0, T, D, I, A;
    cin >> W0 >> I0 >> T; // 다이어트 전 체중(W0), 일일 에너지 섭취량(I0), 기초 대사량(I0), 기초 대사량 변화 역치(T)
    cin >> D >> I >> A; // 다이어트 기간(D), 다이어트 기간 일일 에너지 섭취량(I), 일일 활동 대사량(A)

    // 1) 기초 대사량 변화를 고려하지 않은 경우
    int finalWeightWithoutChange = W0 + (I - (I0 + A)) * D;
    if (finalWeightWithoutChange <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        cout << finalWeightWithoutChange << " " << I0 << "\n";
    }

    // 2) 기초 대사량 변화를 고려한 경우
    ci result = diet(D, W0, I, I0, T, A);
    if (result.first <= 0 || result.second <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        // 요요 여부를 확인
        string yoYo = (I0 > result.second) ? "YOYO" : "NO";
        cout << result.first << " " << result.second << " " << yoYo << "\n";
    }

    return 0;
}
