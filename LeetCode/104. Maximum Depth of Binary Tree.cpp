	/**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	 * };
	 */
	 
	 /*1. 只有根节点，自然是1；
	 2. 如果只有根节点和左子树，那么树的深度为为左子树的深度+1，如果只有根节点和右子树，那么树的深度为右子树的深度+1。
     3. 左右子树都有，取左右子树中深度较大者。*/
	class Solution {
	public:
	    int maxDepth(TreeNode* root) {
	    if(root==nullptr)
	        return 0;
	        int leftDepth = maxDepth(root->left);
	        int rightDepth = maxDepth(root->right);
	        return leftDepth > rightDepth ? (leftDepth+1): (rightDepth+1);
	        
	    }
	};