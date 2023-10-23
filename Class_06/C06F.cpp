// DS二叉树——二叉树之数组存储
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree_fromArray(int tree[], int index, const int &n) {
  if (tree[index] == 0 || index > n) {
    return nullptr;
  } else {
    auto *newNode = new TreeNode(tree[index]);
    newNode->left = buildTree_fromArray(tree, 2 * index, n);
    newNode->right = buildTree_fromArray(tree, 2 * index + 1, n);
    return newNode;
  }
}

void preorderTraversal_iteration(TreeNode *root) {
  if (!root) {
    return;
  }
  stack<TreeNode *> nodeStack;
  nodeStack.push(root);

  while (!nodeStack.empty()) {
    TreeNode *node = nodeStack.top();
    nodeStack.pop();
    cout << node->val << ' ';

    if (node->right) {
      nodeStack.push(node->right);
    }
    if (node->left) {
      nodeStack.push(node->left);
    }
  }
}

void freeTree_iteration(TreeNode *root) {
  if (!root) {
    return;
  }

  stack<TreeNode *> nodeStack;
  TreeNode *current = root;
  while (current || !nodeStack.empty()) {
    while (current) {
      nodeStack.push(current);
      current = current->left;
    }

    current = nodeStack.top();
    nodeStack.pop();
    TreeNode *temp = current;
    current = current->right;

    delete temp;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int treeArr[n + 1];

    for (int i = 1; i <= n; i++) {
      cin >> treeArr[i];
    }

    auto *root = buildTree_fromArray(treeArr, 1, n);
    preorderTraversal_iteration(root);
    cout << '\n';
    freeTree_iteration(root);
  }

  return 0;
}
