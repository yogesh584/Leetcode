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
    bool solve(TreeNode* root,bool presentNode[],int rootNumber){
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            TreeNode* front = q.front().first;
            int nodeNumber = q.front().second;
    
            q.pop();

            if(presentNode[nodeNumber - 1] == false)    return false;
            presentNode[nodeNumber] = true;

            if(front->left)
                q.push({front->left,nodeNumber*2});
            
            if(front->right)
                q.push({front->right,nodeNumber*2+1});
        }

        return true;
    }

    bool isCompleteTree(TreeNode* root) {
        bool presentNode[1001] = {0};
        presentNode[0] = true;
        return solve(root,presentNode,1);
    }
};