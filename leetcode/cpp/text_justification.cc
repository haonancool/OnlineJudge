class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int len = 0, i = 0;
        int j;
        for (j = 0; j < words.size(); j++) {
            int tmp = len + words[j].length();
            if (j > i)
                tmp += j - i;
            if (tmp > maxWidth) {
                string row;
        
                if (i + 1 == j) {
                    row += words[i];
                    for (int k = 0; k < maxWidth - len; k++)
                    row.push_back(' ');
                } else {
                    int interval = (maxWidth - len) / (j - i - 1);
                    for (int k = i; k < j; k++) {
                        row += words[k];
                        if (k < j - 1) {
                            for (int m = 0; m < interval; m++)
                                row.push_back(' ');
                            if (k - i < (maxWidth - len) % (j - i - 1))
                                row.push_back(' ');
                        }
                    }
                }
                ret.push_back(row);
                i = j;
                len = words[j].length();
            } else {
                len += words[j].length();
            }
        }
        string row;
        for (int k = i; k < j; k++) {
            row += words[k];
            if (k < j - 1)
                row.push_back(' ');
        }
        while (row.length() < maxWidth)
            row.push_back(' ');
        ret.push_back(row);
        return ret;
    }
};