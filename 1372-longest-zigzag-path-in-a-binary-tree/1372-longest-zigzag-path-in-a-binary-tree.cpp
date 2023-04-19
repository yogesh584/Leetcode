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
    int solve(TreeNode* root,bool direction,int& ans){
        if(root == NULL){
            return 0;
        }

        int leftAns = solve(root->left,0,ans);
        int rightAns = solve(root->right,1,ans);
        ans = max(ans,max(leftAns,rightAns));

        if(direction){
            return leftAns+1;
        }
        return rightAns+1;
    }

    int longestZigZag(TreeNode* root) {
        int ans = 0;
        solve(root,0,ans);
        return ans;
    }
};