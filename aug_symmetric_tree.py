class TreeNode:
    def __init__(self, val=0, left=None, right=None):
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

# base cases: no vals or vals don't equal, return false
class Solution1:
    def isSymmetric(self, root):
        if root == None:
            return True
        if (not root.left and not root.right):
            return True
        elif (not root.left or not root.right):
            return False

        queue = []
        queue.append(root)
        queue.append(root)

        left, right = 0, 0

        while len(queue):
            if left.val != right.val:
                return False

            left = queue[0]
            queue.pop(0)

            right = queue[0]
            queue.pop(0)

            if (left.left and right.right):
                queue.append(left.left)
                queue.append(right.right)
            elif (left.left or right.right):
                return False

            if (left.right and right.left):
                queue.append(left.right)
                queue.append(right.left)
            elif (left.right or right.left):
                return False
        return True

# 1, 2, 2, 3, 4, 4, 3
n4 = TreeNode(3)
n5 = TreeNode(4)
n6 = TreeNode(4)
n7 = TreeNode(3)
n2 = TreeNode(2, n4, n5)
n3 = TreeNode(2, n6, n7)
n1 = TreeNode(1, n2, n3)

s = Solution()
s1 = Solution()
print(s.isSymmetric(n1))
print(s1.isSymmetric(n1))
