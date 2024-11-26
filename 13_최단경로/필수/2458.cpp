#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 500 + 1; // 최대 학생 수 (인덱스를 1부터 사용하기 위해 +1)

// 학생들 간의 키 비교 결과를 저장하는 행렬
bool adjacency_matrix[MAX_N][MAX_N];

void floydWarshall(int n) {
    // 플로이드-워셜 알고리즘을 사용하여 모든 학생 쌍의 키 비교 결과를 계산
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (adjacency_matrix[i][k]) {
                for (int j = 1; j <= n; j++) {
                    if (adjacency_matrix[k][j]) {
                        adjacency_matrix[i][j] = true;
                    }
                }
            }
        }
    }
}

int countKnownRanks(int n) {
    int count = 0; // 자신의 순위를 알 수 있는 학생의 수

    for (int i = 1; i <= n; i++) {
        int known_relations = 0; // i번 학생과 직접 또는 간접적으로 비교된 학생의 수

        for (int j = 1; j <= n; j++) {
            if (i == j) continue; // 자기 자신은 비교하지 않음

            // i번 학생이 j번 학생보다 작거나 큰 경우
            if (adjacency_matrix[i][j] || adjacency_matrix[j][i]) {
                known_relations++;
            }
        }

        // 자신을 제외한 모든 학생들과의 키 비교 결과를 알면 순위를 알 수 있음
        if (known_relations == n - 1) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, m; // n: 학생 수, m: 키 비교한 학생 쌍의 수
    cin >> n >> m;

    // adjacency_matrix 초기화
    for (int i = 1; i <= n; i++) {
        fill(adjacency_matrix[i], adjacency_matrix[i] + n + 1, false);
    }

    // 키 비교 결과 입력
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjacency_matrix[a][b] = true; // a번 학생이 b번 학생보다 키가 작음
    }

    // 모든 학생 쌍에 대해 키 비교 결과 계산
    floydWarshall(n);

    // 순위를 알 수 있는 학생의 수 계산
    int result = countKnownRanks(n);

    // 결과 출력
    cout << result << endl;

    return 0;
}
