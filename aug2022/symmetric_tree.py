class TreeNode:
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSymmetric(self, root):
        def recur(left, right):
            if not left and not right:
                return True
            if not left or not right or left.val != right.val:
                return False
            return recur(left.left, right.right) and recur(left.right, right.left)
        return recur(root, root)

t2 = TreeNode(2)
t3 = TreeNode(2)
t1 = TreeNode(1, t2, t3)

s = Solution()
print(s.isSymmetric(t1))
