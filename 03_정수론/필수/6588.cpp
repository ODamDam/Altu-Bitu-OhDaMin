#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 충분히 큰 크기의 상수 설정. 최대값에 대한 안전 장치로 사용.
const int MAX_PRIME_LIST_SIZE = 1000000;

// 홀수에 대한 소수 여부를 저장하는 벡터. 
// 인덱스 i는 숫자 (2*i + 3)와 대응됨.
vector<bool> prime_num_list(MAX_PRIME_LIST_SIZE / 2, true);

// 주어진 최대 값에 대해 소수 리스트를 생성하는 함수
void makePrimeNumList(int max_value) {
    // 3부터 시작하여 max_value의 제곱근까지 반복
    for (int i = 3; i * i < max_value; i += 2) {
        // i가 소수인 경우, i의 배수들 (홀수)에 대해 소수 여부를 false로 설정
        if (prime_num_list[i / 2]) {
            for (int j = i * i; j < max_value; j += 2 * i) {
                prime_num_list[j / 2] = false;
            }
        }
    }
}

// 주어진 숫자가 소수인지 여부를 확인하는 함수
bool isPrime(int number) {
    if (number <= 1) return false; // 1 이하의 숫자는 소수가 아님
    if (number == 2 || number == 3) return true; // 2와 3은 소수
    if (number % 2 == 0) return false; // 짝수는 소수가 아님
    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) return false; // 나누어떨어지면 소수가 아님
    }
    return true; // 소수임
}

// 주어진 숫자에 대해 Goldbach's conjecture에 따라 두 소수의 합으로 표현되는지 확인하는 함수
void findPrimeNumPair(int n) {
    // 3 ~ n/2 loop
    for (int i = 3; i <= n / 2; i += 2) {
        // i와 n-i가 모두 prime
        if (prime_num_list[i / 2] && prime_num_list[(n - i) / 2]) {
            cout << n << " = " << i << " + " << n - i << '\n'; // 출력
            return;
        }
    }
    // no pair
    cout << "Goldbach's conjecture is wrong." << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); // C++ 표준 입출력과의 동기화 비활성화
    cin.tie(NULL); // cin과 cout의 동기화 비활성화
    cout.tie(NULL); // cout과 cin의 동기화 비활성화

    int input_value;
    vector<int> inputs; // 입력된 숫자들을 저장하는 벡터
    int max_value = 0;  // 입력된 숫자들 중 최대값을 저장하는 변수

    // 입력을 읽어서 inputs 벡터에 저장하고, 최대값을 갱신
    while (cin >> input_value && input_value != 0) {
        inputs.push_back(input_value);
        if (input_value > max_value) {
            max_value = input_value;
        }
    }

    // 입력된 최대값보다 큰 숫자에 대해서만 소수 리스트를 생성
    if (max_value > 2) {
        makePrimeNumList(max_value);
    }

    // 각 입력 값에 대해 소수 쌍을 찾고 결과를 출력
    for (int value : inputs) {
        findPrimeNumPair(value);
    }

    return 0;
}
