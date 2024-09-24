#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // 행성 개수를 저장할 변수
    cin >> n; // 행성 개수 입력

    vector<int> nums(n); // 각 행성의 속도를 저장할 벡터
    for (int i = 0; i < n; ++i) {
        cin >> nums[i]; // 각 행성의 속도 입력
    }

    long long speed = nums[n - 1]; // 마지막 행성의 속도로 초기화

    for (int i = n - 2; i >= 0; --i) { // 뒤에서 두 번째부터 역순으로 탐색
        if (nums[i] > speed) { // 현재 행성의 속도가 speed보다 크면
            speed = nums[i]; // speed를 현재 행성의 속도로 업데이트
        } else { // speed가 더 크거나 작다면
            if (speed % nums[i] != 0) { // speed가 현재 행성 속도의 정수배가 되지 않으면
                speed = (speed / nums[i] + 1) * nums[i]; // 최소값으로 업데이트
            }
        }
    }

    cout << speed << '\n'; // 최종 속도 출력
    return 0; // 프로그램 종료
}
