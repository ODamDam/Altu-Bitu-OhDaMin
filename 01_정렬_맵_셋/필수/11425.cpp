// 2271086 오다민

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

void processStrings() {
    int n, m;
    cin >> n >> m;

    unordered_set<string> string_set;
    string input_str;
    
    // 집합 S에 포함된 문자열을 입력 받음
    for (int i = 0; i < n; ++i) {
        cin >> input_str;
        string_set.insert(input_str);
    }

    int count = 0;
    
    // 검사할 문자열을 입력 받음
    for (int i = 0; i < m; ++i) {
        cin >> input_str;
        if (string_set.find(input_str) != string_set.end()) {
            ++count;
        }
    }
    
    // 결과 출력
    cout << count << endl;
}

int main() {// 메인 함수
    processStrings();
    return 0;
}
