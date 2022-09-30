
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
      self.val = val
      self.left = left
      self.right = right


class Solution:
     def isSymmetric(self, root):
         print('hi')
         def recur(left, right):
             # base cases
             if (left == None and right == None):
                 return True
             if (left == None or right == None):
                 return False
             if (left.val != right.val):
                 return False
             return (recur(left.left, right.right) and recur(left.right, right.left))
         print('root', root)
         return recur(root, root)

s = Solution()
pval3 = TreeNode(2)
pval2 = TreeNode(2)
pval1 = TreeNode(1, pval2, pval3)
print('pval1', pval1)
res = s.isSymmetric(pval1)
print(res)













# end
