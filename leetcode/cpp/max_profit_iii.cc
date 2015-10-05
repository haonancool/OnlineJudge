class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.size() < 2)
    		return 0;
        vector<int> left(prices.size(), 0), right(prices.size(), 0);
        int minimum = prices.front(), maximum = prices.back();
        for (int i = 1; i < prices.size(); i++) {
        	int temp = prices[i] - minimum;
        	if (temp > left[i - 1])
        		left[i] = temp;
        	else
        		left[i] = left[i - 1];
        	if (minimum > prices[i])
        		minimum = prices[i];
        }
        for (int i = prices.size() - 2; i >= 0; i--) {
        	int temp = maximum - prices[i];
        	if (temp > right[i + 1])
        		right[i] = temp;
        	else
        		right[i] = right[i + 1];
        	if (maximum < prices[i])
        		maximum = prices[i];
        }
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
        	int temp = left[i] + right[i];
        	if (temp > profit)
        		profit = temp;
        }
        return profit;
    }
};