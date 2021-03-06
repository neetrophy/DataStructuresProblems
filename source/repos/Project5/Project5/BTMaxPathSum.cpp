﻿/*Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int PathSum(TreeNode* node, int & maxpsum) {
		if (node == NULL)
			return 0;
		int left = 0, right = 0;
		if (node->left)  left = PathSum(node->left, maxpsum);
		if (node->right) right = PathSum(node->right, maxpsum);

		int value = max(node->val, node->val + max(left, right));
		maxpsum = max(maxpsum, max(node->val + left + right, value));
		return value;
	}
	int maxPathSum(TreeNode* root) {
		if (root == NULL)
			return 0;
		int maxpsum = INT_MIN;
		PathSum(root, maxpsum);
		return maxpsum;
	}
};