// DS二叉树——Huffman编码与解码（不含代码框架）
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

// 定义Huffman树的结点结构
struct TreeNode {
  char data;
  int weight;
  TreeNode* left;
  TreeNode* right;

  TreeNode(char c, int w) : data(c), weight(w), left(nullptr), right(nullptr) {}
};

// 定义比较函数，用于优先队列中结点的排序
struct CompareNodes {
  bool operator()(const TreeNode* left, const TreeNode* right) {
    return left->weight > right->weight;
  }
};

// 创建Huffman树
TreeNode* buildHuffmanTree(vector<char> characters, vector<int> weights) {
  priority_queue<TreeNode*, vector<TreeNode*>, CompareNodes> pq;

  for (int i = 0; i < characters.size(); i++) {
    pq.push(new TreeNode(characters[i], weights[i]));
  }

  while (pq.size() > 1) {
    TreeNode* left = pq.top();
    pq.pop();
    TreeNode* right = pq.top();
    pq.pop();

    TreeNode* parent = new TreeNode('\0', left->weight + right->weight);
    parent->left = left;
    parent->right = right;

    pq.push(parent);
  }

  return pq.top();
}

// 生成Huffman编码
void generateHuffmanCodes(TreeNode* root, string code, map<char, string>& codes) {
  if (root == nullptr) {
    return;
  }

  if (root->data != '\0') {
    codes[root->data] = code;
  }

  generateHuffmanCodes(root->left, code + "0", codes);
  generateHuffmanCodes(root->right, code + "1", codes);
}

// Huffman编码
string huffmanEncode(map<char, string> codes, string input) {
  string encodedString = "";
  for (char c : input) {
    if (codes.find(c) != codes.end()) {
      encodedString += codes[c];
    } else {
      return "error!";
    }
  }
  return encodedString;
}

// Huffman解码
string huffmanDecode(TreeNode* root, string encodedString) {
  TreeNode* current = root;
  string decodedString = "";
  for (char c : encodedString) {
    if (c == '0') {
      current = current->left;
    } else if (c == '1') {
      current = current->right;
    }

    if (current->left == nullptr && current->right == nullptr) {
      decodedString += current->data;
      current = root;
    }
  }
  return decodedString;
}

int main() {
  int testCases;
  cin >> testCases;

  while (testCases--) {
    int n;
    cin >> n;

    vector<char> characters(n);
    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
      cin >> characters[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> weights[i];
    }

    string input;
    cin >> input;

    TreeNode* huffmanTree = buildHuffmanTree(characters, weights);

    map<char, string> codes;
    generateHuffmanCodes(huffmanTree, "", codes);

    for (int i = 0; i < n; i++) {
      char c = characters[i];
      string code = codes[c];
      cout << c << " :" << code << endl;
    }

    string encodedString = huffmanEncode(codes, input);
    cout << encodedString << endl;

    string decodedString = huffmanDecode(huffmanTree, encodedString);
    if (decodedString == "error!") {
      cout << "error!" << endl;
    } else {
      cout << decodedString << endl;
    }
  }

  return 0;
}
