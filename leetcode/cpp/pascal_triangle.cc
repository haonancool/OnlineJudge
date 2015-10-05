class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 1; i <= numRows; i++) {
        	vector<int> temp;
        	for (int j = 0; j < i; j++) {
        		if (0 == j || i - 1 == j)
        			temp.push_back(1);
        		else
        			temp.push_back(ret.back()[j - 1] + ret.back()[j]);
        	}
        	ret.push_back(temp);
        }
        return ret;
    }
};