class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty())
        	return 0;
        vector<int> table;
        for (int i = 0; i < triangle.size(); i++) {
        	vector<int> temp;
        	for (int j = 0; j < i + 1; j++) {
        		if (0 == i) {
        			temp.push_back(triangle[i][0]);
        		} else {
        			if (j == 0) {
        				temp.push_back(table.front() + triangle[i][j]);
        			} else if (j == i) {
        				temp.push_back(table.back() + triangle[i][j]);
        			} else {
        				int left = table[j - 1] + triangle[i][j],
        					right = table[j] + triangle[i][j];
        				int n = (left < right) ? left : right;
        				temp.push_back(n);
        			}
        		}
        	}
        	table = temp;
        }
        int ret = table[0];
        for (int i = 1; i < table.size(); i++) {
        	if (ret > table[i])
        		ret = table[i];
        }
        return ret;
    }
};