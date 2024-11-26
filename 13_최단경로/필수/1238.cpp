#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

// 무한대를 나타내기 위한 상수
const int INF = numeric_limits<int>::max();

// 그래프의 간선을 표현하는 구조체
struct Edge {
    int target; // 연결된 노드
    int weight; // 해당 간선의 가중치
};

// 다익스트라 알고리즘 함수
// 주어진 시작점(start)에서 다른 모든 노드까지의 최단 거리를 계산
vector<int> dijkstra(int start, const vector<vector<Edge>>& graph) {
    int n = graph.size(); // 그래프의 크기 (노드 수)
    vector<int> distance(n, INF); // 시작점으로부터의 최단 거리를 저장 (초기값은 무한대)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;

    distance[start] = 0; // 시작점까지의 거리는 0
    min_heap.push({0, start}); // 우선순위 큐에 {거리, 노드} 형태로 추가

    while (!min_heap.empty()) {
        int current_dist = min_heap.top().first; // 현재 노드까지의 거리
        int current_node = min_heap.top().second; // 현재 노드
        min_heap.pop();

        // 큐에서 꺼낸 거리 정보가 이미 최적 거리보다 크다면 무시
        if (current_dist > distance[current_node]) {
            continue;
        }

        // 현재 노드와 연결된 모든 인접 노드 탐색
        for (const auto& edge : graph[current_node]) {
            int next_node = edge.target; // 다음 노드
            int new_dist = current_dist + edge.weight; // 새로운 거리 계산

            // 더 짧은 경로를 발견하면 최단 거리 갱신
            if (new_dist < distance[next_node]) {
                distance[next_node] = new_dist; // 최단 거리 업데이트
                min_heap.push({new_dist, next_node}); // 큐에 새로운 거리와 노드 추가
            }
        }
    }

    return distance; // 시작점에서 각 노드까지의 최단 거리 배열 반환
}

int main() {
    int n, m, x;
    cin >> n >> m >> x; // n: 마을의 수, m: 도로의 수, x: 파티가 열리는 마을 번호

    // 그래프와 역방향 그래프를 저장할 2차원 벡터
    vector<vector<Edge>> graph(n + 1); // 정방향 그래프 (1번 마을부터 시작)
    vector<vector<Edge>> reverse_graph(n + 1); // 역방향 그래프 (X로 돌아오는 경로 계산용)

    // 도로 정보 입력
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t; // u에서 v로 가는 도로의 소요 시간 t
        graph[u].push_back({v, t}); // 정방향 그래프에 추가
        reverse_graph[v].push_back({u, t}); // 역방향 그래프에 추가
    }

    // X로 가는 최단 거리 계산 (모든 마을 -> X)
    vector<int> to_x = dijkstra(x, reverse_graph);

    // X에서 오는 최단 거리 계산 (X -> 모든 마을)
    vector<int> from_x = dijkstra(x, graph);

    // 왕복 시간이 가장 오래 걸리는 학생의 왕복 시간 계산
    int max_time = 0; // 왕복 시간의 최대값을 저장할 변수
    for (int i = 1; i <= n; i++) {
        max_time = max(max_time, to_x[i] + from_x[i]); // 각 학생의 왕복 시간 계산
    }

    // 결과 출력
    cout << max_time << "\n"; // 왕복 시간이 가장 오래 걸리는 학생의 시간 출력

    return 0;
}
