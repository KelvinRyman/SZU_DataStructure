// DS二叉树——二叉树之数组存储
#include <iostream>
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
    auto *node = new TreeNode(tree[index]);
    node->left = buildTree_fromArray(tree, 2 * index, n);
    node->right = buildTree_fromArray(tree, 2 * index + 1, n);
    return node;
  }
}

void preorderTraversal(TreeNode *root) {
  if (root) {
    cout << root->val << ' ';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
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
    int n;
    cin >> n;
    int tree[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> tree[i];
    }
    auto *root = buildTree_fromArray(tree, 1, n);
    preorderTraversal(root);
    cout << '\n';
  }

  return 0;
}