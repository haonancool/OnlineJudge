from collections import deque

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        ret = []
        q = deque()
        q.append(root)
        while q:
            cur = q.popleft()
            if cur is None:
                ret.append('null')
            else:
                ret.append(str(cur.val))
                q.append(cur.left)
                q.append(cur.right)
        return ','.join(ret)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        nodes = data.split(',')
        if nodes[0] == 'null':
            return None
        else:
            root = TreeNode(int(nodes[0]))
        q = deque()
        q.append(root)
        i = 1
        while q:
            cur = q.popleft()
            if nodes[i] == 'null':
                left = None
            else:
                left = TreeNode(int(nodes[i]))
                q.append(left)
            cur.left = left
            i += 1
            if nodes[i] == 'null':
                right = None
            else:
                right = TreeNode(int(nodes[i]))
                q.append(right)
            cur.right = right
            i += 1
        return root

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    codec = Codec()
    data = codec.serialize(root)
    ret = codec.deserialize(data)
