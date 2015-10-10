class TrieNode(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.flag = False
        self.children = {}


class Trie(object):

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.flag = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        cur = self.root
        for c in word:
            if c not in cur.children:
                return False
            cur = cur.children[c]
        return cur.flag

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie
        that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        cur = self.root
        for c in prefix:
            if c not in cur.children:
                return False
            cur = cur.children[c]
        return True


class Solution(object):
    def __init__(self):
        self.trie = Trie()
        self.visited = None
        self.res = set()

    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        m = len(board)
        if m == 0:
            return []
        n = len(board[0])
        if n == 0:
            return[]
        self.visited = [[False] * n for i in xrange(m)]
        for w in words:
            self.trie.insert(w)
        for x in xrange(m):
            for y in xrange(n):
                self.dfs(self.trie.root, x, y, '', board)
        return list(self.res)

    def dfs(self, node, x, y, s, board):
        if self.visited[x][y]:
            return
        c = board[x][y]
        s = s + c
        if c not in node.children:
            return
        else:
            node = node.children[c]
        if node.flag:
            self.res.add(s)
        m, n = len(board), len(board[0])
        self.visited[x][y] = True
        if x > 0:
            self.dfs(node, x-1, y, s, board)
        if x < m-1:
            self.dfs(node, x+1, y, s, board)
        if y > 0:
            self.dfs(node, x, y-1, s, board)
        if y < n-1:
            self.dfs(node, x, y+1, s, board)
        self.visited[x][y] = False
