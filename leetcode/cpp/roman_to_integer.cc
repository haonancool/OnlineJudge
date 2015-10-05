class Solution {
public:
  int rToA(char c) {
    int ret = 0;
    switch (c) {
    case 'I':
      ret = 1;
      break;
    case 'V':
      ret = 5;
      break;
    case 'X':
      ret = 10;
      break;
    case 'L':
      ret = 50;
      break;;
    case 'C':
      ret = 100;
      break;
    case 'D':
      ret = 500;
      break;
    case 'M':
      ret = 1000;
      break;
    default:
      break;
    }
    return ret;
  }
  int romanToInt(string s) {
    int len = static_cast<int>(s.length());
    int last = rToA(s[0]), 
        num = last;
    for (int i = 1; i < len; i++) {
      int cur = rToA(s[i]);
      num += cur;
      if (cur > last) {
        num -= 2 * last;
      }
      last = cur;
    }
    return num;
  }
};
