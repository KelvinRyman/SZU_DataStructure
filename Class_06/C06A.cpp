// DS二叉树—二叉树构建与遍历（不含框架）
#include <iostream>
using namespace std;

struct TreeNode {
  char val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(string &preorder, int &index) {
  if (preorder.empty()) {
    return nullptr;
  }

  char val = preorder[index++];
  if (val == '#') {
    return nullptr;
  } else {
    auto *node = new TreeNode(val);
    node->left = buildTree(preorder, index);
    node->right = buildTree(preorder, index);
    return node;
  }
}

TreeNode *initTree(string &preorder) {
  int index = 0;
  return buildTree(preorder, index);
}

void preorderTraversal(TreeNode *root) {
  if (root) {
    cout << root->val;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

void inorderTraversal(TreeNode *root) {
  if (root) {
    inorderTraversal(root->left);
    cout << root->val;
    inorderTraversal(root->right);
  }
}

void postorderTraversal(TreeNode *root) {
  if (root) {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val;
  }
}

void freeTree(struct TreeNode *root) {
  if (root) {
    freeTree(root->left);
    freeTree(root->right);
    delete root;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> m;

  while (m--) {
    string preorder;
    cin >> preorder;
    TreeNode *root = initTree(preorder);
    preorderTraversal(root);
    cout << '\n';
    inorderTraversal(root);
    cout << '\n';
    postorderTraversal(root);
    cout << '\n';
    freeTree(root);
  }

  return 0;
}
