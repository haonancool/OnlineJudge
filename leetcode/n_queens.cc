#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        if (n == 0)
            return ret;
        vector<string> cur;
        helper(ret, cur, n);
        return ret;
    }
    void helper(vector<vector<string>> &result, vector<string> &cur, int n) {
        if (cur.size() == n) {
            result.push_back(cur);
            return;
        }
        for (int i = 0; i < n; i++) {
            bool flag = true;
            int k = cur.size();
            for (int j = 0; j < k; j++) {
                if (cur[j][i] == 'Q') {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                continue;
            for (int j = 0; j < k; j++) {
                int x0 = i + (k - j), x1 = i - (k - j);
                if ((x0 >= 0 && x0 < n && cur[j][x0] == 'Q') ||
                    (x1 >= 0 && x1 < n && cur[j][x1] == 'Q')) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                continue;
            string tmp;
            for (int j = 0; j < n; j++) {
                if  (i == j)
                    tmp.push_back('Q');
                else
                    tmp.push_back('.');
            }
            cur.push_back(tmp);
            helper(result, cur, n);
            cur.pop_back();
        }
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<vector<string>> result = sol.solveNQueens(n);
    for (const auto &conf : result) {
        for (const auto &s : conf)
            cout << s << endl;
        cout << endl;
    }
    return 0;
}
