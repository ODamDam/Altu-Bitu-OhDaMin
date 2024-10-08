#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100; // 최대 컴퓨터 개수
vector<int> network[MAX + 1]; // 네트워크 연결 정보
bool visited[MAX + 1]; // 방문 여부 확인 배열
int infected_count = 0; // 감염된 컴퓨터 수

// DFS로 바이러스 전파 탐색
void dfs(int computer) {
    visited[computer] = true;
    infected_count++; // 감염된 컴퓨터 수 증가

    // 현재 컴퓨터와 연결된 다른 컴퓨터 탐색
    for (int next : network[computer]) {
        if (!visited[next]) { // 아직 방문하지 않은 컴퓨터라면
            dfs(next); // 해당 컴퓨터로 이동
        }
    }
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(nullptr);

    int n; // 컴퓨터 수
    cin >> n;

    int m; // 네트워크 상에서 연결된 컴퓨터 쌍 개수
    cin >> m;

    // 네트워크 연결 정보 입력
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        network[u].push_back(v);
        network[v].push_back(u); // 양방향 연결
    }

    // DFS로 1번 컴퓨터에서 바이러스 전파 시작
    dfs(1);

    // 1번 컴퓨터는 제외하고 출력해야 하므로 -1을 해 줘야 한다.
    cout << infected_count - 1 << '\n';

    return 0;
}
