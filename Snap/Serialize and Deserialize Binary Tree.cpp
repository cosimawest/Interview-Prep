/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") return NULL;
        stringstream s(data); // makes reading a string to a point easier
        return deserialize(s);
    }
    
    TreeNode* deserialize(stringstream& data) {
        string temp;
        
        // below reads up to ',' then puts that into temp, discarding it from data
        // also discards the ',' delimiter... convient huh?
        getline(data, temp, ','); 
        
        if(temp == "#") return NULL;
        else {
            TreeNode *node = new TreeNode(stoi(temp));
            node->left = deserialize(data);
            node->right = deserialize(data);
            return node;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
