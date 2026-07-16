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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rootVal = root->val;
        int maxi = max(p->val, q->val);
        int mini = min(q->val, p->val);
        if(rootVal >= mini && rootVal <= maxi) return root;
        else if(rootVal > maxi) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
};
