class Solution {
public:
  string convert(string s, int nRows) {
    if (1 == nRows)
      return s;
    string ret;
    int len = static_cast<int>(s.length());
    for (int i = 0; i < nRows; i++) {
      int index = i;
      while (index < len) {
        ret += s[index];
        if (0 == i || nRows - 1 == i) {
          index += 2 * (nRows - 1);
        } else if (index % (2 * nRows - 2) < nRows) {
          index += 2 * (nRows - 1 - i);
        } else {
          index += 2 * i;
        }
      }
    }
    return ret;
  }
};
