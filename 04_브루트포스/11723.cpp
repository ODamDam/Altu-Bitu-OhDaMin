#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M;
    cin >> M;

    int S = 0; // S는 집합을 비트마스크로 표현하는 정수로, 각 비트는 집합의 원소가 포함되어 있는지를 나타낸다.

    while (M--) {
        string command;
        int x;
        cin >> command;

        if (command == "add") { // 비트 설정
            cin >> x;
            S |= (1 << (x - 1)); // x번째 비트를 1로 설정한 값을 반환 -> x를 집합에 추가
        } 
        else if (command == "remove") { // 비트 해제
            cin >> x;
            S &= ~(1 << (x - 1)); // x번째 비트를 0으로 설정한 값을 반환 -> x를 집합에서 제거
        } 
        else if (command == "check") { // 비트 체크
				    cin >> x;
				    cout << ((S & (1 << (x - 1))) != 0) << '\n'; // x가 집합에 있는지 확인. 결과가 0이 아니면 x가 집합에 포함되어 있는 것.
				}
        else if (command == "toggle") { // 비트 반전
            cin >> x;
            S ^= (1 << (x - 1)); // x가 있으면 제거하고, 없으면 추가
        } 
        else if (command == "all") { // 집합 전체
            S = (1 << 20) - 1; // 집합을 {1, 2, ..., 20}으로 설정. (1 << 20)는 20개의 비트가 0인 값을 생성하고, - 1은 이 값을 모두 1로 만듦.
        } 
        else if (command == "empty") {
            S = 0; // 집합을 공집합으로 설정 -> 모든 비트를 0으로 만듦
        }
    }

    return 0;
}