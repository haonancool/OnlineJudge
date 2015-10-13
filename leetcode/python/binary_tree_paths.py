# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if root is None:
            return []
        ret = []
        self.help(root, [], ret)
        return ret

    def help(self, root, tmp, ret):
        tmp.append(str(root.val))
        if root.left:
            self.help(root.left, tmp, ret)
        if root.right:
            self.help(root.right, tmp, ret)
        if not root.left and not root.right:
            ret.append('->'.join(tmp))
        tmp.pop()
