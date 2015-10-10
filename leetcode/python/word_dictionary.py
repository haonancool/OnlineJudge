class TrieNode(object):
    def __init__(self):
        self.state = False
        self.children = {}

    def add(self, word, i):
        if word[i] not in self.children:
            self.children[word[i]] = TrieNode()
        if i == len(word) - 1:
            self.children[word[i]].state = True
        else:
            self.children[word[i]].add(word, i+1)

    def search(self, word, i):
        if word[i] == '.':
            for k, v in self.children.iteritems():
                if i == len(word) - 1:
                    return v.state
                elif v.search(word, i+1):
                    return True
            return False
        elif word[i] in self.children:
            if i == len(word) - 1:
                return self.children[word[i]].state
            else:
                return self.children[word[i]].search(word, i+1)
        else:
            return False


class WordDictionary(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        self.root.add(word, 0)

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could
        contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        return self.root.search(word, 0)

# Your WordDictionary object will be instantiated and called as such:
# wordDictionary = WordDictionary()
# wordDictionary.addWord("word")
# wordDictionary.search("pattern")

if __name__ == '__main__':
    word_dict = WordDictionary()
    word_dict.addWord('a')
    print word_dict.search('.')
