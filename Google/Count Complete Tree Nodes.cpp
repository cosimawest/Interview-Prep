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
    
    // hint a full balanced binary tree has (2^h – 1) nodes where h is height
    
    int countNodes(TreeNode* root) {
        int lh = 0, rh = 0;
        
        TreeNode *l = root, *r = root;
        
        while(l) {
            l = l->left;
            lh++;
        }
        
        while(r) {
            r = r->right;
            rh++;
        }
        
        if(lh == rh) return pow(2,lh)-1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
