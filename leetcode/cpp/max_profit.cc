class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.empty())
    		return 0;
        int profit = 0, minimum = prices[0];
        for (int i = 1; i < prices.size(); i++) {
        	int temp = prices[i] - minimum;
        	if (temp > profit)
        		profit = temp;
        	if (prices[i] < minimum)
        		minimum = prices[i];
        }
        return profit;
    }
};