#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100; // 최대 사람 수
vector<int> relations[MAX + 1]; // 관계를 저장 -> 인접 리스트
int visited[MAX + 1]; // 방문 여부, 촌수를 저장하는 배열

// BFS로 두 사람 간의 촌수를 계산
int calculate_relation(int start, int target) {
    queue<int> q;
    q.push(start);
    visited[start] = 0; // 시작점: 자기 자신, 0촌

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 목표 사람에 도달하면 그때의 촌수 반환
        if (current == target) {
            return visited[current];
        }

        // 현재 사람과 연결된 사람들을 모두 확인
        for (int next : relations[current]) {
            if (visited[next] == -1) { // 아직 방문하지 않은 경우만
                visited[next] = visited[current] + 1; // 촌수 증가
                q.push(next);
            }
        }
    }

    // 목표 사람에 도달하지 못하면 -1 반환
    return -1;
}

int main() {
    ios::sync_with_stdio(false); // 입출력 최적화
    cin.tie(nullptr);

    int n; // 전체 사람 수
    cin >> n;

    int person1, person2;
    cin >> person1 >> person2; // 촌수 계산 대상

    int m; // 부모 자식 관계 수
    cin >> m;

    // 부모-자식 관계 입력
    for (int i = 0; i < m; ++i) {
        int parent, child;
        cin >> parent >> child;
        relations[parent].push_back(child);
        relations[child].push_back(parent); // 양방향으로 관계 저장
    }

    // 방문 배열을 -1로 초기화
    for (int i = 1; i <= n; ++i) {
        visited[i] = -1;
    }

    // 두 사람 간의 촌수를 계산
    int result = calculate_relation(person1, person2);

    cout << result << '\n';

    return 0;
}
