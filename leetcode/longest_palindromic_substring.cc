class Solution {
public:
  string longestPalindrome(string s) {
    string test_str = "^#";
    for (auto &c : s) {
      test_str += c;
      test_str += '#';
    }
    test_str += '$';
    int len = static_cast<int>(test_str.length());
    vector<int> p(len - 2, 0);
    int center = 0, right = 0;
    for (int i = 1; i < len - 1; i++) {
      int i_mirror = 2 * center - i;
      p[i] = (right > i) ? min(right - i, p[i_mirror]) : 0;
      while (test_str[i - p[i] - 1] == test_str[i + p[i] + 1])
        p[i]++;
      if (i + p[i] > right) {
        center = i;
        right = i + p[i];
      }
    }

    int max_len = 0, head = 0;
    for (int i = 1; i < len - 1; i++) {
      if (p[i] > max_len) {
        max_len = p[i];
        head = (i - max_len - 1) / 2;
      }
    }
    return s.substr(head, max_len);
  }
};
