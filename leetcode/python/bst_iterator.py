# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.parents = []
        self.cur = root
        while self.cur and self.cur.left:
            self.parents.append(self.cur)
            self.cur = self.cur.left

    def hasNext(self):
        """
        :rtype: bool
        """
        return bool(self.cur)

    def next(self):
        """
        :rtype: int
        """
        ret = self.cur
        if self.cur.right:
            self.cur = self.cur.right
            while self.cur.left:
                self.parents.append(self.cur)
                self.cur = self.cur.left
        elif len(self.parents) > 0:
            self.cur = self.parents.pop()
        else:
            self.cur = None
        return ret.val
            

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
