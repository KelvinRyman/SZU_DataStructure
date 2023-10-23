// DS树–二叉树之最大路径
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
  char val;
  int weight;
  TreeNode *left;
  TreeNode *right;

  TreeNode(char v, int w) : val(v), weight(w), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(const string &input, unordered_map<char, int> &weights, int &index) {
  if (index >= input.length()) {
    return nullptr;
  }

  char val = input[index];
  if (val == '0') {
    index++;
    return nullptr;
  }

  auto *newNode = new TreeNode(val, weights[val]);
  index++;

  newNode->left = buildTree(input, weights, index);
  newNode->right = buildTree(input, weights, index);

  return newNode;
}

int maxPathSum(TreeNode *root, int &maxSum) {
  if (root == nullptr) {
    return 0;
  }

  int leftSum = max(0, maxPathSum(root->left, maxSum));
  int rightSum = max(0, maxPathSum(root->right, maxSum));

  int currentPathSum = leftSum + rightSum + root->weight;
  maxSum = max(maxSum, currentPathSum);

  return max(leftSum, rightSum) + root->weight;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string preorder;
    cin >> preorder;
    int n;
    cin >> n;
    unordered_map<char, int> weights(n);
    for (auto ch : preorder) {
      if (ch != '0') {
        cin >> weights[ch];
      }
    }

    int index = 0;
    TreeNode *root = buildTree(preorder, weights, index);

    int maxSum = 0;
    int maxPathWeight = maxPathSum(root, maxSum);
    cout << maxPathWeight << "\n";
  }

  return 0;
}
