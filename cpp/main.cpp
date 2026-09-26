#include <iostream>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(): val { 0 }, left{ nullptr }, right { nullptr } {}
  TreeNode(int x): val { x }, left{ nullptr }, right { nullptr } {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val { x }, left{ left }, right { right } {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
  if (p == nullptr && q == nullptr) return true;
  if ((p == nullptr) ^ (q == nullptr)) return false;
  if (p->val != q->val) return false;
  bool leftEqual = isSameTree(p->left, q->left);
  bool rightEqual = isSameTree(p->right, q->right);
  return leftEqual && rightEqual;
}


int main() {
  TreeNode p { 1, new TreeNode(2), new TreeNode(3) };
  TreeNode q { 1, new TreeNode(2), new TreeNode(3) };
  std::cout << isSameTree(&p, &q) << std::endl;
  return 0;
}