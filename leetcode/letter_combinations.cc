#include <iostream>
#include <vector>
#include <stack>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::vector;
using std::stack;
using std::string;

const char *number_letter[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int number_size[] = {3, 3, 3, 3, 3, 4, 3, 4};
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		int size = static_cast<int>(digits.size());
		if (0 == size)
			return ret;
		char *temp = new char[size + 1];
		temp[size] = '\0';
		vector<int> nums; 
		int i = 0;
		while (i != -1) {
			int index = digits[i] - '2';
			if (nums.size() <= i) {
				nums.push_back(0);
				temp[i] = number_letter[index][nums[i]];
				if (size - 1 == i)
					ret.push_back(temp);
				if (i < size - 1)
					i++;
			} else {
				if (number_size[index] - 1 > nums[i]) {
					nums[i]++;
					temp[i] = number_letter[index][nums[i]];
					if (size - 1 == i)
						ret.push_back(temp);
					if (i < size - 1)
						i++;
				} else {
					nums.pop_back();
					i--;
				}
			}
		}
		delete temp;
		return ret;
	}
};

int main() {
	Solution sol;
	string digits;
	cin >> digits;
	vector<string> result = sol.letterCombinations(digits);
	cout << '{';
	for (size_t i = 0; i < result.size(); i++) {
		if (i > 0)
			cout << ", ";
		cout << "\"";
		cout << result[i];
		cout << "\"";
	}
	cout << '}';
	return 0;
}
