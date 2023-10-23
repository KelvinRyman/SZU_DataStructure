// DS二叉树——层次遍历
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
  char val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(char *&preorder) {
  char val = *preorder++;
  if (val == '0') {
    return nullptr;
  }

  auto *newNode = new TreeNode(val);
  newNode->left = buildTree(preorder);
  newNode->right = buildTree(preorder);
  return newNode;
}

void levelTraversal(TreeNode *root) {
  if (!root) {
    return;
  }

  queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);
  while (!nodeQueue.empty()) {
    TreeNode *node = nodeQueue.front();
    nodeQueue.pop();
    cout << node->val;
    if (node->left) {
      nodeQueue.push(node->left);
    }
    if (node->right) {
      nodeQueue.push(node->right);
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string preorder;
    cin >> preorder;
    char *input = &preorder[0];
    TreeNode *root = buildTree(input);

    levelTraversal(root);
  }

  return 0;
}