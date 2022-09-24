from __future__ import annotations;

'''
inp = [1,None,2,3] (root, left, right)
res = [1,3,2] Inorder(left, root, right)
# 1 is the root, no left node, the right node of 1 is 2,
3 is the left node of 2, goes first.

algorithms:
recursive
iterative
time complexity : O(n)
space complexity: O(n)
worst case scenario: stack only having left side child linear, pop all at once
'''

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    def __repr__(self):
        return 'obj val=' + str(self.val) + ' left=' + str(self.left) + \
        ' right=' + str(self.right)

# recursive
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        def recur(root):
            if not root:
                return
            if not None:
                recur(root.left)
                res.append(root.val)
                recur(root.right)
        recur(root)
        return res



# iteratively builds up the stack and pops once the left reaches none
class Solution1:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        stack = []
        curr = root

        while curr or stack:
            while curr:
                stack.append(curr)
                curr = curr.left
            # LIFO pop
            curr = stack.pop()
            res.append(curr.val)
            curr = curr.right
        return res


inp = [1,None,2,3]

obj3 = TreeNode(3, None, None)
obj2 = TreeNode(2, obj3, None)
obj1 = TreeNode(1, None, obj2)

s = Solution()
print('Solution ', s.inorderTraversal(obj1))
s1 = Solution1()
print('Solution1 ', s1.inorderTraversal(obj1))



# convert list into object
def ls_to_obj(arr):
    res = []
    for i in range(len(arr) - 1):
        if i == len(arr) - 2:
            res.append(arr[i])
            t = TreeNode(val = res, left = arr[i+1], right = None)
            res.append(arr[len(arr) - 1])
            t = TreeNode(val = res, left = None, right = None)
            return res
        elif arr[i] != None:
            res.append(arr[i])
            t = TreeNode(val = res, left = arr[i+1], right = arr[i+2])

    return res


# def ls_to_ln(arr):
#     if len(arr) < 1:
#         return None
#     elif len(arr) == 1:
#         return ListNode(arr[0])
#     return ListNode(arr[0], next = ls_to_ln(arr[1:]))
#
# res = []
# for l in lists:
#     ls = ls_to_ln(l)
#     res.append(ls)
# print(res)






# end
