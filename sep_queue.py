class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSymmetric(self, root):
        def recur(left, right):
            if left==None and right==None:
                return True
            if left==None or right==None:
                return False
            if left.val != right.val:
                return False
            return (recur(left.left, right.right) and recur(left.right, right.left))
        return recur(root, root)

class Solution1:
    def isSymmetric(self, root):
        if root == None:
            return True
        if root.left == None and root.right == None:
            return True
        if root.left == None or root.right == None:
            return False

        queue = []
        queue.append(root)
        queue.append(root)

        left, right = TreeNode(), TreeNode()

        while len(queue):
            left = queue[0]
            queue.pop(0)
            right = queue[0]
            queue.pop(0)

            if left.val != right.val:
                return False
            if left.left and right.right:
                queue.append(left.left)
                queue.append(right.right)
            elif left.left or right.right:
                return False
            if left.right and right.left:
                queue.append(left.right)
                queue.append(right.left)
            elif left.right or right.left:
                return False
        return True

if __name__ == '__main__':
    pval3 = TreeNode(2)
    pval2 = TreeNode(2)
    pval1 = TreeNode(1, pval2, pval3)

    s = Solution()
    s1 = Solution1()

    res = s.isSymmetric(pval1)
    res1 = s1.isSymmetric(pval1)
    print(res)
    print(res1)











# end
