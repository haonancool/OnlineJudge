struct Node {
	int key;
	int val;
	Node *pre;
	Node *next;
	Node(int k, int v) : key(k), val(v), pre(NULL), next(NULL) {}
};

class LRUCache {
public:
	LRUCache(int capacity) 
		: size_(0), capacity_(capacity),
		  head_(NULL), tail_(NULL) {
	}

	int get(int key) {
		if (table_.find(key) == table_.end())
			return -1;
		move(table_[key]);
		return table_[key]->val;
	}

	void set(int key, int value) {
		if (table_.find(key) != table_.end()) {
			table_[key]->val = value;
			move(table_[key]);
		} else {
			if (size_ == capacity_) {
				table_.erase(tail_->key);
				tail_->key = key;
				tail_->val = value;
				table_[key] = tail_;
				move(tail_);
			} else {
				Node *p = new Node(key, value);
				table_[key] = p;
				size_++;
				move(p);
			}
		}
	}

private:
	void move(Node *p) {
		if (!head_) {
			head_ = tail_ = p;
			return;
		}
		if (head_ == p)
			return;
		if (tail_ == p)
			tail_ = p->pre;
		if (p->pre) p->pre->next = p->next;
		if (p->next) p->next->pre = p->pre;
		head_->pre = p;
		p->pre = NULL;
		p->next = head_;
		head_ = p;
	}

	unordered_map<int, Node*> table_;
	int size_;
	int capacity_;
	Node *head_;
	Node *tail_;
};
