# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if p.val > q.val:
            p, q = q, p
        cur = root
        while cur:
            if p.val <= cur.val <= q.val:
                return cur.val
            elif q.val < cur.val:
                cur = cur.left
            else:
                cur = cur.right
