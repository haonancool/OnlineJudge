#include <iostream>

using namespace std;

int dist = 0;

void maxDistance(Node *root) {
	helper(root);
	return dist;
}

// return the length of longest path from root to a leaf node
int helper(Node *root) {
	int left = 0, right = 0;
	if (root->left)
		left = helper(root->left);
	if (root->right)
		right = helper(root->right);
	// update the maximum distance between two leaves
	if (left && right && left + right > dist)
		dist = left + right;
	return std::max(left, right);
}
