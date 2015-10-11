# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        if not root.left and not root.right:
            return 1
        elif not root.left and root.right:
            return 2
        elif root.left and not root.right:
            return 2
        left, right = self.get_height(root)
        if left == right:
            return 2**(left+1)-1
        else:
            return 1 + self.countNodes(root.left) + self.countNodes(root.right)

    def get_height(self, root):
        left = 0
        cur = root
        while cur.left:
            left += 1
            cur = cur.left
        right = 0
        cur = root
        while cur.right:
            right += 1
            cur = cur.right
        return left, right
