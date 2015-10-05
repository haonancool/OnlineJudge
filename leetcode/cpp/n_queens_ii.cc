#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int count;
    int totalNQueens(int n) {
    	count = 0;
        if (n == 0)
            return 0;
        vector<string> cur;
        helper(cur, n);
        return count;
    }
    void helper(vector<string> &cur, int n) {
        if (cur.size() == n) {
            count++;
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
            helper(cur, n);
            cur.pop_back();
        }
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    int count = sol.totalNQueens(n);
    cout << count << endl;
    return 0;
}
