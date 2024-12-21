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
    void  solve(TreeNode* L,TreeNode* R,int lvl){
        if(!L || !R)return;
        if(lvl%2==1){
            int temp=L->val;
            L->val=R->val;
            R->val=temp;
        }
        solve(L->left,R->right,lvl+1);
        solve(L->right,R->left,lvl+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level=1;
        solve(root->left,root->right,level);
        return root;
    }
};