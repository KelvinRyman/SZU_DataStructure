// DS树--二叉树高度
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

TreeNode *initTree(string preorder) {
  char *input = &preorder[0];
  return buildTree(input);
}

//int maxDepth(TreeNode *root) {
//  if (!root) {
//    return 0;
//  }
//  return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//}

int maxDepth_iteration(TreeNode *root) {
  if (!root) {
    return 0;
  }
  int depth = 0;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    depth++;
    int size = q.size();
    while (size--) {
      auto *node = q.front();
      q.pop();
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }
  }
  return depth;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string preorder;
    cin >> preorder;
    TreeNode *root = initTree(preorder);
    cout << maxDepth_iteration(root) << '\n';
  }

  return 0;
}
