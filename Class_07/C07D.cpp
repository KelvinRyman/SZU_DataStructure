// DS树-带权路径和
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
  char data;
  int weight;
  TreeNode* left;
  TreeNode* right;

  TreeNode(char d, int w) : data(d), weight(w), left(nullptr), right(nullptr) {}
};

long long weightedPathSum(TreeNode* root, int depth) {
  if (root == nullptr) {
    return 0;
  }

  if (root->left == nullptr && root->right == nullptr) {
    return root->weight * depth;
  }

  long long leftSum = weightedPathSum(root->left, depth + 1);
  long long rightSum = weightedPathSum(root->right, depth + 1);

  return leftSum + rightSum;
}

TreeNode* buildTree(const string& preorder, const vector<int>& weights, int& index) {
  if (index >= preorder.length() || preorder[index] == '0') {
    index++;
    return nullptr;
  }

  char data = preorder[index];
  index++;

  auto* node = new TreeNode(data, 0);
  if (data != '0') {
    node->weight = weights[data - 'A'];
    node->left = buildTree(preorder, weights, index);
    node->right = buildTree(preorder, weights, index);
  }

  return node;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    string preorder;
    cin >> preorder;
    int n;
    cin >> n;
    vector<int> weights(26, 0);

    for (const auto& ch : preorder) {
      if (isupper(ch)) {
        cin >> weights[ch - 'A'];
      }
    }

    int index = 0;
    TreeNode* root = buildTree(preorder, weights, index);
    long long pathSum = weightedPathSum(root, 0);
    cout << pathSum << endl;
  }

  return 0;
}
