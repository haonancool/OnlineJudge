class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	    int n = gas.size();
		int total = 0;
		int i = 0, j = 0;
		while (j < n) {
			int k = (i + j) % n;
			total += gas[k] - cost[k];
			j++;
			if (total < 0) {
			    if (i + j > n - 1)
			        return -1;
			    i += j;
			    j = 0;
			    total = 0;
			}
		}
		return i;
	}
};
