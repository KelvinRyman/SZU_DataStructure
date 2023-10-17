// DS二叉树——后序遍历
#include <iostream>
#include <stack>
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

void postorderTraversal(TreeNode *root) {
  if (!root) {
    return;
  }

  stack<TreeNode *> nodeStack;
  nodeStack.push(root);
  TreeNode *prev = nullptr;
  while (!nodeStack.empty()) {
    TreeNode *curr = nodeStack.top();
    if (!prev || prev->left == curr || prev->right == curr) {   // 第一次迭代或者 prev 是 curr 的父节点
      if (curr->left) {
        nodeStack.push(curr->left);
      } else if (curr->right) {
        nodeStack.push(curr->right);
      } else {
        cout << curr->val;
        nodeStack.pop();
      }
    } else if (curr->left == prev) {
      if (curr->right) {
        nodeStack.push(curr->right);
      } else {
        cout << curr->val;
        nodeStack.pop();
      }
    } else if (curr->right == prev) {
      cout << curr->val;
      nodeStack.pop();
    }
    prev = curr;
  }
  cout << '\n';
}

void postorderTraversal1(TreeNode *root) {
  if (!root) return;

  stack<TreeNode *> s1, s2;
  s1.push(root);

  while (!s1.empty()) {
    TreeNode *current = s1.top();
    s1.pop();
    s2.push(current);

    if (current->left) {
      s1.push(current->left);
    }

    if (current->right) {
      s1.push(current->right);
    }
  }

  while (!s2.empty()) {
    TreeNode *current = s2.top();
    s2.pop();
    cout << current->val << " ";
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
    auto *root = buildTree(input);

    postorderTraversal(root);
  }

  return 0;
}
