// DS二叉树——二叉树之父子结点
#include <iostream>
using namespace std;

struct TreeNode {
  char val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

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

void preorderTraversal(TreeNode *root) {
  if (!root) {
    return;
  }

  if (!root->left && !root->right) {
    cout << root->val << ' ';
  }
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void Father_SonNode(TreeNode *node) {
  if (!node) {
    return;
  }
  Father_SonNode(node->left);
  Father_SonNode(node->right);
  if (node->left && !node->left->left && !node->left->right) {
    cout << node->val << ' ';
  }
  if (node->right && !node->right->left && !node->right->right) {
    cout << node->val << ' ';
  }
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
    preorderTraversal(root);
    cout << '\n';
    Father_SonNode(root);
    cout << '\n';
  }

  return 0;
}