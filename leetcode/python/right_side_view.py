# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ret = []
        if not root:
            return ret
        global_n = 0
        q = deque()
        q.append((root, 1))
        while len(q) > 0:
            cur, local_n = q.popleft()
            if local_n > global_n:
                ret.append(cur.val)
                global_n = local_n
            if cur.right:
                q.append((cur.right, local_n+1))
            if cur.left:
                q.append((cur.left, local_n+1))
        return ret