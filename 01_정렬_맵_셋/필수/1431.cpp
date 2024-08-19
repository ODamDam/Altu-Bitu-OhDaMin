// 2271086 오다민

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// 상수 정의: 시리얼 넘버 길이는 최대 50.
const int MAX_SERIAL_LENGTH = 50;

// 숫자 합을 계산하는 함수
int sumOfDigits(const string& serial) {
    int sum = 0;
    for (char ch : serial) {
        if (isdigit(ch)) {
            sum += ch - '0';
        }
    }
    return sum;
}

// 시리얼 번호를 비교하는 사용자 정의 함수
bool compareSerials(const string& serial_a, const string& serial_b) {
    // 1. 길이가 다르면, 짧은 것이 먼저.
    if (serial_a.length() != serial_b.length()) {
        return serial_a.length() < serial_b.length();
    }

    // 2. 숫자의 합이 다르면, 작은 합을 가지는 것이 먼저.
    int sum_a = sumOfDigits(serial_a);
    int sum_b = sumOfDigits(serial_b);
    if (sum_a != sum_b) {
        return sum_a < sum_b;
    }

    // 3. 사전순으로 비교.
    return serial_a < serial_b;
}

// 시리얼 번호를 입력받고 정렬하여 출력하는 함수
void processSerialNumbers() {
    int num_serials;
    cin >> num_serials;
    vector<string> serials(num_serials);

    // 시리얼 번호 입력 받기
    for (int i = 0; i < num_serials; ++i) {
        cin >> serials[i];
    }

    // 사용자 정의 비교 함수로 정렬
    sort(serials.begin(), serials.end(), compareSerials);

    // 정렬된 시리얼 번호 출력
    for (const string& serial : serials) {
        cout << serial << endl;
    }
}

int main() {
    processSerialNumbers();
    return 0;
}
