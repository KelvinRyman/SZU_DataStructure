// DS二叉树–左叶子数量
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  char val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

// 迭代创建二叉树
//TreeNode *buildTree(const string &preorder) {
//  stack<TreeNode *> nodeStack;
//  TreeNode *root = new TreeNode(preorder[0]);
//  nodeStack.push(root);
//
//  for (int i = 1; i < preorder.size(); i++) {
//    if (preorder[i] != '#') {
//      TreeNode *newNode = new TreeNode(preorder[i]);
//      if (nodeStack.top()->left == NULL) {
//        nodeStack.top()->left = newNode;
//        nodeStack.push(newNode);
//      } else if (nodeStack.top()->right == NULL) {
//        nodeStack.top()->right = newNode;
//        nodeStack.pop();
//        nodeStack.push(newNode);
//      }
//    } else {
//      if (nodeStack.top()->left == NULL) {
//        nodeStack.top()->left = NULL;
//      } else {
//        nodeStack.top()->right = NULL;
//      }
//    }
//  }
//
//  return root;
//}

TreeNode *buildTree(char *&preorder) {
  char val = *preorder;
  preorder++;
  if (val == '0') {
    return nullptr;
  }

  auto *node = new TreeNode(val);
  node->left = buildTree(preorder);
  node->right = buildTree(preorder);
  return node;
}

int countLeftLeaves(TreeNode *root, bool isLeft) {
  if (!root) {
    return 0;
  }

  if (!root->left && !root->right && isLeft) {
    return 1;
  }

  int leftCount = countLeftLeaves(root->left, true);
  int rightCount = countLeftLeaves(root->right, false);

  return leftCount + rightCount;
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
    auto *root = buildTree(input);

    int leftLeaves = countLeftLeaves(root, false);
    cout << leftLeaves << '\n';
  }

  return 0;
}