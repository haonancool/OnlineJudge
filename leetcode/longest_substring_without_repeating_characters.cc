class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int max = 0, len = 0, head = 0;
    int size = static_cast<int>(s.length());
    unordered_map<char, int> hash;
    for (int i = 0; i < size; i++) {
      char c = s[i];
      if (hash.find(c) != hash.end()) {
        max = len > max ? len : max;
        int index = hash[c];
        for (int j = head; j < index; j++) {
          hash.erase(s[j]);
          len--;
        }
        head = index + 1;
        hash[c] = i;
      } else {
        hash[c] = i;
        len++;
      }
    }
    max = len > max ? len : max;
    return max;
  }
};
