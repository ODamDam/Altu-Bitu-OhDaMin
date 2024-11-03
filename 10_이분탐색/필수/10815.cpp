#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);  // 입출력 속도 최적화
    cin.tie(NULL);

    int n, m;
    cin >> n;
    
    unordered_set<int> card_set;
    int card;

    // 상근이가 가진 숫자 카드를 입력받아 집합에 저장
    for (int i = 0; i < n; ++i) {
        cin >> card;
        card_set.insert(card);
    }

    cin >> m;
    int query;
    
    // 질의에 대한 결과를 저장할 문자열
    string result;

    // 각 질의에 대해 상근이가 해당 숫자를 가지고 있는지 확인
    for (int i = 0; i < m; ++i) {
        cin >> query;
        if (card_set.find(query) != card_set.end()) {
            result += "1 ";
        } else {
            result += "0 ";
        }
    }

    // 결과 출력
    cout << result << "\n";

    return 0;
}
