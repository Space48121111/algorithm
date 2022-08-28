#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

// recursively compare left and right vals
class Solution {
public:
  bool recur(TreeNode *left, TreeNode *right)
  {
    if (left == NULL && right == NULL)
    {
      return true;
    }
    if (left == NULL || right == NULL || left->val != right->val)
    {
      return false;
    }
    return (recur(left->left, right->right) && recur(left->right, right->left));
  }

  bool isSymmetric(TreeNode *root)
  {
    return recur(root, root);
  }
};

// iteratively if left and right nodes are equal, pop off from the stack
class Solution1 {
public:
  bool isSymmetric(TreeNode* root, TreeNode* left, TreeNode* right)
  {
    vector<TreeNode*> stack;
    vector<int>* curr = root;
    while (curr != NULL || stack.size() != 0)
    {
      while (curr != NULL)
      {
        stack.push_back(curr);
        if (left == NULL || right == NULL || left != right)
        {
          return False;
        }
        curr = stack[stack.size()-1];
        stack.pop_back(curr);
        curr = left->left || right->right;
      }
    }
  }
}

int main(int argc, char*argv[])
{
  TreeNode *pval2 = new TreeNode(2);
  TreeNode *pval3 = new TreeNode(2);
  TreeNode *pval1 = new TreeNode(1, pval2, pval3);

  Solution sol;
  bool res = sol.isSymmetric(pval1);
  if (res == 1)
  {
    std::cout << "True" << std::endl;
  }
  else
  {
    std::cout << "False" << std::endl;

  }

  delete pval2;
  delete pval3;
  delete pval1;
}







// end
