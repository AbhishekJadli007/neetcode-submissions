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
private:
pair<bool,int> check(TreeNode * root){
    if(!root) {
        return {true,0};
    }

    pair<bool,int>ans;

    pair<bool,int>lp = check(root->left);
    pair<bool,int>rp = check(root->right);

    if(abs(lp.second-rp.second)>1) {
        ans.first = false;
        ans.second = 0 ; 
        return ans;
    }
    ans.second = max(lp.second,rp.second)+1;
    ans.first = lp.first  && rp.first;
    
    return ans;

}
public:
    bool isBalanced(TreeNode* root) {
        return check(root).first;
    }
};
