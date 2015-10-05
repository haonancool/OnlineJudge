class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    int div = 1, len = 1;
    int tmp = x;
    while (tmp >= 10) {
      tmp /= 10;
      div *= 10;
      len++;
    }
    bool ret = true;
    for (int i = 0; i < len / 2; i++) {
      int head = x / div, tail = x % 10;
      if (head != tail) {
        ret = false;
        break;
      }
      x -= head * div;
      x /= 10;
      div /= 100;
    }
    return ret;
  }
};
