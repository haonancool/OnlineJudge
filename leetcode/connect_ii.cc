class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
        	return;
        if (root->left) {
        	if (root->right) {
        		root->left->next = root->right;
        	} else {
        		TreeLinkNode *p = root->next;
        		while (p && !p->left && !p->right)
        			p = p->next;
        		if (p && p->left)
        			root->left->next = p->left;
        		else if (p && p->right)
        			root->left->next = p->right;
        		else
        			root->left->next = 0;
        	}
        }
        if (root->right) {
    		TreeLinkNode *p = root->next;
    		while (p && !p->left && !p->right)
    			p = p->next;
    		if (p && p->left)
    			root->right->next = p->left;
    		else if (p && p->right)
    			root->right->next = p->right;
    		else
    			root->right->next = 0;
        }
        connect(root->right);
        connect(root->left);
    }
};