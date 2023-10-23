// DS二叉树——二叉树之父子结点
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
  char val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

void preOrder(TreeNode *root, queue<TreeNode *> &leaf, queue<TreeNode *> &parent) {
  if (!root) {
    return;
  }

  preOrder(root->left, leaf, parent);
  if (root->left && !root->left->left && !root->left->right) {
    leaf.push(root->left);
    parent.push(root);
  }
  if (root->right && !root->right->left && !root->right->right) {
    leaf.push(root->right);
    parent.push(root);
  }
  preOrder(root->right, leaf, parent);
}

TreeNode *buildTree() {
  char val;
  cin >> val;
  if (val == '0') {
    return nullptr;
  }

  auto *newNode = new TreeNode(val);
  newNode->left = buildTree();
  newNode->right = buildTree();
  return newNode;
}

void findParentNode(TreeNode *node) {
  queue<TreeNode *> leaf;
  queue<TreeNode *> parent;
  preOrder(node, leaf, parent);
  while (!leaf.empty()) {
    cout << leaf.front()->val << ' ';
    leaf.pop();
  }
  cout << '\n';

  while (!parent.empty()) {
    cout << parent.front()->val << ' ';
    parent.pop();
  }
  cout << '\n';
}

void freeTree(TreeNode *root) {
  if (root) {
    freeTree(root->left);
    freeTree(root->right);
    delete root;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    auto *root = buildTree();

    findParentNode(root);
    freeTree(root);
  }

  return 0;
}