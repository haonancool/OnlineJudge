class Solution {
public:
    bool isPalindrome(string s) {
    	bool ret = true;
        int i = 0, j = s.length() - 1;
        do {
        	while (!isalnum(s[i]) && i < j)
        		i++;
        	while (!isalnum(s[j]) && i < j)
        		j--;
        	if (i < j) {
        		if (tolower(s[i]) != tolower(s[j])) {
        			ret = false;
        			break;
        		}
        		i++;
        		j--;
        	} else {
        		break;
        	}
        } while (1);
        return ret;
    }
};