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
// p.second -> height
// p.first -> max ( diameter)
pair<int,int> diameter(TreeNode * root){
    if(!root){
        return {0,0};
    }

    pair<int,int>ans;

    pair<int,int> lp = diameter(root->left);
    pair<int,int> rp = diameter(root->right);
    
    ans.second = max(lp.second,rp.second)+1;
    ans.first = max({lp.first, rp.first, lp.second + rp.second});
    return ans;
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};
