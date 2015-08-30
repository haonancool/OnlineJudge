class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        for (int i = 1; i <= rowIndex + 1; i++) {
        	vector<int> temp;
        	for (int j = 0; j < i; j++) {
        		if (0 == j || i - 1 == j)
        			temp.push_back(1);
        		else
        			temp.push_back(ret[j - 1] + ret[j]);
        	}
        	ret = temp;
        }
        return ret;
    }
};