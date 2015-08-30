struct WordNode {
	string word;
	int dist;
	WordNode(const string &w, int d) : word(w), dist(d) {}
};

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		queue<WordNode> q;
		q.push(WordNode(beginWord, 1));
		while (!q.empty()) {
			WordNode word_node = q.front();
			q.pop();
			if (word_node.word == endWord)
				return word_node.dist;
			for (int i = 0; i < endWord.length(); i++) {
				char origin = word_node.word[i];
				for (char c = 'a'; c <= 'z'; c++) {
					if (origin == c)
						continue;
					word_node.word[i] = c;
					if (wordDict.find(word_node.word) != wordDict.end()) {
						q.push(WordNode(word_node.word, word_node.dist + 1));
						wordDict.erase(word_node.word);
					}
				}
				word_node.word[i] = origin;
			}
		}
		return 0;
	}
};