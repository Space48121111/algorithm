#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
  bool recur(TreeNode* left, TreeNode* right) {
    if (left == NULL && right == NULL)
      return true;
    if (left == NULL || right == NULL || left->val != right->val)
      return false;
    return (recur(left->left, right->right) && recur(left->right, right->left));
  }
  bool isSymmetric(TreeNode* root) {
    return recur(root, root);
  }
};

class Solution1 {
public:
  bool isSymmetric(TreeNode* root) {
    if (root == NULL)
      return true;
    if (!root->left && !root->right)
      return true;
    if (!root-> left || !root->right)
      return false;

    queue<TreeNode*> queue;
    queue.push(root);
    queue.push(root);

    TreeNode* left, * right;

    while (!queue.empty())
    {
      left = queue.front();
      queue.pop();

      right = queue.front();
      queue.pop();

      if (left->val != right->val)
        return false;
      if (left->left && right->right)
      {
        queue.push(left->left);
        queue.push(right->right);
      }

      else if (left->left || right->right)
        return false;
      if (left->right && right->left)
      {
        queue.push(left->right);
        queue.push(right->left);
      }
      else if (left->right || right->left)
        return false;
    }
    return true;
  }
};

int main(int argc, char* argv[]) {
  TreeNode* pval3 = new TreeNode(3);
  TreeNode* pval2 = new TreeNode(3);
  TreeNode* pval1 = new TreeNode(1, pval2, pval3);

  Solution sol;
  Solution1 sol1;
  bool res = sol.isSymmetric(pval1);
  bool res1 = sol1.isSymmetric(pval1);

    cout << res << endl;
    cout << res1 << endl;

  delete pval3;
  delete pval2;
  delete pval1;
}












// end
