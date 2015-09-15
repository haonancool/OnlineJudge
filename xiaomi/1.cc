#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

template<typename T>
class MyQueue {
public:
	bool empty() const {
		return s0_.empty() && s1_.empty();
	}

	void push(const T &val) {
		s0_.push(val);	
	}

	T pop() {
		if (empty())
			throw underflow_error("Empty queue");
		if (s1_.empty()) {
			while (!s0_.empty()) {
				T val = s0_.top();
				s0_.pop();
				s1_.push(val);
			}
		}
		T ret = s1_.top();
		s1_.pop();
		return ret;
	}
private:
	stack<T> s0_;
	stack<T> s1_;
};

int main() {
	MyQueue<int> q;
	q.push(1);
	q.push(2);
	cout << q.pop() << endl;
	q.push(3);
	q.push(4);
	while (!q.empty())
		cout << q.pop() << endl;
	return 0;
}
