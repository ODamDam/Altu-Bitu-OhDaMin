#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0; // 찾은 종말의 수 개수를 셀 변수로 count를 선언
    int num = 666; // 666부터 시작해도 됨

    // N번째 종말의 수를 찾을 때까지 반복
    while (true) {
        // 숫자를 문자열로 변환하여 "666"이 포함되는지 확인
        string str = to_string(num);
        if (str.find("666") != string::npos) { // "666"이 포함되어 있는 경우
            count++; // -> 찾은 종말의 수 개수 증가
        }

        // N번째 종말의 수를 찾은 경우, 출력 및 종료
        if (count == N) {
            cout << num << endl;
            break;
        }

        num++; // 다음 숫자 검사
    }

    return 0;
}
