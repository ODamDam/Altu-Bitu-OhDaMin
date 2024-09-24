#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++ 입출력 속도 향상
    cin.tie(NULL); // cin과 cout의 묶음을 풀어 속도 향상

    string name;
    cin >> name;

    // 알파벳 빈도수를 저장
    map<char, int> freq;
    for (char c : name) {
        freq[c]++;
    }

    // 홀수 개의 문자가 몇 개인지 확인
    int odd_count = 0;
    char odd_char = 0; // 홀수 개의 문자가 있을 경우 그것을 저장
    for (auto it : freq) {
        if (it.second % 2 != 0) {
            odd_count++;
            odd_char = it.first;
        }
    }

    // 홀수 개의 문자가 2개 이상이면 팰린드롬 불가능
    if (odd_count > 1) {
        cout << "I'm Sorry Hansoo\n"; // endl 대신 \n 사용
        return 0;
    }

    // 팰린드롬을 만들 수 있는 경우
    string first_half = "", second_half = "";

    // 알파벳을 사전순으로 정렬하며 절반을 만듦
    for (auto it : freq) {
        string temp(it.second / 2, it.first); // 절반을 채움
        first_half += temp;
    }

    // 첫 번째 절반의 반대편을 뒤집어서 팰린드롬의 두 번째 절반을 만듦
    second_half = first_half;
    reverse(second_half.begin(), second_half.end());

    // 홀수 개의 문자가 있다면 가운데 배치
    if (odd_char != 0) {
        first_half += odd_char;
    }

    // 결과 출력
    cout << first_half + second_half << '\n'; // endl 대신 \n 사용

    return 0;
}
