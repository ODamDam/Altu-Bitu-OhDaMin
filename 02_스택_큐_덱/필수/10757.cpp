// 2271086 오다민

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string a, b;

    // 두 큰 수를 문자열로 입력받음 <= 주어지는 정수 A, B값이 매우 크므로 C++의 기본 정수형으로는 처리할 수 없다.
    std::cin >> a >> b;

    // 두 문자열 중 길이가 짧은 쪽 앞에 0을 추가하여 두 문자열의 길이를 맞춰줌
    while (a.length() < b.length()) {
        a = "0" + a;
    }
    while (b.length() < a.length()) {
        b = "0" + b;
    }

    std::string result = "";// 결과를 저장할 문자열 result
    int carry = 0;

    // 뒤에서부터 각 자리 숫자를 더해주는 부분
    for (int i = a.length() - 1; i >= 0; --i) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;  // 다음 자리에 더할 숫자
        result += (sum % 10) + '0';  // 현재 자리에 들어갈 숫자
    }

    // 마지막 올림수가 남아있다면 추가해주기
    if (carry > 0) {
        result += carry + '0';
    }

    // 더한 결과는 역순이므로 reverse 해줌
    std::reverse(result.begin(), result.end());

    std::cout << result << std::endl;// 최종 결과 출력

    return 0;
}
