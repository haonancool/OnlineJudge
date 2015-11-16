class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if (words.empty())
            return ret;
        int len = words[0].length();
        if (0 == len)
            return ret;
        unordered_map<string, int> table;
        for (auto &word : words)
            table[word]++;
        int limit = s.length();
        limit -= words.size() * len;
        for (int i = 0; i < len && i <= limit; i++) {
            int cnt = words.size();
            unordered_map<string, int> tmp = table;
            int j = i, k = i;
            for(;;) {
                string word = s.substr(k, len);
                if (tmp.find(word) != tmp.end()) {
                    if (tmp[word] > 0) {
                        tmp[word]--;
                        cnt--;
                        if (0 == cnt) {
                            ret.push_back(j);
                            if (j + len <= limit) {
                                tmp[s.substr(j, len)]++;
                                cnt++;
                                j += len;
                            } else {
                                break;
                            }
                        }
                        k += len;
                    } else {
                        while (j <= limit && 0 == tmp[word]) {
                            tmp[s.substr(j, len)]++;
                            cnt++;
                            j += len;
                        }
                        if (j > limit)
                            break;
                        tmp[word]--;
                        cnt--;
                        k += len;
                    }
                } else {
                    k += len;
                    j = k;
                    if (j > limit)
                        break;
                    tmp = table;
                    cnt = words.size();
                }
            }
        }
        return ret;
    }
};