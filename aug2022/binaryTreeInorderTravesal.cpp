#include <iostream>
#include <vector>

using namespace std;
/*

  inp = [1,null,2,3] (root, left, right)
  res = [1,3,2] Inorder (Left, Root, Right)

*/

// model pre-defined structure to know how much memory it needs
// constructor objects Treenode() with diff vars
//  val is the val itself, left, right nullptr/NULL are the pointers
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  //without args, take 0 as default
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  // one arg
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  // 3 args
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    // & reference return multi vals
    // multi vals of whatyes
    void recur(TreeNode *root, vector<int> &res)
    {
      if (root == NULL)
      {
        return;
      }
      else
      {
        recur(root->left, res);
        res.push_back(root->val);
        recur(root->right, res);
      }

    }

    vector<int> inorderTraversal(TreeNode *root) {
      vector<int> res;
      recur(root, res);
      return res;
    }

};


class Solution1 {
public:
  // *root a big-size object use asterisk pointer/ref
  // not root to make a copy of itself, takes more memory
  // refer to obj from another function too
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    vector<TreeNode*> stack;
    // when assign vals, *curr is the pointer type to the val
    TreeNode *curr = root;

    // *curr returns the org obj val instead of the pointer
    // curr returns the pointer *ValuePtr
    while (curr != NULL || stack.size() != 0)
    {
      while (curr != NULL)
      {
        stack.push_back(curr);
        curr = curr->left;
      }
      // pop_back remove and destroy the last
      curr = stack[stack.size()-1];
      stack.pop_back();
      // curr: a pointer curr points to val of itself
      res.push_back(curr->val);
      // curr points to right
      curr = curr->right;
    }
    return res;
  }
};


// inp = [1,null,2,3]
int main(int argc, char* argv[]) {
  //new: create to assign to a pointer, need to delete manually
  // TreeNode*pval3 = new TreeNode(3, nullptr, nullptr);
  TreeNode*pval3 = new TreeNode(3);
  TreeNode*pval2 = new TreeNode(2, pval3, nullptr);
  TreeNode*pval1 = new TreeNode(1, nullptr, pval2);
  // create obj, and delete automatically
  // static func Soluction::inorderTraversal()
  Solution sol;
  vector<int> res = sol.inorderTraversal(pval1);
  for (int i=0; i<res.size(); i++)
  {
    std::cout << "Res "<< res[i] << std::endl;
  }

  Solution1 sol1;
  vector<int> res1 = sol1.inorderTraversal(pval1);
  for (int i=0; i<res1.size(); i++)
  {
    std::cout << "Res1 "<< res1[i] << std::endl;
  }

  // clear the memory
  delete pval1;
  delete pval2;
  delete pval3;

}





// end
