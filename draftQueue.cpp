#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(): val(0), left(NULL), right(NULL) {}
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    queue<TreeNode*> queue;
    TreeNode  *left, *right;

    if (root == NULL)
      return true;
    if (!root->left && !root->right)
      return true;
    if (!root->left || !root->right)
      return false;

    queue.push(root);
    queue.push(root);

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
      // 'or' includes 'and', ret false all the time
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

int main(int argc, char const *argv[]) {
  TreeNode *pval3 = new TreeNode(3);
  TreeNode *pval2 = new TreeNode(2);
  TreeNode *pval1 = new TreeNode(1, pval2, pval3);

  Solution sol;
  bool res = sol.isSymmetric(pval1);
  cout << res << endl;

  delete pval3;
  delete pval2;
  delete pval1;

  return 0;
}













// end
