class Solution {
public:
  int reverse(int x) {
    if (x > -10 && x < 10)
      return x;
    bool negtive = false;
    if (x < 0) {
      x = -x;
      negtive = true;
    }
    int max_val = (2 << 30) - 1;
    int ret = 0;
    while (x > 0) {
      if (max_val / 10 < ret) {
        ret = 0;
        break;
      }
      ret *= 10;
      int digit = x % 10;
      if (max_val - digit < ret) {
        ret = 0;
        break;
      }
      ret += digit;
      x /= 10;
    }
    ret = negtive ? -ret : ret;
    return ret;
  }
};
