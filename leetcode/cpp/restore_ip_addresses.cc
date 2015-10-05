class Solution {
public:
	unordered_set<unsigned int> table;
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        helper(0, s, 3);
        for (int ip : table) {
        	string temp;
        	temp += to_string((ip >> 24) & 0xff) + '.';
        	temp += to_string((ip >> 16) & 0xff) + '.';
        	temp += to_string((ip >> 8) & 0xff) + '.';
        	temp += to_string(ip & 0xff);
        	ret.push_back(temp);
        }
        return ret;
    }
    void helper(unsigned int temp, string s, int i) {
    	unsigned int n = 0;
    	for (int j = 0; j < 3 && j < s.length(); j++) {
    		n *= 10;
    		n += s[j] - '0';
    		if (n <= 255) {
    			if (i > 0) {
    				helper(temp | (n << (8 * i)), s.substr(j + 1), i - 1);
    			} else if (j == s.length() - 1) {
    				table.insert(temp | (n << (8 * i)));
    			}
    		} else {
    			break;
    		}
    		if (j == 0 && n == 0)
				break;
    	}
    }
};