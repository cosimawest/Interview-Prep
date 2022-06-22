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
    int max_sum=INT_MIN;
    
    int max_gain(TreeNode* root) {
        if(!root)return 0;
        
        // get value of left and right node, disregarding zeros
        // we disregard zeros because along with wanting to use the max between left and right,
        // we also want to check this current set of three nodes to see if it beats the current max
        int l=max(max_gain(root->left),0);
        int r=max(max_gain(root->right),0);
        
        // checking if current three nodes beat current max
        int new_price=root->val+l+r;
        max_sum=max(max_sum,new_price);
        
        // return to the parent node, it's current value plus the max between left and right side
        // we only want one side, since after checking the partnet plus it's two children,
        // we need to move upwards, meaning only one side of the branch can stay
        return root->val+max(l,r);
    }
    
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
};
