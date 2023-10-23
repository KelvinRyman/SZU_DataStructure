// DS森林叶子编码
#include <iostream>
#include <vector>

using namespace std;

// 定义树的结点结构
struct TreeNode {
  char data;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(char d) : data(d), left(nullptr), right(nullptr) {}
};

// 递归建立二叉树
TreeNode *buildBinaryTree(const string &preorder, int &index, int b) {
  if (index >= preorder.length() || preorder[index] == '0') {
    index += 2; // 跳过空格
    return nullptr;
  }

  auto root = new TreeNode(preorder[index]);
  index += 2;

  int i = 0;
  // 当左子树为空，递归建立左子树
  while (!root->left && i < b) {
    root->left = buildBinaryTree(preorder, index, b);
    i++;
  }

  TreeNode *temp = root->left;
  // 递归建立右子树
  while (i < b) {
    if (preorder[index] != '0') {
      temp->right = buildBinaryTree(preorder, index, b);
      temp = temp->right;
    } else {
      index += 2;
    }
    i += 1;
  }
  return root;
}

void toBinaryCode(TreeNode *root, string code) {
  if (root->left) {
    toBinaryCode(root->left, code + '0');
  }
  if (root->right) {
    toBinaryCode(root->right, code + '1');
  }
  if (!root->left && !root->right) {
    for (int i = 0; i < code.length(); i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << code[i];
    }
    cout << '\n';
  }
}

// 构建森林二叉树
TreeNode *buildForestTree(const vector<TreeNode *> &forest) {
  if (forest.empty()) {
    return nullptr;
  }

  for (int i = 0; i < forest.size() - 1; i++) {
    forest[i]->right = forest[i + 1];
  }
  return forest[0];
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, B;
  cin >> N >> B;
  cin.ignore();

  vector<string> str(N);
  vector<TreeNode *> root(N);
  for (int i = 0; i < N; i++) {
    getline(cin, str[i]);

    // 建立二叉树
    int index = 0;
    root[i] = buildBinaryTree(str[i], index, B);
  }

  toBinaryCode(buildForestTree(root), "");
  return 0;
}