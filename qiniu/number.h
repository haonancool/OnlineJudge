#ifndef NUMBER_H
#define NUMBER_H

#include <vector>
#include <string>

class Number {
public:
	Number(const std::string &str, int base);
	void toBase(int base);
	Number& operator+=(const Number &rhs);
	int getBase() const { return base_; }
	std::string toString() const;

private:

	std::vector<int> integral_;
	std::vector<int> fraction_;
	int base_;
};

#endif // NUMBER_H
