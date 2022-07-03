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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        // get longest path to the right and left
        // add both (as long as one isn't negative) plus current and compare to max
        // replace curr val with that number
        getMaxPathSum(root);
        
        return res;
    }
    
    int getMaxPathSum(TreeNode* root) {
        if(!root) return 0;
        // return 0 if null
        
        // left int equals maxPathSum left or 0
        // right int equals maxPathSum right or 0
        int l = max(getMaxPathSum(root->left), 0);
        int r = max(getMaxPathSum(root->right), 0);
        
        // add left right and curr and compare to res
        res = max(res, l + r + root->val);
        
        // return max of left and right plus itself (curr will either increase or stay the same)
        return max(l,r) + root->val;
    }
};
