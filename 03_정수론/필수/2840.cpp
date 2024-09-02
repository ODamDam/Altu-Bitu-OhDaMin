#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// 함수 선언
bool processCircle(vector<char>& circle, int& currentIndex, int n, int k);
void printResult(const vector<char>& circle, int n, int currentIndex);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<char> circle(n, '?'); // 원의 상태를 저장하는 벡터
    int currentIndex = 0;

    // 원의 상태를 처리하는 함수 호출
    if (processCircle(circle, currentIndex, n, k)) {
        // 문자의 중복을 확인하는 배열
        vector<bool> chk(26, false);
        for (int i = 0; i < n; ++i) {
            if (circle[i] == '?') continue;
            if (chk[circle[i] - 'A']) {
                cout << "!" << endl;
                return 0;
            }
            chk[circle[i] - 'A'] = true;
        }

        // 원의 상태 출력
        printResult(circle, n, currentIndex);
    }
    else {
        cout << "!" << endl;
    }

    return 0;
}

// 원의 상태를 처리하는 함수
bool processCircle(vector<char>& circle, int& currentIndex, int n, int k) {
    for (int i = 0; i < k; ++i) {
        int step;
        char ch;
        cin >> step >> ch;

        // 현재 위치에서 step만큼 왼쪽으로 이동
        int nextIndex = ((currentIndex - step) % n + n) % n;

        if (circle[nextIndex] == '?') {
            circle[nextIndex] = ch;
        }
        else if (circle[nextIndex] != ch) {
            return false; // 모순 -> false 반환
        }

        currentIndex = nextIndex;
    }

    return true; // 모든 검사가 통과 -> true 반환
}

// 원의 상태 출력
void printResult(const vector<char>& circle, int n, int currentIndex) {
    for (int i = 0; i < n; ++i) {
        cout << circle[(currentIndex + i) % n];
    }
    cout << endl;
}
