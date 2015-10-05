class Solution {
public:
    vector<int> ret;
    vector<int> grayCode(int n) {
        int num = 0;
        helper(num, n);
        return ret;
    }
    void helper(int &num, int n) {
        if (0 == n) {
            ret.push_back(0);
            return;
        }
        if (1 == n) {
            ret.push_back(num);
            num ^= 1;
            ret.push_back(num);
            return;
        }
        helper(num, n - 1);
        num ^= 1 << n - 1;
        helper(num, n - 1);
    }
};