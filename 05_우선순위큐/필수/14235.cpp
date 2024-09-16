#include <iostream>
#include <queue>

using namespace std;

// 풀이 아이디어: 우선순위 큐를 사용하여 선물을 관리한다.
// 선물을 충전할 때마다 힙에 선물을 추가, 아이를 만날 때마다 가장 큰 값(Root값)을 꺼내서 준다.
// 없으면 -1을 출력한다.

int main() {
    ios::sync_with_stdio(false);  // 입출력 동기화 비활성화
    cin.tie(0);  // cin과 cout의 묶음 해제

    int n;
    cin >> n; // 거점 방문 횟수(n)를 입력받는다.

    // 최대 힙(우선순위 큐, 내림차순 정렬)
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a == 0) {
            // 아이를 만난 경우,
            if (pq.empty()) {
                cout << "-1" << endl;  // 선물이 없다면 '-1'을 출력한다.
            }
            else {
                cout << pq.top() << endl;  // 선물이 있다면, 가장 큰 선물(=Root)을 출력한다.
                pq.pop();  // 선물을 제거(Pop)한다.
            }
        }
        else {
            // 거점지에서 선물을 충전한다.
            for (int j = 0; j < a; j++) {
                int gift;
                cin >> gift;
                pq.push(gift);  // 선물 최대 힙에 추가
            }
        }
    }


    return 0;
}
