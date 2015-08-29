class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3)
        	return false;
        if (len3 == 0)
        	return true;
        vector<int> table;

        for (int k = 1; k <= len3; k++) {
        	bool flag = false;
        	if (1 == k) {
        		if (len2 >= 1 && s2[0] == s3[0]) {
        			table.push_back(1);
        			flag = true;
        		} else {
        			table.push_back(0);
        		}
        		if (len1 >= 1 && s1[0] == s3[0]) {
        			table.push_back(1);
        			flag = true;
        		} else {
        			table.push_back(0);
        		}
        	} else {
        		vector<int> temp;
        		for (int j = 0; j <= k; j++) {
	        		if (j < k && k - j <= len2 && table[j] && s2[k - j - 1] == s3[k - 1]) {
	        			temp.push_back(1);
	        			flag = true;
	        		} else if (j > 0 && j <= len1 && table[j - 1] && s1[j - 1] == s3[k - 1]) {
	        			temp.push_back(1);
	        			flag = true;
	        		} else {
	        			temp.push_back(0);
	        		}
	        	}
        		table = temp;
        	}
        	if (!flag)
        		return false;
        }
        return true;
    }
};