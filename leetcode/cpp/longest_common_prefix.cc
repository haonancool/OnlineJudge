class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
      return string();
    int min_len = strs[0].length();
    for (size_t i = 1; i < strs.size(); i++) {
      int len = static_cast<int>(strs[i].length());
      min_len = len < min_len ? len : min_len;
    }
    int prefix_len = 0;
    for (int i = 0; i < min_len; i++) {
      bool flag = true;
      for (size_t j = 1; j < strs.size(); j++) {
        if (strs[j][i] != strs[0][i]) {
          flag = false;
          break;
        }
      }
      if (flag)
        prefix_len++;
      else
        break;
    }
    return strs[0].substr(0, prefix_len);
  }
};
