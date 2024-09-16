#include <iostream>
#include <string>
#include <cstring> 

using namespace std;

// 배열을 이용하여 풀이했습니다.

void check(const string& word, int v[]) { // 영문자 26개에 대한 빈도를 계산한다.
    memset(v, 0, sizeof(int) * 26);  // 배열을 0으로 초기화
    for (char ch : word) {
        v[ch - 'A']++;  // 각 문자의 빈도를 카운트한다.
    }
}

int main() {
    int n, v[26], f[26], count = 0;
    string word; // 초기 세팅.

    cin >> n >> word; // 개수 n과 단어를 입력 받는다.
    check(word, v);  // 첫 번째 단어의 빈도를 먼저 계산한다.

    while (--n) {
        cin >> word;
        check(word, f);  // 나머지 단어들의 빈도 계산

        int plus = 0, minus = 0;
        for (int i = 0; i < 26; i++) {
            if (f[i] > v[i]) plus += f[i] - v[i];    // f[i]가 더 크면 plus 증가
            else if (f[i] < v[i]) minus += v[i] - f[i];  // v[i]가 더 크면 minus 증가
        }
        if (plus <= 1 && minus <= 1) count++;  // 조건 만족 시, 비슷한 단어라고 판단하여 카운트 증가
    }

    cout << count << endl;  // 결과 출력

    return 0;
}
