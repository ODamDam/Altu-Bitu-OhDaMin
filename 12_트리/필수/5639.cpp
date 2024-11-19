#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

// 트리를 구성하는 함수
TreeNode* buildTree(vector<int>& preorder, int& index, int min_value, int max_value) {
    if (index >= preorder.size()) {
        return nullptr;
    }

    int current_value = preorder[index];
    if (current_value < min_value || current_value > max_value) {
        return nullptr;
    }

    // 현재 값을 사용하여 노드 생성
    TreeNode* node = new TreeNode(current_value);
    index++; // 다음 값을 처리

    // 왼쪽과 오른쪽 서브트리 재귀적으로 구성
    node->left = buildTree(preorder, index, min_value, current_value);
    node->right = buildTree(preorder, index, current_value, max_value);

    return node;
}

// 후위 순회를 수행하여 결과 출력
void postorderTraversal(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->value << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> preorder;
    int value;
    while (cin >> value) {
        preorder.push_back(value);
    }

    int index = 0;
    TreeNode* root = buildTree(preorder, index, INT_MIN, INT_MAX);

    postorderTraversal(root);

    return 0;
}
