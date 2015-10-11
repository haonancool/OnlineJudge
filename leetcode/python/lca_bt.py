# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.ret = None

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        self.pre_order(root, p, q)
        return self.ret

    def pre_order(self, root, p, q):
        if root is None or self.ret is not None:
            return
        if root is p:
            if self.pre_order(root.left, p, q) is q or self.pre_order(root.right, p, q) is q:
                self.ret = root
                return
            else:
                return p
        elif root is q:
            if self.pre_order(root.left, p, q) is p or self.pre_order(root.right, p, q) is p:
                self.ret = root
                return
            else:
                return q
        else:
            a = self.pre_order(root.left, p, q)
            b = self.pre_order(root.right, p, q)
            if (a is p and b is q) or (a is q and b is p):
                self.ret = root
            elif a is p or b is p:
                return p
            elif a is q or b is q:
                return q
