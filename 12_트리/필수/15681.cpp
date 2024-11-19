#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100000; // 최대 정점 수

vector<int> tree[MAX_N + 1]; // 트리의 연결 관계를 저장하는 인접 리스트
int subtree_size[MAX_N + 1]; // 각 정점을 루트로 하는 서브트리의 정점 수
bool visited[MAX_N + 1];     // 방문 여부를 기록하는 배열

// 서브트리 크기를 계산하는 함수
int calculateSubtreeSize(int node) {
    visited[node] = true; // 현재 정점을 방문 표시
    subtree_size[node] = 1; // 자신도 자신의 서브트리에 포함되므로 1로 시작

    for (int neighbor : tree[node]) {
        if (!visited[neighbor]) { // 아직 방문하지 않은 자식 노드
            subtree_size[node] += calculateSubtreeSize(neighbor); // 자식 서브트리 크기를 더함
        }
    }

    return subtree_size[node]; // 최종 서브트리 크기를 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, q; // 정점 수, 루트 번호, 쿼리 수
    cin >> n >> r >> q;

    // 트리 입력
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u); // 무향 그래프이므로 양방향 간선
    }

    // 서브트리 크기 계산
    calculateSubtreeSize(r);

    // 쿼리 처리
    while (q--) {
        int u;
        cin >> u;
        cout << subtree_size[u] << "\n"; // 각 쿼리 결과 출력
    }

    return 0;
}
