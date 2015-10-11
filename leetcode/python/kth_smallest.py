# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.count = 0
        self.ret = 0

    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.in_order(root, k)
        return self.ret

    def in_order(self, root, k):
        if root.left:
            self.in_order(root.left, k)
        self.count += 1
        if self.count == k:
            self.ret = root.val
            return
        elif self.count > k:
            return
        if root.right:
            self.in_order(root.right, k)
