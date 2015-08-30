struct WordNode {
	string word;
	int dist;
	WordNode *pre;
	WordNode(const string &w, int d, WordNode *previous) : word(w), dist(d), pre(previous) {}
};

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> ret;
        dict.insert(end);
		queue<WordNode*> q;
		q.push(new WordNode(start, 1, 0));
		int dist = -1;
		unordered_map<string, int> table;
		table[start] = 1;
		while (!q.empty()) {
			WordNode *word_node = q.front();
			q.pop();
			if (word_node->word == end) {
				if (dist < 0 || dist == word_node->dist) {
					dist = word_node->dist;
					vector<string> temp(dist);
					WordNode *p = word_node;
					for (int i = temp.size() - 1; i >= 0; i--) {
						temp[i] = p->word;
						p = p->pre;
					}
					ret.push_back(temp);
				}
				continue;
			}
			for (int i = 0; i < end.length(); i++) {
				char origin = word_node->word[i];
				for (char c = 'a'; c <= 'z'; c++) {
					if (origin == c)
						continue;
					word_node->word[i] = c;
					if (dict.find(word_node->word) != dict.end()) {
						if (table.find(word_node->word) == table.end())
							table[word_node->word] = word_node->dist + 1;
						if (table[word_node->word] == word_node->dist + 1)
							q.push(new WordNode(word_node->word, word_node->dist + 1, word_node));
					}
				}
				word_node->word[i] = origin;
			}
		}
        return ret;
    }
};