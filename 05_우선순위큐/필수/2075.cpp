#include <iostream>
#include <queue>
#include <vector> 

using namespace std;

// 풀이 아이디어: 먼저 우선순위 큐에 N개의 수를 삽입하고, N개 이상의 수가 들어가면 항상 최솟값을 제거하는 방식으로 큐의 크기가 N을 초과하지 않도록 관리

int main() {
    ios::sync_with_stdio(false);  // 입출력 동기화 비활성화
    cin.tie(0);  // cin과 cout의 묶음 해제

    int N;
    cin >> N; // N을 입력받는다.

    // 최소 힙(우선순위 큐)
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N * N; i++) {
        int num;
        cin >> num;

        // 최소 힙에 숫자를 넣는다.
        pq.push(num);

        // 힙 크기가 N을 초과하면 가장 작은 값을 제거한다.
        if (static_cast<int>(pq.size()) > N) {
            pq.pop();
        }
    }

    // N번째로 큰 수 = 최소 힙의 Root에 남아 있는 수이므로 출력한다.
    cout << pq.top() << endl;

    return 0;
}
