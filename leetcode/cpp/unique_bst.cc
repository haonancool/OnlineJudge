class Solution {
public:
    int numTrees(int n) {
    	if (0 == n)
    		return 0;
        vector<int> table;
        table.push_back(1);
        for (int i = 1; i <= n; i++) {
        	int count = 0;
        	for (int j = 0; j <= i - 1; j++) {
        		count += table[j] * table[i - 1 - j];
        	}
        	table.push_back(count);
        }
        return table.back();
    }
};