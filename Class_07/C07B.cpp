// DS树-二叉树高度
#include <iostream>
using namespace std;

class BinaryTree {
 public:
  struct TreeNode {
    char data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char d) : data(d), left(nullptr), right(nullptr) {}
  };

  int getHeight(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
  }

  TreeNode *buildTree(const string &preorder, int &index) {
    if (index >= preorder.length() || preorder[index] == '0') {
      index++;
      return nullptr;
    }

    char data = preorder[index++];

    auto *node = new TreeNode(data);
    node->left = buildTree(preorder, index);
    node->right = buildTree(preorder, index);

    return node;
  }

  void deleteTree(TreeNode *root) {
    if (!root) {
      return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string preorder;
    cin >> preorder;
    int index = 0;
    BinaryTree bt;
    auto *root = bt.buildTree(preorder, index);
    cout << bt.getHeight(root) << '\n';
    bt.deleteTree(root);
  }
  return 0;
}
